#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int N, Q; vector<int> con[101010];

int dep[101010], anc[101010][18];

int lca(int a, int b)
{
	if(dep[a] < dep[b]) swap(a,b);
	for(int i=17; i>=0; i--)
	{
		if(dep[a]-dep[b] >= (1<<i)) a = anc[a][i];
	}
	if(a == b) return a;
	for(int i=17; i>=0; i--)
	{
		if(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
	}
	return anc[a][0];
}

int dist(int a, int b){
	int m = lca(a, b);
	return dep[a]+dep[b]-2*dep[m];
}

void dfs(int ix)
{
	for(int i=0;i<con[ix].size();i++)
	{
		int e=con[ix][i];
		if(e == anc[ix][0]) continue;
		anc[e][0] = ix; dep[e] = dep[ix]+1;
		dfs(e);
	}
}

int main(){
	scanf("%d%d", &N, &Q);
	for(int i=2; i<=N; i++){
		int e;
		scanf("%d", &e);
		con[i].push_back(e);
		con[e].push_back(i);
	}
	anc[1][0] = 0; dfs(1);
	for(int i=1; i<18; i++)
	{
		for(int j=1; j<=N; j++) anc[j][i] = anc[anc[j][i-1]][i-1];
	}
	for(int i=Q;i>=1;i--)
	{
		int a, b, c, m1, m2, m3, m;
		scanf("%d%d%d", &a, &b, &c);
		m1 = lca(a,b); m2 = lca(a,c); m3 = lca(b,c);
		if(m1 == m2) m = m3;
		else if(m1 == m3) m = m2;
		else m = m1;
		printf("%d\n", 1+max(max(dist(m,a),dist(m,b)),dist(m,c)));
	}
	return 0;
}