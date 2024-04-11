#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	int T, n;
	for(cin >> T; T--;) {
		vector <int> a, b;
		cin >> n;
		int x, y;
		rep(i, 1, n * 2) {
			scanf("%d%d", &x, &y);
			if(x == 0) a.push_back(abs(y));
			else b.push_back(abs(x));
		}
		sort(a.begin(), a.end()), sort(b.begin(), b.end());
		double ans = 0;
		rep(i, 0, n - 1) ans += sqrt(1.0 * a[i] * a[i] + 1.0 * b[i] * b[i]);
		printf("%.10lf\n", ans);
	}
	return 0;
}