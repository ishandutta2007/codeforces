#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 4e5 + 5;
map <pair <char, char>, int> id;
pair <char, char> c[N];
int n, m, d[N], stk[N], tp;
char s[4];
vector <int> G[N];
void dfs(int u) {
	while(!G[u].empty()) {
		int v = G[u].back();
		G[u].pop_back(), dfs(v);
	}
	stk[++tp] = u;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) {
		scanf("%s", s);
		int a = id[{s[0], s[1]}];
		if(!a) c[a = id[{s[0], s[1]}] = ++m] = {s[0], s[1]};
		int b = id[{s[1], s[2]}];
		if(!b) c[b = id[{s[1], s[2]}] = ++m] = {s[1], s[2]};
		G[a].pb(b), d[a]++, d[b]--;
	}
	int s = 0, t = 0;
	rep(i, 1, m) {
		if(d[i] == 1) { if(s) puts("NO"), exit(0); s = i; }
		if(d[i] == -1) { if(t) puts("NO"), exit(0); t = i; }
		if(abs(d[i]) > 1) puts("NO"), exit(0);
	}
	if((s || t) && (!s || !t)) puts("NO"), exit(0);
	dfs(s ? s : 1);
	if(tp <= n) puts("NO"), exit(0);
	puts("YES");
	putchar(c[stk[tp]].first), putchar(c[stk[tp]].second);
	while(--tp) putchar(c[stk[tp]].second);
	return 0;
}