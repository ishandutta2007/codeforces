#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
int n;ll k;
ll a[MN],f[MN][3],ans;
int main(){
	scanf("%d%lld",&n,&k);
	F(i,1,n)scanf("%lld",a+i);
	F(i,1,n){
		f[i][0]=std::max(0ll,f[i-1][0]+a[i]);
		f[i][1]=std::max(0ll,std::max(f[i-1][0],f[i-1][1])+a[i]*k);
		f[i][2]=std::max(0ll,std::max(f[i-1][1],f[i-1][2])+a[i]);
		ans=std::max(ans,std::max(f[i][0],std::max(f[i][1],f[i][2])));
	}printf("%lld\n",ans);
	return 0;
}