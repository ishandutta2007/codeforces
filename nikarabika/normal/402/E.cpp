//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2000;
vector<int> stc;
int a[maxn][maxn],
	n;
bool mark[maxn];

void dfs1(int v){
	mark[v] = true;
	for(int u = 0; u < n; u++)
		if(!mark[u] and a[v][u])
			dfs1(u);
	stc.PB(v);
	return;
}

void dfs2(int v){
	mark[v] = true;
	for(int u = 0; u < n; u++)
		if(!mark[u] and a[u][v])
			dfs2(u);
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", a[i] + j);
	dfs1(0);
	for(int i = 0; i < n; i++)
		if(!mark[i]){
			printf("NO\n");
			return 0;
		}
	memset(mark, false, sizeof mark);
	dfs2(stc.back());
	for(auto v : stc)
		if(!mark[v]){
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}