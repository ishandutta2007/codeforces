#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
         
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = (1 << 20) + 3;

int n;
int a[max_n], b[max_n];
vector<pii> gr[max_n];
vector<pii> path;
bool used[max_n];

void euler(int v) {
	while(sz(gr[v])) {
		pii to = gr[v].back();
		gr[v].pop_back();
		if (used[to.se / 2]) continue;
		used[to.se / 2] = true;
		euler(to.fi);
		path.emplace_back(v, to.fi);
	}
}


bool f(int k) {
	path.clear();
	for(int i = 0;i < (1 << k);i++) 
		gr[i].clear();
	fill(used, used + n, false);

	for(int i = 0;i < n;i++) {
		int v1 = a[i] & ((1 << k) - 1), v2 = b[i] & ((1 << k) - 1);
		gr[v1].emplace_back(v2, i * 2);
		gr[v2].emplace_back(v1, i * 2 + 1);
	}

	for(int i = 0;i < (1 << k);i++) {
		if (sz(gr[i]) & 1) return false;
	}

	for(int st = 0;st < (1 << k);st++) {
		if (sz(gr[st])) {
			euler(st);
			reverse(all(path));

			if (sz(path) != n) return false;
			break;
		}
	}
	return true;
}

void solve() {
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i] >> b[i];

	vector<pii> p;
	int k = -1, r = 21;
	while(k + 1 < r) {
		int mid = (k + r) / 2;
		if (!f(mid)) r = mid;
		else {
			k = mid;
			p = path;
		}
	}
	
	map<pii, set<int>> er;
	for(int i = 0;i < n;i++) {
		int v1 = a[i] % (1 << k), v2 = b[i] % (1 << k);
		er[mp(v1, v2)].emplace(i);
		er[mp(v2, v1)].emplace(i);
	}
	vector<int> res;
 
	for(auto i : p) {
		int t = *er[i].begin();
		er[i].erase(er[i].begin());
		er[mp(i.se, i.fi)].erase(t);
		if (i.fi == a[t] % (1 << k)) res.emplace_back(t * 2), res.emplace_back(t * 2 + 1);
		else res.emplace_back(t * 2 + 1), res.emplace_back(t * 2);
	}
 
 
	cout << k << endl;
 
	for(int i : res)
		cout << i + 1 << " ";
	cout << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}