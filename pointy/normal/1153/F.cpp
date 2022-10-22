// LUOGU_RID: 90823522
// Author: Little09
// Problem: CF1153F Serval and Bonus Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1153F
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=4005;
ll n,m; 
ll dp[N],l;

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

ll w[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> l;
	init();
	w[0]=1;
	for (int i=1;i<=n;i++) w[i]=w[i-1]*(2*i-1)%mod;
	//cout << w[2] << endl;
	ll tmp=ksm(2*n+1,mod-2)*l%mod,p=w[n],ans=0;
	for (int i=0;i<=2*n;i++)
	{
		ll res=0;
		for (int j=0;j<=n;j++) 
		{
			if (i<j||2*n-i<j) dp[j]=0;
			else if ((i-j)%2==1) dp[j]=0;
			else dp[j]=C(i,j)*C(2*n-i,j)%mod*w[(i-j)/2]%mod*w[(2*n-i-j)/2]%mod*jc[j]%mod;
		}
		// cout << i << endl;
		// for (int j=0;j<=n;j++) cout << dp[j] << " ";
		// cout << endl;
		for (int j=m;j<=n;j++) res=(res+dp[j])%mod;
		res=res*ksm(p,mod-2)%mod;
		ans=(ans+res)%mod; 
	}
	ans=ans*tmp%mod;
	cout << ans;
	return 0;
}