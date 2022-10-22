// Author: Little09
// Problem: E. Balance Addicts
// Contest: Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll a[N];
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
ll b[N],c[N],cnt;
map<ll,ll>q;
map<ll,bool>used;

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	cnt=0;
	for (int i=1;i<=n;i++) b[i]=0,c[i]=0;
	for (int i=1;i<n;i++)
	{
		if (i==1|a[i]!=a[i-1])
		{
			cnt++;
			b[cnt]=a[i];
			c[cnt]=1;
		}
		else
		{
			c[cnt]++;
		}
	}
	q.clear(),used.clear();
	for (int i=1;i<=cnt;i++) q[b[i]]=c[i];
	ll res=1;
	for (int i=1;i<=cnt;i++)
	{
		if (used[b[i]]) continue;
		used[b[i]]=1;
		if (q[a[n]-b[i]]==0) continue;
		used[a[n]-b[i]]=1;
		if (b[i]*2==a[n])
		{
			int L=q[b[i]];
			ll s=1;
			for (int j=1;j<=L;j++) s=(s+C(L,j))%mod;
			res=res*s%mod;
			continue;	
		}
		int L=q[b[i]],R=q[a[n]-b[i]];
		int u=min(L,R);
		ll s=1;
		for (int j=1;j<=u;j++) s=(s+C(L,j)*C(R,j)%mod)%mod;
		res=res*s%mod;
	} 
	cout << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}