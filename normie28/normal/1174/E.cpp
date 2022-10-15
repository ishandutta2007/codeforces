#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll n,m,i,j,k,t,t1,u,v,a,b,res;
ll fac[2000001],inv[2000001];
ll cnt2[1000001],cnt3[1000001];
ll buc[22][2];
ll bow(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=bow(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%=p;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	fac[0]=1;
	inv[0]=1;
	for (i=1;i<=2*n;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=MOD;
		inv[i]=bow(fac[i],MOD-2,MOD);
	}
	for (i=1;i<=n;i++)
	{
		u=i;
		while(u%2==0)
		{
			cnt2[i]++;
			u/=2;
		}
		while(u%3==0)
		{
			cnt3[i]++;
			u/=3;
		}
	}
	for (i=1;i<=n;i++) buc[cnt2[i]][0]++;
	u=1;
	v=0;
	for (i=0;i<20;i++)
	{
		if (buc[i][0])
		{
			u*=fac[v+buc[i][0]-1];
			u%=MOD;
			u*=inv[v];
			u%=MOD;
			u*=buc[i][0];
			u%=MOD;
			v+=buc[i][0];
//			cout<<buc[i][0]<<endl;
		}
	}
	res+=u;
//	cout<<res<<endl;
	res%=MOD;
	a=n/3;
	b=n;
	if (floor(log2(a))+1==floor(log2(b)))
	{
		a=floor(log2(a));
		for (i=0;i<=a;i++) buc[i][0]=0;
		for (i=1;i<=n;i++) buc[min(cnt2[i],a)][min(cnt3[i],ll(1))]++;
		for (i=0;i<=a;i++)
		{
			u=1;
			v=0;
			b=0;
			for (j=0;j<i;j++)
			{
				b=buc[j][0]+buc[j][1];
				if (b)
				{
					u*=fac[v+b-1];
					u%=MOD;
					u*=inv[v];
					u%=MOD;
					u*=b;
					u%=MOD;
					v+=b;
				}
			}
			b=0;
			for (j=i;j<=a;j++) b+=buc[j][0];
				if (b)
				{
					u*=fac[v+b-1];
					u%=MOD;
					u*=inv[v];
					u%=MOD;
					u*=b;
					u%=MOD;
					v+=b;
				}
			for (j=i;j<=a;j++)
			{
				b=buc[j][1];
				if (b)
				{
					u*=fac[v+b-1];
					u%=MOD;
					u*=inv[v];
					u%=MOD;
					u*=b;
					u%=MOD;
					v+=b;
				}
			}
			res+=u;
			res%=MOD;
		}
	}
	cout<<res;
}