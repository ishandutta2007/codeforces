#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void GG() {
	printf("IMPOSSIBLE\n") , exit(0);
}

const int N = 1e5 + 10;

int t , T;
int n , m , l[N] , r[N];
vector <int> G[N];
int col[N];

void dfs(int x) {
	for(auto i : G[x]) {
		if(!col[i])
			col[i] = col[x] ^ 1 , dfs(i);
		else if(col[i] == col[x])
			GG();
	}
}

int main() {
	scanf("%d%d%d%d" , &t , &T , &n , &m);
	for(int i = 1; i <= n; i++) scanf("%d%d" , &l[i] , &r[i]);
	for(int i = 1 , u , v; i <= m; i++) {
		scanf("%d%d" , &u , &v);
		G[u].push_back(v) , G[v].push_back(u);
	}
	int Min = 0x3f3f3f3f , Max = 0;
	for(int i = 1; i <= n; i++)	
		Min = min(Min , r[i]) , Max = max(Max , l[i]);
	if(Min + Max > T) Min = T - Max;
	if(Min + Max < t) Max = t - Min;
	if(Min < 0 || Max < 0) GG();
	for(int i = 1; i <= n; i++)
	{
		if(!((l[i] <= Min && Min <= r[i]) || (l[i] <= Max && Max <= r[i])))
			GG();
		if((l[i] <= Min && Min <= r[i]) && (l[i] <= Max && Max <= r[i]))
			continue;
		if(l[i] <= Min && Min <= r[i])
			col[i] = 2;
		else
			col[i] = 3;
	}
	for(int i = 1; i <= n; i++)
		if(col[i]) dfs(i);
	for(int i = 1; i <= n; i++)
		if(!col[i])
			col[i] = 2 , dfs(i);
	printf("POSSIBLE\n%d %d\n" , Min , Max);
	for(int i = 1; i <= n; i++)
		printf("%d" , col[i] - 1);
	printf("\n");
	return 0;
}