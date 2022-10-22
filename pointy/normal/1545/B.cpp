#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 
const ll mod=998244353;
const int N=100001;
int n,m,T; 
int a[N];
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll jc[N+5],inv[N+5];
inline ll C(ll x,ll y)
{
	if (y>x) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

void work()
{
	cin >> n;
	ll tot=0,sum1=0,sum=0;
	for (int i=1;i<=n;i++) 
	{
		char x;
		cin >> x;
		if (x=='0')
		{
			if (tot%2==1) sum++;
			tot=0;
		}
		else
		{
			tot++;
			sum1++;
		}
	}
	if (tot%2==1) sum++;
	ll x1=n-sum,x2=(sum1-sum)/2;
	ll ans=C(x1-x2,x2);
	cout << ans << endl;
	return;
}

int main()
{
	init();
	cin >> T;
	while (T--)
	{
		work();
	}
	return 0;
}