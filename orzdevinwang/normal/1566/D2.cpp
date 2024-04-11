#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
using namespace std;
const int M = 1e3 + 7, N = 1e5, mod = 998244353;
int n, m, a[N], f[M][M], arr[N], tp, lh[N];
int sz[N];
void add (int x, int w) {
	for(; x <= n * m; x += x & -x) sz[x] += w;
}
int query (int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += sz[x];
	return ret;
}
int hd[N];
int geth (int x) { return (x - 1) / m + 1; }
int getl (int x) { return (x - 1) % m + 1; }
void Main () {
	tp = 0;
	ll ns = 0;
	cin >> n >> m;
	L(i, 1, n * m) cin >> a[i], arr[++tp] = a[i] ;
	sort(arr + 1, arr + tp + 1);
	tp = unique(arr + 1, arr + tp + 1) - arr - 1;
	L(i, 1, n * m) a[i] = lower_bound(arr + 1, arr + tp + 1, a[i]) - arr, hd[a[i]] += 1;
	L(i, 1, tp) hd[i] += hd[i - 1];
	R(i, n * m, 1) {
		int id = hd[a[i]]--;
		f[geth(id)][getl(id)] = i;
	}
	L(i, 1, n) { 
		int cnt = 0;
		L(j, 1, m) {
			add (f[i][j], 1), ns += query (f[i][j] - 1) - cnt;	
			if(a[f[i][j]] == a[f[i][j + 1]]) cnt += 1;
			else cnt = 0;
		}
		L(j, 1, m) add (f[i][j], -1);
	}
	cout << ns << "\n";
	L(i, 1, tp) hd[i] = 0;
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}