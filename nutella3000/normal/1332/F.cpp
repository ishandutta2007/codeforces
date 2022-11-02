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
//#define all(_v) _v.begin(), _v.end()
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int mod = 998244353;
const int max_n = 3e5 + 3;

int n;
vector<int> gr[max_n];
int d[max_n], p[max_n][2];

int mul(int a, int b) {
	return a * b % mod;
}

int sum(int a, int b) {
	int r = a + b;
	if (r >= mod) r -= mod;
	return r;
}

void dfs(int v, int pr = -1) {
	int al = 1, q1 = 1, q2 = 1; 

	for(int to : gr[v]) {
		if (to == pr) continue;
		dfs(to, v);

		al = mul(al, (2 * d[to] + p[to][0] + p[to][1]) % mod);
		q1 = mul(q1, (2 * d[to] + p[to][0]) % mod);
		q2 = mul(q2, sum(d[to], p[to][0]));
	}

	d[v] = al;
	p[v][1] = q1;
	p[v][0] = (p[v][1] - q2 + mod) % mod;
}

void solve() {
	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		gr[--v1].emplace_back(--v2);
		gr[v2].emplace_back(v1);
	}

	dfs(0);
	/*for(int i = 0;i < n;i++) {
		cout << d[i] << " " << p[i][0] << " " << p[i][1] << endl;
	}*/

	cout << (p[0][0] + d[0] - 1 + mod) % mod << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}