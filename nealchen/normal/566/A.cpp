#include <cstdio>
const int N = 1e5+1, M = 8e5+1;
int n, next[2][N], head[2][M], tail[2][M], go[M][26], ans[N], tot = 0;
long long answer;
char s[M + 1];
int trie(char *p) {
	int i = 0;
	for(; *p; ++p) {
		if(!go[i][*p-'a']) go[i][*p-'a'] = ++tot;
		i = go[i][*p-'a'];
	}
	return i;
}
void cat(int k, int u, int v) {
	if(!head[k][v]) return;
	if(!head[k][u]) {
		head[k][u] = head[k][v], tail[k][u] = tail[k][v];
		return;
	}
	if(head[k][u]) next[k][tail[k][u]] = head[k][v];
	head[k][v] = tail[k][v], tail[k][u] = tail[k][v];
}
void dfs(int o, int dep)
{
	int i, j;
	for(i = 0; i < 26; ++i) {
		if(j = go[o][i]) {
			dfs(j, dep+1);
			cat(0, o, j);
			cat(1, o, j);
		}
	}
	i = head[0][o];
	j = head[1][o];
	while (i != 0 && j != 0) {
		ans[i] = j;
		answer += dep;
		i = next[0][i];
		j = next[1][j];
	}
	head[0][o] = i;
	head[1][o] = j;
}
int main()
{
	scanf("%d\n", &n);
	for (int k = 0; k < 2; ++k) {
		for (int i = 1; i <= n; ++i) {
			scanf("%[^\n]\n", s);
			int j = trie(s);
			if (!head[k][j]) {
				head[k][j] = tail[k][j] = i;
			}
			else {
				next[k][tail[k][j]] = i;
				tail[k][j] = i;
			}
		}
	}
	dfs(0, 0);
	printf("%lld\n", answer);
	for (int i = 1; i <= n; ++i) {
		printf("%d %d\n", i, ans[i]);
	}
	return 0;
}