// Author: Little09
// Problem: E. Tokitsukaze and Duel
// Contest: Codeforces - Codeforces Round #573 (Div. 2)
// URL: https://codeforces.com/contest/1191/problem/E
// Memory Limit: 256 MB
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N];


void work()
{
	//cin >> n;
	//for (int i=1;i<=n;i++) cin >> a[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		char x;
		cin >> x;
		a[i]=x-'0';
		b[i]=b[i-1]+a[i];
	}
	for (int i=m;i<=n;i++)
	{
		if (b[i-m]+b[n]-b[i]==0||b[i-m]+b[n]-b[i]==n-m)
		{
			cout << "tokitsukaze";
			return 0;
		}
	}
	for (int i=m;i<=n;i++)
	{
		if (n-i>m||i-m>m)
		{
			cout << "once again";
			return 0;
		}
		if (i==m||i==n) continue;
		if (b[n]-b[i]>0&&b[i-m]>0)
		{
			cout << "once again";
			return 0;
		}
		if (b[n]-b[i]<n-i&&b[i-m]<i-m)
		{
			cout << "once again";
			return 0;
		}
	}
	cout << "quailty";
	return 0;
}