// Author: Little09
// Problem: CF1613D MEX Sequences
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1613D
// Memory Limit: 250 MB
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];
ll g[N],f[N];

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=0;i<=n;i++) g[i]=0,f[i]=0;
	ll tmp=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1) tmp=tmp*2%mod;
		if (a[i]==0) f[0]=(1+f[0]*2ll)%mod;
		else f[a[i]]=(f[a[i]-1]+f[a[i]]*2ll)%mod;
		if (a[i]>1) g[a[i]-1]=(g[a[i]-1]*2ll+f[a[i]-2])%mod;
		g[a[i]+1]=(g[a[i]+1]*2ll)%mod;
	}
	ll ans=tmp-1;
	for (int i=0;i<=n;i++) ans=(ans+f[i]+g[i])%mod;
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}