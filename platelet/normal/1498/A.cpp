#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
typedef long long ll;
int T; ll n;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int calc(ll x) {
	int res = 0;
	while(x) res += x % 10, x /= 10;
	return res;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%lld", &n);
		ll x = n;
		while(gcd(x, calc(x)) == 1) x++;
		printf("%lld\n", x);
	}
	return 0;
}