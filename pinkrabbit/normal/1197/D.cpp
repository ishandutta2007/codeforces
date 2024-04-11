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
int n,m,k;
int a[MN],b[MN];
ll ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,n)scanf("%d",a+i);
	F2(j,0,m){
		F(i,1,n)b[i]=a[i]-(i%m==j?k:0);
		ll s=0;
		F(i,1,n){
			s=std::max(s+b[i],0ll);
			if(i%m==j)ans=max(ans,s);
		}
	}printf("%lld\n",ans);
	return 0;
}