// Author: Little09
// Problem: CF1677D Tokitsukaze and Permutations
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1677D
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

const int N=1000005;
int n,m; 
int a[N];


void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=n-m+1;i<=n;i++)
	{
		if (a[i]!=0&&a[i]!=-1)
		{
			cout << 0 << endl;
			return;
		}
	}
	ll ans=1;
	for (int i=1;i<=m;i++) ans=ans*i%mod;
	for (int i=n;i>=m+1;i--) 
	{
		if (a[i-m]==0) ans=ans*(m+1)%mod;
		else if (a[i-m]==-1) ans=ans*i%mod;
	}
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