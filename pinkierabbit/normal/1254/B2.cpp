#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
int a[MN];
ll s[MN],S,z,ans;
void chk(ll x){
	ll m=x/2+1,s=0,c=0;
	F(i,1,n){
		if(!a[i])continue;
		ll z=min(x-s,(ll)a[i]);
		if(s+z<m)c-=z*i,s+=z;
		else if(s>=m)c+=z*i,s+=z;
		else c-=(m-s-1)*i,c+=(s+z-m-(x&1)+1)*i,s+=z;
//		printf("%lld\n",c);
		if(s==x){
			z=(a[i]-z)%x;
//			printf("z=%lld\n",z);
			if(z>=m)c-=(m-1)*i,c+=(z-m-(x&1)+1)*i;
			else c-=z*i;
//			printf("c=%lld\n",c);
			s=z;
		}
	}
//	printf("%lld:%lld\n",x,c);
	ans=min(ans,c);
}
int main(){
	scanf("%d",&n),ans=infll;
	F(i,1,n)scanf("%d",a+i),s[i]=s[i-1]+a[i];
	z=S=s[n];
	for(int i=2;i<=z/i;++i)if(z%i==0){chk(i);while(z%i==0)z/=i;}
	if(z>1)chk(z);
	printf("%lld\n",ans==infll?-1ll:ans);
	return 0;
}