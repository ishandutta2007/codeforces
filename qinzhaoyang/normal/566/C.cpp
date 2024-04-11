#include <stdio.h>
#include <bits/stdc++.h>
#define pr pair<int,int>
#define mp(a , b) make_pair((a) , (b))
#define f first
#define s second 
#define pb push_back

using namespace std;

const int N = 2e5 + 10;
int n , w[N];
vector <pr > G[N];

int v[N] , s[N] , rt , ans1;
double d[N] , ans2 = 1e20 , sum;

void find(int x  , int fa , int S) {
	s[x] = 1; int M = 0;
	for(auto i : G[x]) {
		int to = i.f , t = i.s;
		if(to == fa || v[to]) continue;
		find(to , x , S);
		M = max(M , s[to]) , s[x] += s[to];
	}
	M = max(M , S - s[x]);
	if(M <= S / 2) rt = x;
}

void calc(int x , int fa , int wh , int t) {
	sum += pow(t , 1.5) * w[x] , d[wh] += pow(t , 0.5) * 1.5 * w[x];
	for(auto i : G[x]) if(i.f != fa)
		calc(i.f , x , wh , i.s + t);
}

void dfs(int x , int S) {
	if(v[x]) return;
	find(x , 0 , S) , x = rt , find(x , 0 , S);
	v[x] = 1 , sum = 0.0; double sd = 0.0 , M = 0.0; int wh = 0;
	for(auto i : G[x]) {
		int to = i.f;
		d[to] = 0 , calc(to , x , to , i.s) , sd += d[to];
		if(d[to] > M) wh = to , M = d[to];
	}
	if(sum < ans2) ans1 = x , ans2 = sum;
	if(sd - 2 * M < 0) dfs(wh , s[wh]);
}

int main() {
	scanf("%d" , &n);
	for(int i = 1; i <= n; i++) scanf("%d" , &w[i]);
	for(int i = 1; i < n; i++) {
		int u , v , w; scanf("%d%d%d" , &u , &v , &w);
		G[u].pb(mp(v , w)) , G[v].pb(mp(u , w));
	}
	dfs(1 , n);
	printf("%d %.10f\n" , ans1 , ans2);
	return 0;
}