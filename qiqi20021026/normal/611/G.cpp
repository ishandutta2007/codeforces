#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 1200000

const LL mod=1000000007;
//const LL mod=998244353;
struct node{
	LL x,y;
	node(LL x=0,LL y=0):x(x),y(y){}
	node operator + (const node &p) const{
		return node(x+p.x,y+p.y);
	}
	node operator - (const node &p) const{
		return node(x-p.x,y-p.y);
	}
	LL operator * (const node &p) const{
		return x*p.y-y*p.x;
	}
}a[N],b[N];
LL n,s,pre[N],ans;

void upd(LL &x,LL y){x=(x+y)%mod;}

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	for (LL i=2;i<n;++i){
		s+=(a[i+1]-a[1])*(a[i]-a[1]);
	}
	for (LL i=1;i<=n;++i) a[i+n]=a[i];
	for (LL i=2;i<=n*2;++i){
		pre[i]=pre[i-1]+a[i]*a[i-1];
		b[i]=b[i-1];
		upd(b[i].x,a[i].x);
		upd(b[i].y,a[i].y);
	}
	LL now=0,sum=0;
	for (LL i=1,j=3;i<=n;++i){
		for (;;++j){
			LL tmp=(a[j]-a[i])*(a[j-1]-a[i]);
			if ((now+tmp)>=(s+1)/2) break;
			now+=tmp;
			upd(sum,now);
		}
		upd(ans,s%mod*(j-i-2)-sum*2);
		now-=a[i]*a[j-1]+a[j-1]*a[i+1]+a[i+1]*a[i];
		upd(sum,-(a[i]*(b[j-1]-b[i])%mod+(b[j-1]-b[i])*a[i+1]%mod+a[i+1]*a[i]%mod*(j-i-1)%mod));
//		for (LL k=i+1;k<j;++k) 
//		sum-=a[i]*a[k]+a[k]*a[i+1]+a[i+1]*a[i];
	}
	upd(ans,mod);
//	ans=ans*inv(2)%mod;
	printf("%lld\n",ans);
	
	return 0;
}