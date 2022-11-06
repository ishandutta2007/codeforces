#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=100005;
int n;
vector<int> G[Maxn];
int c[2];
int Mx;
void dfs(int x,int p,int d){
	if (G[x].size()==1) c[d]=1;
	int cs=0;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (v!=p){
			if (G[v].size()==1) cs++;
			dfs(v,x,d^1);
		}
	}
	if (cs>0) Mx-=cs-1;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}
	int rt;
	for (int i=1;i<=n;i++){
		if (G[i].size()!=1) rt=i;
	}
	Mx=n-1;
	dfs(rt,-1,0);
	int Mn;
	if(c[0] && c[1]) Mn=3;
	else Mn=1;
	printf("%d %d\n",Mn,Mx);
	return 0;
}