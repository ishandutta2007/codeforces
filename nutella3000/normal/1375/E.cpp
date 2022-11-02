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
const int max_n = 1e3 + 3;

int n;
int a[max_n], pos[max_n];

void scan() {
	cin >> n;
	map<int, vector<int>> b;
	for(int i = 0;i < n;i++) {
		int v;
		cin >> v;
		b[v].emplace_back(i);
	}
	int c = 0;
	for(auto i1 : b) {
		for(auto i2 : i1.se)
			a[i2] = c++;
	}

	for(int i = 0;i < n;i++)
		pos[a[i]] = i;
}


vector<pii> res;

void repl(int i, int j) {
	pos[a[i]] = j;
	pos[a[j]] = i;
	swap(a[i], a[j]);
	res.emplace_back(i, j);
}

void solve() {
	scan();

	for(int i = n - 1;i >= 0;i--) {
		for(int j = a[i] + 1;j <= i;j++) {
			repl(i, pos[j]);
		}
	}
	cout << sz(res) << endl;
	for(auto i : res)
		cout << i.se + 1 << " " << i.fi + 1 << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}