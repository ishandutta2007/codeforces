// Author: Little09
// Problem: B. Mainak and Interesting Sequence
// Contest: Codeforces - Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.ml/contest/1726/problem/B
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
	cin >> n >> m;
	if (n>m)
	{
		printNo;
		return;
	}
	if (n%2==1)
	{
		printYes;
		for (int i=1;i<n;i++) cout << "1 ";
		cout << m-(n-1) << endl;
	}
	else if (m%2==1)
	{
		printNo;
		return;
	}
	else
	{
		printYes;
		for (int i=1;i<n-1;i++) cout << "1 ";
		cout << (m-(n-2))/2 << " " << (m-(n-2))/2 << endl;
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