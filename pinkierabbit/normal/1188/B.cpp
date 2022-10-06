#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,p,k,a[MN];
map<int,int>mp;
ll ans;
int main(){
	scanf("%d%d%d",&n,&p,&k);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)++mp[((ll)a[i]*a[i]%p*a[i]%p-k+p)%p*a[i]%p];
	for(auto v:mp)ans+=(ll)v.second*(v.second-1)/2;
	printf("%lld\n",ans);
	return 0;
}