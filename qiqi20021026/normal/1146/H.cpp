#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 320

LL n,m,ans,x[N],y[N],f[6][N][N];
struct node{
	LL x,y,u,v;
	node(LL x=0,LL y=0,LL u=0,LL v=0):x(x),y(y),u(u),v(v){}
	bool operator < (const node &w) const{
		LL o1=x>0||(x==0&&y>0),o2=(w.x>0)||(w.x==0&&w.y>0);
		if (o1!=o2) return o1<o2;
		return x*w.y-y*w.x>=0;
	}
}a[N*N];

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		scanf("%lld%lld",x+i,y+i);
	}
	for (LL i=1;i<=n;++i)
		for (LL j=1;j<=n;++j)
			if (i!=j) a[++m]=node(x[i]-x[j],y[i]-y[j],i,j);
	sort(a+1,a+m+1);
	for (LL i=1;i<=n;++i) f[0][i][i]=1;
	for (LL i=1;i<=m;++i)
		for (LL j=0;j<5;++j)
			for (LL k=1;k<=n;++k)
				f[j+1][k][a[i].v]+=f[j][k][a[i].u];
	for (LL i=1;i<=n;++i) ans+=f[5][i][i];
	printf("%lld\n",ans);
	
	return 0;
}