#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;

int main() {
	int t, p, f, cnts, cntw, s, w;
	for(cin >> t; t--;) {
		scanf("%d%d%d%d%d%d", &p, &f, &cnts, &cntw, &s, &w);
		if(s > w) swap(cnts, cntw), swap(s, w);
		int ans = 0;
		per(i, min(cnts, p / s), 0) {
			int t1 = min((p - i * s) / w, cntw);
			int t2 = min(f / s, cnts - i);
			ans = max(ans, i + t1 + t2 + min((f - t2 * s) / w, cntw - t1));
		}
		printf("%d\n", ans);
	}
	return 0;
}