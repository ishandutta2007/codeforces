#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 1e4 + 5;
typedef long long ll;
int n, A[N], B[N];
ll pre[N], suf[N]; 
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &A[i * 2]);
	rep(i, 1, n) scanf("%d", &B[i * 2]);
	n *= 2;
	rep(i, 1, n) pre[i] = pre[i - 1] + (ll)A[i] * B[i];
	per(i, n, 1) suf[i] = suf[i + 1] + (ll)A[i] * B[i];
	ll as = pre[n];
	rep(i, 1, n * 2) {
		ll su = (ll)A[i] * B[i];
		rep(j, 1, min(i - 1, n - i)) {
			su += (ll)A[i - j] * B[i + j] + (ll)A[i + j] * B[i - j];
			as = max(as, su + pre[i - j - 1] + suf[i + j + 1]);
		}
	}
	cout << as;
	return 0;
}