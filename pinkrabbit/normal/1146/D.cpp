#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
int m,a,b,d;
int v[MN],que[MN],l,r,cnt;
int f[MN];
ll ans;
int main(){
	scanf("%d%d%d",&m,&a,&b),d=__gcd(a,b),a/=d,b/=d;
	f[0]=1,cnt=1,v[0]=1,l=1,r=0;
	F(i,1,a+b-1){
		if(i>=a&&v[i-a])v[i]=1,que[++r]=i,++cnt;
		while(l<=r){
			int u=que[l++];
			if(u+a<=i&&!v[u+a])v[u+a]=1,que[++r]=u+a,++cnt;
			if(u-b>=0&&!v[u-b])v[u-b]=1,que[++r]=u-b,++cnt;
		}f[i]=cnt;
	}
	if(m<(ll)(a+b)*d){
		F(i,0,a+b-1){
			if(m>=(ll)(i+1)*d)ans+=(ll)f[i]*d;
			else{ans+=(ll)f[i]*(m-(ll)i*d+1);break;}
		}
		printf("%lld\n",ans);
	}
	else{
		F(i,0,a+b-1)ans+=(ll)f[i]*d;
		ll x=m/d;
		ans+=(ll)d*(a+b+1+x)*(x-a-b)/2;
		ans+=(ll)(m-x*d+1)*(x+1);
		printf("%lld\n",ans);
	}
	return 0;
}