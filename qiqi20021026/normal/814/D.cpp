#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define pi (double)3.14159265358979
#define LL long long

LL n,xb,ans,cnt;
LL g[2][2],x[1030],y[1030],r[1030],fa[1030],tail[1030];
LL f[1030][2][2];
struct edge{
	int last,v;
}e[1030];

LL dis(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

void add(int x,int y){
	cnt++;
	e[cnt].v=y;
	e[cnt].last=tail[x];
	tail[x]=cnt;
}

void dp(int x){
	LL g[2][2]={{0}};
	for (int i=tail[x];i;i=e[i].last){
		dp(e[i].v);
		for (int j=0;j<=1;j++)
			for (int k=0;k<=1;k++)
				g[j][k]+=f[e[i].v][j][k];
	}
	
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)
			f[x][i][j]=max(
				g[i^1][j]+(LL)r[x]*r[x]*(i==1?+1:-1),
				g[i][j^1]+(LL)r[x]*r[x]*(j==1?+1:-1)
			);
}

int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i],&y[i],&r[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			if (r[i]<r[j] && dis(i,j)<r[j]*r[j])
				if (fa[i]==0 || r[fa[i]]>r[j])
					fa[i]=j;
		if (fa[i]!=0) add(fa[i],i);
	}
	
	for (int i=1;i<=n;i++)
		if (fa[i]==0){
			dp(i);
			ans+=f[i][1][1];
		}
	
	printf("%.8f\n",ans*pi);
}