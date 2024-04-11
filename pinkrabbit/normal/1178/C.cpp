#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m;
ll ans=1;
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n+m)ans=2*ans%mod;
	printf("%lld\n",ans);
	return 0;
}