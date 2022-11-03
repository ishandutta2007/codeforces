#include<bits/stdc++.h>
#define vd void
#define il inline
using namespace std;
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int a[400010],u[400010],c[400010],C[400010],d[400010];
std::vector<int>A[400010],v[400010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)a[i]=u[i]=gi();
	std::sort(u+1,u+n+1);
	for(int i=1;i<=n;++i)a[i]=std::lower_bound(u+1,u+n+1,a[i])-u;
	for(int i=1;i<=n;++i)++c[a[i]];
	for(int i=1;i<=n;++i)++C[c[i]];
	int ans=0,h=0,w=0,sum=0;
	for(int i=1;i<=n;++i)sum+=C[i];
	for(int i=1,pre=0;i<=n;++i){
		pre+=C[i]*i,sum-=C[i];
		int s=(sum*i+pre)/i;
		if(s>=i&&i*s>ans)ans=i*s,h=i,w=s;
	}
	printf("%d\n%d %d\n",ans,h,w);
	for(int i=1;i<=h;++i)A[i].resize(w);
	for(int l=1,r;l<=n;l=r+1){
		r=l;while(r<n&&u[r]==u[r+1])++r;
		v[r-l+1].push_back(u[r]);
	}
	int m=0;
	for(int i=n;i;--i)for(int j:v[i])for(int k=0;k<std::min(i,h);++k)d[++m]=j;
	m=0;
	for(int i=1;i<=w;++i)
		for(int j=1;j<=h;++j)
			A[j][(i+j)%w]=d[++m];
	for(int i=1;i<=h;++i){
		for(int j=0;j<w;++j)
			printf("%d ",A[i][j]);
		puts("");
	}
	return 0;
}