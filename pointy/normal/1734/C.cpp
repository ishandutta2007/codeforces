// Author: Little09
// Problem: C. Removing Smallest Multiples
// Contest: Codeforces - Codeforces Round #822 (Div. 2)
// URL: https://codeforces.com/contest/1734/problem/C
// Memory Limit: 256 MB
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
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=1000005;
int n,m; 
int a[N],b[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) 
	{
		char x;
		cin >> x;
		a[i]=x-'0';
		b[i]=0;
	}
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;i*j<=n;j++)
		{
			if (a[i*j]) break;
			if (b[i*j]) continue;
			b[i*j]=1;
			ans+=i;
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