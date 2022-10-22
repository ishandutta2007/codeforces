#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define upd(a, b) a = max(a, b)

using namespace std;
const int N = 100005;
int n, a[7], b[N][7], g[N*6];
struct node {
	int i, j, v;
	node(int i, int j) :i(i), j(j) { v = b[i][j]; }
	bool operator <(const node& o)const { return v > o.v; }
}; priority_queue <node> q;
int main() {
	rep(i, 1, 6) cin >> a[i];
	cin >> n;
	rep(i, 1, n) {
		scanf("%d", &b[i][0]);
		rep(j, 1, 6) g[(i-1)*6+j] = b[i][j] = b[i][0] - a[j];
		sort(b[i] + 1, b[i] + 7);
	}
	sort(g + 1, g + n * 6 + 1);
	int Max = - 1e9, ans = 1e9;
	rep(i, 1, n) q.push(node(i, 1)), upd(Max, b[i][1]);
	rep(i, 1, n * 6) {
		while(q.top().v < g[i]) {
			node t = q.top(); q.pop();
			if(t.j < 6) q.push(node(t.i, t.j + 1)), upd(Max, b[t.i][t.j+1]);
			else return cout << ans, 0;
		}
		ans = min(ans, Max - g[i]);
	}
	return cout << ans, 0;
}