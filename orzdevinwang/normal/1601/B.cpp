#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, a[N], b[N], dp[N], lst[N];
vi e[N];
int f[N];
int find (int x) {
	return  f[x] == x ? x : f[x] = find (f[x]);
}
int arr[N], atot;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i];
	L(i, 1, n) f[i] = i;
	queue < int > q;
	q.push (n), dp[n] = 0, f[n] = n - 1;
	while (!q.empty()) {
		int u = q.front (), z = u + b[u];
		q.pop();
		for (int t = find (z); t >= z - a[z]; t = find (t - 1)) {
			q.push (t);
			dp[t] = dp[u] + 1;
			lst[t] = u;
			if(t == 0) {
				int r = t;
				while (r != n) arr[++atot] = r, r = lst[r];
				cout << dp[t] << '\n';
				R(i, atot, 1) cout << arr[i] << ' ';
				cout << '\n';
				return 0;
			}
			f[t] = find (t - 1);
		}
	}
	cout << -1 << '\n';
	return 0;
}