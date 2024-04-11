// Author: Little09
// Problem: C. Make Them Equal
// Contest: Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/C
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
char a[N],x;
int s[N];

void work()
{
	cin >> n >> x;
	for (int i=1;i<=n;i++) cin >> a[i];
	int cnt=0;
	for (int i=1;i<=n;i++) cnt+=(a[i]==x);
	for (int i=1;i<=n;i++) s[i]=(a[i]==x);
	if (cnt==n)
	{
		cout << 0 << endl;
		return;
	}
	for (int i=1;i<=n;i++)
	{
		int tot=0;
		for (int j=1;i*j<=n;j++)
		{
			tot+=s[i*j];
		}
		if (tot==n/i)
		{
			cout << 1 << endl << i << endl;
			return;
		}
	}
	cout << 2 << endl << n-1 << " " << n << endl;
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