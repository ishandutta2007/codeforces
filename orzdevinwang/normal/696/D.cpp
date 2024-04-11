#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 209;
const ll inf = 1e18;
int tot = 1;
struct Martix {
	ll G[N][N];
	void clear() { L(i, 1, tot) L(j, 1, tot) G[i][j] = -inf; }
	void start() { clear(); L(i, 1, tot) G[i][i] = 0; }
} P;
Martix operator * (Martix aa, Martix bb) {
	Martix res; res.clear();
	L(i, 1, tot) L(j, 1, tot) L(k, 1, tot) res.G[i][j] = max(res.G[i][j], aa.G[i][k] + bb.G[k][j]);
	return res;
}
Martix operator ^ (Martix aa, ll bb)  {
	Martix res; res.start();
	for(; bb; aa = aa * aa, bb >>= 1) if(bb & 1) res = res * aa;
	return res;
}
int n; ll m;
int ch[N][26], fa[N], cnt[N];
void bfs() {
	queue<int> q;
	L(i, 0, 25) if(ch[1][i]) q.push(ch[1][i]), fa[ch[1][i]] = 1; else ch[1][i] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		cnt[u] += cnt[fa[u]];
		L(i, 0, 25) {
			int v = ch[u][i];
			if(v) fa[v] = ch[fa[u]][i], q.push(v);
			else ch[u][i] = ch[fa[u]][i];
		}
	}
}
char s[514];
int V[N];
int main() {
	scanf("%d%lld", &n, &m);
	L(i, 1, n) scanf("%d", &V[i]);
	L(i, 1, n) {
		scanf("%s", s + 1); int Len = strlen(s + 1), now = 1;
		L(j, 1, Len) {
			if(!ch[now][s[j] - 'a']) ch[now][s[j] - 'a'] = ++tot;
			now = ch[now][s[j] - 'a'];
		}
		cnt[now] += V[i];
	}
	bfs();
	P.clear();
	L(i, 1, tot) L(j, 0, 25) P.G[i][ch[i][j]] = cnt[ch[i][j]];
	Martix pp = (P ^ m); ll ans = 0;
	L(i, 1, tot) ans = max(ans, pp.G[1][i]);
	printf("%lld\n", ans);
	return 0;
}