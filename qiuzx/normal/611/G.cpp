//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll cross(ll xa,ll ya,ll xb,ll yb){return xa*yb-xb*ya;}
ll n,dx[N],dy[N],sumx[N],sumy[N],tots=0,ans=0,sum,cur;
void upd(ll i,ll j)
{
	cur+=abs(cross(dx[j]-dx[i],dy[j]-dy[i],dx[j+1]-dx[i],dy[j+1]-dy[i]));
	sum=(sum+cur)%mod;
	return;
}
void trs(ll i,ll j)
{
	cur+=cross(dx[i+1]-dx[i],dy[i+1]-dy[i],dx[j]-dx[i],dy[j]-dy[i]);
	ll px=(dx[i+1]-dx[i]+mod)%mod,py=(dy[i+1]-dy[i]+mod)%mod;
	sum=(sum+((j-i-1)*((py*dx[i]+mod-(px*dy[i])%mod)%mod))%mod+(px*((sumy[j+1]-sumy[i+2])%mod))%mod+mod-((py*((sumx[j+1]-sumx[i+2])%mod))%mod))%mod;
	return;
}
int main(){
	ll i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&dx[i],&dy[i]);
		dx[i+n]=dx[i],dy[i+n]=dy[i];
	}
	for(i=1;i+1<n;i++)
	{
		tots+=abs(cross(dx[i]-dx[0],dy[i]-dy[0],dx[i+1]-dx[0],dy[i+1]-dy[0]));
	}
	for(i=0;i<n*2;++i)
	{
		sumx[i+1]=sumx[i]+dx[i];
		sumy[i+1]=sumy[i]+dy[i];
	}
	for(i=0,j=1,sum=0,cur=0;i<n;i++)
	{
		while(j+1<2*n&&(unsigned long long)(cur+abs(cross(dx[j]-dx[i],dy[j]-dy[i],dx[j+1]-dx[i],dy[j+1]-dy[i])))*(ll)2<=tots)
		{
			upd(i,j);
			++j;
		}
		ans+=((tots%mod)*(j-i-1))%mod-2*sum;
		ans=(ans%mod+mod)%mod;
		if(i+1<n)
		{
			trs(i,j);
		}
	}
	printf("%lld\n",ans);
	return 0;
}