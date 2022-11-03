#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll x[5010],a[5010],b[5010],c[5010],d[5010];
ll f[2][2510][2][2];
void cxk(ll&a,ll b){if(a>b)a=b;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	int s=gi(),e=gi();
	for(int i=1;i<=n;++i)x[i]=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int i=1;i<=n;++i)b[i]=gi();
	for(int i=1;i<=n;++i)c[i]=gi();
	for(int i=1;i<=n;++i)d[i]=gi();
	memset(f[0],63,sizeof f[0]);
	f[0][0][0][0]=0;
	int o=0;
	for(int i=1;i<n;++i){
		memset(f[!o],63,sizeof f[!o]);
		for(int j=0;j*2<=n;++j){
			for(int S=0;S<2;++S)
				for(int E=0;E<2;++E){
					if(i==s){
						cxk(f[!o][j][1][E],f[o][j][S][E]-x[i]+d[i]);
						if(j)cxk(f[!o][j-1][1][E],f[o][j][S][E]+x[i]+c[i]);
					}else if(i==e){
						cxk(f[!o][j][S][1],f[o][j][S][E]-x[i]+b[i]);
						if(j)cxk(f[!o][j-1][S][1],f[o][j][S][E]+x[i]+a[i]);
					}else{
						cxk(f[!o][j+1][S][E],f[o][j][S][E]-2*x[i]+b[i]+d[i]);
						if(j)if(j>1||S||E)cxk(f[!o][j-1][S][E],f[o][j][S][E]+2*x[i]+a[i]+c[i]);
						if(j||S)cxk(f[!o][j][S][E],f[o][j][S][E]+a[i]+d[i]);
						if(j||E)cxk(f[!o][j][S][E],f[o][j][S][E]+b[i]+c[i]);
					}
				}
		}
		o^=1;
	}
	ll ans=1e18;
	if(s==n)ans=f[o][0][0][1]+x[n]+c[n];
	else if(e==n)ans=f[o][0][1][0]+x[n]+a[n];
	else ans=f[o][0][1][1]+2*x[n]+a[n]+c[n];
	printf("%lld\n",ans);
	return 0;
}