#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define ll long long
int n;
ll a[MN],b[MN],s,ans;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%lld%lld",&a[i],&b[i]),s+=a[i];
	if(s<0)F(i,1,n)a[i]*=-1;
	dF(j,61,0){
		ll S=0;
		F(i,1,n)if(b[i]==(1ll<<j))S+=a[i];
		if(S>0)ans|=1ll<<j;
		F(i,1,n)if(b[i]>>j&1){b[i]^=1ll<<j;if(S>0)a[i]*=-1;}
	}printf("%lld\n",ans);
	return 0;
}