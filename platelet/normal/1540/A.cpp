#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int T, n, d[N];
void solve() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &d[i]);
	sort(d + 1, d + n + 1);
	ll su = 0, as = d[n];
	rep(i, 1, n) as -= d[i] * (i - 1ll) - su, su += d[i];
	printf("%lld\n", as);
}
int main() {
	int T; for(cin >> T; T--; solve());
}