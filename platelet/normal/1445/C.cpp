#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b)

using namespace std;
int T, q; long long p, ans, res;
int main() {
	#ifdef local
//		freopen("1.in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		cin >> p >> q;
		if(p % q) cout << p << endl;
		else {
			ans = 0; int qq = q;
			for(int i = 2; i * i <= qq; i++) if(qq % i == 0) {
				res = 1;
				while((p / res) % q == 0) res *= i;
				while(qq % i == 0) qq /= i;
				ans = max(ans, p / res);
			}
			if(qq > 1) {
				res = 1;
				while((p / res) % q == 0) res *= qq;
				ans = max(ans, p / res);
			}
			cout << ans << endl;
		}
	}
	return 0;
}