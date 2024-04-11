#include<cstdio>
const int maxn=100000,mod=1000000007;
int n,m,a[maxn+10],now=1,ans,r,rr;
int add(int x,int y){return (x+y)%mod;}
int dec(int x,int y){return (x-y+mod)%mod;}
int mul(int x,int y){return 1ll*x*y%mod;}
int fpow(int x,int y){
	int ans=1;
	for(;y;y/=2,x=mul(x,x)) if(y%2) ans=mul(ans,x);
	return ans;
}
int div(int x,int y){return mul(x,fpow(y,mod-2));}
int main(){
	scanf("%d%d",&n,&m); r=div(1,m); rr=div(dec(1,r),2);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		if(!x&&!a[i]) ans=add(ans,mul(now,rr)),now=mul(now,r);
		else if(!x) ans=add(ans,mul(now,div(a[i]-1,m))),now=mul(now,r);
		else if(!a[i]) ans=add(ans,mul(now,div(m-x,m))),now=mul(now,r);
		else if(a[i]>x){
			ans=add(ans,now); break;
		}else if(a[i]<x) break;
	}
	printf("%d",ans);
}