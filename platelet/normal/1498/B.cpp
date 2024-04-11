#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int T, n, W;

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &W);
		multiset <int, greater <int>> s;
		int x, as = 0;
		while(n--) scanf("%d", &x), s.insert(x);
		while(!s.empty()) {
			int nw = W;
			while(!s.empty() && *s.rbegin() <= nw) {
				x = *s.lower_bound(nw);
				nw -= x, s.erase(s.find(x));
			}
			as++;
		}
		printf("%d\n", as);
	}
	return 0;
}