#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll n,m,a[N],suml[N],sumr[N],sume[N],ans=0;
vector<ll> plc;
struct BIT{
	ll val[N];
	void upd(ll x,ll v)
	{
		x++;
		while(x<N)
		{
			val[x]+=v;
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		x++;
		ll ret=0;
		while(x>0)
		{
			ret+=val[x];
			x-=x&(-x);
		}
		return ret;
	}
}bit1,bit2;
int main(){
	ll i,j;
	scanf("%lld%lld",&n,&m);
	plc.push_back(-1);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==m)
		{
			plc.push_back(i);
		}
	}
	for(i=0;i<n;i++)
	{
		sumr[i+1]=sumr[i]+(a[i]>m);
		suml[i+1]=suml[i]+(a[i]<m);
		sume[i+1]=sume[i]+(a[i]==m);
	}
	plc.push_back(n);
	for(i=plc.size()-2;i>0;i--)
	{
		for(j=plc[i];j<plc[i+1];j++)
		{
			bit1.upd(500005+sumr[j+1]-sume[j+1]-suml[j+1],1);
			bit2.upd(500005+sumr[j+1]+sume[j+1]-suml[j+1],1);
		}
		for(j=plc[i];j>plc[i-1];j--)
		{
			ans+=bit1.qry(500005+sumr[j]-sume[j]-suml[j])-bit2.qry(500005+sumr[j]+sume[j]-suml[j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}