#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define pb push_back

using namespace std;

const int N = 1e5 + 5;
typedef pair <int, int> P;

int T, n, m, x, a[N], as[N];

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d%d", &n, &m, &x);
		priority_queue <P, vector <P>, greater <P>> q;
		rep(i, 1, m) q.emplace(0, i);
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			P sj = q.top(); q.pop();
			int s = sj.first, j = sj.second;
			as[i] = j, q.emplace(s + a[i], j);
		}
		int mi = q.top().first;
		rep(i, 2, m) q.pop();
		if(q.top().first > mi + x) puts("NO");
		else {
			puts("YES");
			rep(i, 1, n) printf("%d ", as[i]);
			puts("");
		}
	}
	return 0;
}