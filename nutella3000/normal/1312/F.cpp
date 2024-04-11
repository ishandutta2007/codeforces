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
//#define fi first
//#define se second
//#define all(_v) _v.begin(), _v.end()
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = 1e5 + 3, K = 5;

int n, x, y, z;
map<vector<vector<int>>, int> d;
int cnt, p;
vector<vector<int>> state_log;

int mex(vector<int> a) {
	sort(a.begin(), a.end());
	int r = 0;
	for(int i : a) {
		if (i > r) return r;
		if (i == r) r++;
	}
	return r;
}

void go(vector<vector<int>>& cur) {
	int f1 = mex({cur[0][K - x], cur[1][K - y], cur[2][K - z]});
	int f2 = mex({cur[0][K - x], cur[2][K - z]});
	int f3 = mex({cur[0][K - x], cur[1][K - y]});
	for(int i = 0;i < 3;i++)
		cur[i].erase(cur[i].begin());

	cur[0].emplace_back(f1), cur[1].emplace_back(f2), cur[2].emplace_back(f3);
}

void prec() {
	vector<vector<int>> cur(3, vector<int>(K));
	state_log.clear();
	cnt = p = 0;
	d.clear();
	while(!d.count(cur)) {
		state_log.push_back({cur[0].back(), cur[1].back(), cur[2].back()});
		d[cur] = cnt;
		cnt++;
		go(cur);
	}
	p = cnt - d[cur];
}

int f(int a, int t) {
	if (a < cnt) return state_log[a][t];
	else {
		a -= (cnt - p);
		return state_log[a % p + (cnt - p)][t];
	}
}

void solve() {
	cin >> n >> x >> y >> z;
	prec();

	int res = 0, num = 0;
	
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		num ^= f(a[i], 0);
	}

	for(int i = 0;i < n;i++) {
		num ^= f(a[i], 0);
		res += f(max(0ll, a[i] - x), 0) == num;
		res += f(max(0ll, a[i] - y), 1) == num;
		res += f(max(0ll, a[i] - z), 2) == num;
		num ^= f(a[i], 0);
	}

	cout << res << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) solve();
}