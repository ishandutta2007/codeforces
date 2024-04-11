#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int T, n, rt, D[N], fa[N], dis, DDD, A, B;
vector<int> e[N];
vector<int> ve[N];
bool check(int x) {
	printf("? %d ", (int)ve[x].size());
	L(i, 0, (int)ve[x].size() - 1) printf("%d ", ve[x][i]);
	printf("\n");
	fflush(stdout);
	scanf("%d%d", &B, &A);
	return A == dis;
}
void dfs(int x) {
	ve[D[x]].push_back(x), DDD = max(DDD, D[x]);
	for(int v : e[x]) if(v ^ fa[x]) D[v] = D[x] + 1, fa[v] = x, dfs(v);
}
char s[N];
bool flag[N];
void Main() {
	DDD = 0;
	scanf("%d", &n);
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		e[u].push_back(v), e[v].push_back(u);
	}
	printf("? %d ", n);
	L(i, 1, n) printf("%d ", i); printf("\n"); fflush(stdout);
	scanf("%d%d", &rt, &dis);
	D[rt] = 0, fa[rt] = -1, dfs(rt);
	int l = (dis + 1) / 2, r = min(dis, DDD), ans, ansv = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) ans = mid, ansv = B, l = mid + 1;
		else r = mid - 1;
	}
	for(int t = ansv; t != rt; t = fa[t]) flag[t] = 1;
	if(ansv == -1) assert(0);
	// len = ans, va = ansv;
	printf("? %d ", (int)ve[dis - ans].size() - (dis != ans));  
	L(i, 0, (int)ve[dis - ans].size() - 1) if(!flag[ve[dis - ans][i]]) printf("%d ", ve[dis - ans][i]); printf("\n");
	fflush(stdout);
	scanf("%d%d", &B, &A);
	if(A != dis) assert(0);
	printf("! %d %d\n", B, ansv);
	fflush(stdout);
	scanf("%s", s + 1);
	assert(s[1] == 'C');
	L(i, 0, n) e[i].clear(), ve[i].clear(), flag[i] = 0;
}
int main() {
	scanf("%d", &T);
	while(T--) Main();
	return 0;
}