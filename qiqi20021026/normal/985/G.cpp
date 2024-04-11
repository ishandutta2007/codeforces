#include<bits/stdc++.h>

using namespace std;

#define uLL unsigned long long
#define N 220000

int n,m,tot,a[N],b[N],f[N],g[N],head[N],q[N],d[N],vis[N];
uLL A,B,C,ans;
struct edge{int v,nxt;}e[N*2];

void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

int main(){
	scanf("%d%d%llu%llu%llu",&n,&m,&A,&B,&C);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&a[i],&b[i]);
		++d[a[i]]; ++d[b[i]];
		add(a[i],b[i]); add(b[i],a[i]);
		if (a[i]<b[i]){++f[a[i]]; ++g[b[i]];}
		else{++g[a[i]]; ++f[b[i]];}
	}
	for (int i=0;i<n;++i){
		uLL Ai=A*i,Bi=B*i,Ci=C*i;
		if (i<n-2) ans+=Ai*(((uLL)n-1-i)*(n-2-i)/2);
		if (i>0&&i<n-1) ans+=Bi*i*(n-1-i);
		if (i>1) ans+=Ci*((uLL)i*(i-1)/2);
		if (f[i]>1) ans+=Ai*((uLL)f[i]*(f[i]-1)/2);
		if (f[i]>0&&g[i]>0) ans+=Bi*f[i]*g[i];
		if (g[i]>1) ans+=Ci*((uLL)g[i]*(g[i]-1)/2);
		int xb=0;
		for (int j=head[i];j;j=e[j].nxt) q[++xb]=e[j].v;
		sort(q+1,q+xb+1);
		for (int j=1;j<=xb;++j)
			if (q[j]<i) ans+=A*q[j]*(xb-j)+B*q[j]*(j-1);
			else ans+=B*q[j]*(xb-j)+C*q[j]*(j-1);
	}
	for (int i=1;i<=m;++i){
		int x=a[i],y=b[i]; if (x>y) swap(x,y);
		uLL Ax=A*x,Cy=C*y;
		if (y<n-1) ans-=(Ax+B*y)*(n-1-y)+C*(((uLL)n-1-y)*(n+y)/2);
		if (x<y-1) ans-=(Ax+Cy)*(y-1-x)+B*(((uLL)y-1-x)*(x+y)/2);
		if (x>0) ans-=(B*x+Cy)*x+A*((uLL)x*(x-1)/2);
	}
	memset(vis,-1,sizeof vis);
	for (int x=0;x<n;++x){
		for (int i=head[x];i;i=e[i].nxt) vis[e[i].v]=x;
		for (int i=head[x];i;i=e[i].nxt){
			int y=e[i].v; uLL t1=A*min(x,y),t2=B*max(x,y);
			if (d[x]>d[y]||(d[x]==d[y]&&x<y)){
				for (int j=head[y];j;j=e[j].nxt){
					int z=e[j].v;
					if (x<z&&y<z&&vis[z]==x) ans-=t1+t2+C*z;
				}
			}
		}
	}
	printf("%llu\n",ans);
	
	return 0;
}