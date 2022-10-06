#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define ll long long
#define MN 300005
#define MM 600005
#define mod 1000000007
int n,m,q,k,l,r,b1,b2,b3;
int a[MN],b[MN],f[MN],g[MN];
int main(){
	scanf("%d%d%d",&n,&l,&r),--l;
	b3=r/3-l/3;
	b2=(r+1)/3-(l+1)/3;
	b1=(r+2)/3-(l+2)/3;
//	printf("%d %d %d\n",b3,b1,b2);
	ll f1=0,f2=0,f3=1;
	F(i,1,n){
		int g1=(f1*b3+f2*b2+f3*b1)%mod;
		int g2=(f2*b3+f3*b2+f1*b1)%mod;
		int g3=(f3*b3+f1*b2+f2*b1)%mod;
		f1=g1,f2=g2,f3=g3;
	}
	printf("%lld\n",f3);
	return 0;
}