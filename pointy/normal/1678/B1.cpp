// Author: Little09
// Problem: CF1678B1 Tokitsukaze and Good 01-String (easy version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1678B1
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
char a[N];
int b[N],cnt,ans;


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	int las=0;
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (i!=1&&a[i]!=a[i-1]) b[++cnt]=las,las=1;
		else las^=1;
	}
	b[++cnt]=las;
	las=-1,ans=0;
	for (int i=1;i<=cnt;i++)
	{
		if (b[i]==1) 
		{
			if (las==-1) las=i;
			else ans+=i-las,las=-1;
		}
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