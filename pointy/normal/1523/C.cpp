// Author: Little09
// Problem: C. Compression and Expansion
// Contest: Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/C
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
int a[N];


void work()
{
	cin >> n;
	int cnt=0;
	for (int i=1;i<=n;i++) 
	{
		int x;
		cin >> x;
		if (x==1)
		{
			a[++cnt]=x;
		}
		else
		{
			while (cnt&&x!=a[cnt]+1) cnt--;
			a[cnt]=x;	
		}
		for (int j=1;j<=cnt;j++)
		{
			cout << a[j];
			if (j<cnt) cout << ".";
		}
		cout << endl;
	}
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