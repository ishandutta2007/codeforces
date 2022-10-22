// Author: Little09
// Problem: A. Balanced Rating Changes
// Contest: Codeforces Global Round 5
// URL: https://codeforces.com/contest/1237/problem/A
// Memory Limit: 512 MB
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
int a[N];
int tp;

void work()
{
	int x;
	cin >> x;
	if (x%2==0) cout << x/2 << endl;
	else 
	{
		tp^=1;
		if (tp) 
		{
			if (x<0) cout << x/2;
			else cout << (x+1)/2;
		}
		else 
		{
			if (x<0) cout << (x-1)/2;
			else cout << (x)/2;
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