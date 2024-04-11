#include<stdio.h>
long long n;
int m,mod;
long long u,v;
inline long long min(long long a,long long b){return a<b?a:b;}
inline long long max(long long a,long long b){return a>b?a:b;}
inline long long solve(long long q,long long w,long long l,long long r,long long beg,long long st){
    if(q==l&&w==r){
	//printf("%lld %lld %lld %lld %lld %lld v=%lld u=%lld\n",q,w,l,r,beg,st,v,u);
	long long n=(r-l+1);
	long long las=beg+(n-1)*st;
	if(u<beg||v>las)return 0;
	long long vv=(v-beg+st-1)/st;
	long long uu=(u-beg)/st;
	vv=max(vv,0);
	uu=min(uu,n-1);
	//printf("%lld %lld\n",vv,uu);
	if(vv>uu)return 0;
	long long f=beg+vv*st;
	long long g=beg+uu*st;
	long long cnt=(uu-vv+1);
	f%=2*mod;g%=2*mod;cnt%=2*mod;
	return (((f+g)%(2*mod)*cnt)/2)%mod;
    }
    long long oddc=(q+w)/2;
    long long ans=0;
    if(r<=oddc)ans=(ans+solve(q,oddc,l,r,beg,st*2))%mod;
    else if(l<=oddc)ans=(ans+solve(q,oddc,l,oddc,beg,st*2))%mod;
    if(l>oddc)ans=(ans+solve(oddc+1,w,l,r,beg+st,st*2))%mod;
    else if(r>oddc)ans=(ans+solve(oddc+1,w,oddc+1,r,beg+st,st*2))%mod;
    return ans;
}
int main(){
    scanf("%I64d%d%d",&n,&m,&mod);
    while(m--){
	long long l,r;
	scanf("%I64d%I64d%I64d%I64d",&l,&r,&v,&u);//v,u is swapped
	printf("%d\n",(int)solve(1,n,l,r,1,1));
    }
}