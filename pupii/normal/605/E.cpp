#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
double dist[1010],p[1010][1010],prod[1010];
bool vis[1010];
double Dist(int x){return dist[x]/(1-prod[x]);}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			p[i][j]=gi()*1e-2;
	dist[n]=0;vis[n]=1;
	dist[0]=1e233;for(int i=1;i<n;++i)prod[i]=1-p[i][n],dist[i]=1;
	for(int i=1;i<n;++i){
		int x=0;
		for(int j=1;j<n;++j)if(!vis[j]&&Dist(j)<Dist(x))x=j;
		vis[x]=1;dist[x]=Dist(x);
		for(int j=1;j<=n;++j)if(!vis[j])dist[j]=dist[j]+prod[j]*p[j][x]*dist[x],prod[j]*=1-p[j][x];
	}
	printf("%.10lf\n",dist[1]);
	return 0;
}