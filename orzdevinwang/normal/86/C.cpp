#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1007;
const int M = 114;
const int mod = 1e9 + 9;
int n, m;
int ch[M][4], fa[M], len[N], tot = 1;
void bfs() {
	queue<int> q;
	L(i, 0, 3) if(ch[1][i]) q.push(ch[1][i]), fa[ch[1][i]] = 1; else ch[1][i] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		len[u] = max(len[u], len[fa[u]]);
		L(i, 0, 3) {
			int v = ch[u][i];
			if(v) fa[v] = ch[fa[u]][i], q.push(v);
			else ch[u][i] = ch[fa[u]][i];
		}
	}
}
int dp[N][M][12];
char s[114];
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		scanf("%s", s + 1); int Len = strlen(s + 1);
		int now = 1;
		L(j, 1, Len) {
			int opt = (s[j] > 'A') + (s[j] > 'G') + (s[j] > 'C') + (s[j] > 'T');
			if(!ch[now][opt]) ch[now][opt] = ++tot;
			now = ch[now][opt];
		}
		len[now] = max(len[now], Len);
	}
	bfs();
	dp[0][1][0] = 1;
	L(i, 1, n) L(j, 1, tot) L(k, 0, 10) L(t, 0, 3) {
		if(len[ch[j][t]] >= k + 1) (dp[i][ch[j][t]][0] += dp[i - 1][j][k]) %= mod;
		else (dp[i][ch[j][t]][k + 1] += dp[i - 1][j][k]) %= mod; 
	}
	int ans = 0;
	L(i, 1, tot) (ans += dp[n][i][0]) %= mod;
	printf("%d\n", ans);
	return 0;
}
/*
5 5
ATTATGAACC
TTA
TCAG
CCGAGG
T
*/