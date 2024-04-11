#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
int n, K, a[N], L[N], R[N], su[N];
vector <int> v[1000000];
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K;
	rep(i, 1, n) scanf("%d", &a[i]);
	v[0].pb(0);
	rep(i, 1, n) su[i] = (su[i - 1] + a[i]) % K, v[su[i]].pb(i);
	rep(i, 1, n) for(int& j = L[i] = i - 1; j && a[j] <= a[i]; j = L[j]);
	per(i, n, 1) for(int& j = R[i] = i + 1; j <= n && a[j] < a[i]; j = R[j]);
	long long as = 0;
	rep(i, 1, n) if(i - L[i] < R[i] - i) For(j, L[i], i) {
		int t = (su[j] + a[i]) % K;
		#define lb lower_bound
		#define all v[t].begin(), v[t].end()
		as += lb(all, R[i]) - lb(all, i);
	} else For(j, i, R[i]) {
		int t = ((su[j] - a[i]) % K + K) % K;
		as += lb(all, i) - lb(all, L[i]);
	}
	cout << as - n;	
	return 0;
}