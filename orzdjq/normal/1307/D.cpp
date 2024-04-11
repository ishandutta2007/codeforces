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
const int Maxn=200005;
int n,m,k;
int a[Maxn],distA[Maxn],distB[Maxn],q[Maxn],sq,eq;
vector<int> G[Maxn];
bool cmp(int x,int y){
	return distA[x]<distA[y];
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=k;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}	
	q[eq++]=1;
	for (int i=1;i<=n;i++) distA[i]=distB[i]=-1;
	distA[1]=0;
	while (sq<eq){
		int x=q[sq++];
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i];
			if (distA[v]==-1){
				distA[v]=distA[x]+1;
				q[eq++]=v;
			}
		}
	}
	sq=eq=0;
	distB[n]=0;
	q[eq++]=n;
	while (sq<eq){
		int x=q[sq++];
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i];
			if (distB[v]==-1){
				distB[v]=distB[x]+1;
				q[eq++]=v;
			}
		}
	}
	sort(a+1,a+1+k,cmp);
	for (int i=1;i<k;i++){
		if (distA[a[i]]==distA[a[i+1]]){
			printf("%d\n",distA[n]);
			return 0;
		}
	}
	int Mx=0;
	for (int i=1;i<k;i++){
		Mx=max(Mx,distA[a[i]]+1+distB[a[i+1]]);
	}
	Mx=min(Mx,distA[n]);
	printf("%d\n",Mx);
	return 0;
}