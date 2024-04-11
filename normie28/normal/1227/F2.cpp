#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,m,i,j,k,t,t1,u,v,a,b,cur,sum;
ll diffcnt;
ll arr[200001];
ll fac[200001];
ll inv[200001];
ll bow(ll a, ll x)
{
	if (x==0) return 1;
	ll res=bow(a,x/2);
	res*=res;
	res%=MOD;
	if (x%2) res*=a;
	return res%MOD; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=0;i<n;i++) cin>>arr[i];
	for (i=0;i<n;i++) if (arr[i]!=arr[(i+1)%n]) diffcnt++;
	cur=bow(m,n-diffcnt);
	fac[0]=1;
	inv[0]=1;
	for (i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=MOD;
		inv[i]=bow(fac[i],MOD-2);
	}
	sum=0;
	if (n-2>=0)
	{
		for (i=0;i<diffcnt;i++)
		{
			u=bow(m-2,i);
			v=diffcnt-i;
			a=bow(2,v);
			if (v%2==0) {
			a-=fac[v]*inv[v/2]%MOD*inv[v/2]%MOD%MOD; a+=MOD;a%=MOD;}
			a*=bow(2,MOD-2);
			a%=MOD;
			a*=u;
			a%=MOD;
			a*=fac[diffcnt]*inv[i]%MOD*inv[v]%MOD;
			a%=MOD;
	//		cout<<i<<' '<<a<<endl;
			sum+=a;
			sum%=MOD;
		}
	}
//	cout<<cur<<' '<<sum<<endl;
	cout<<(cur*sum)%MOD;
}