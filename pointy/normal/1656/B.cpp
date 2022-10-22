// Author: Little09
// Problem: B. Subtract Operation
// Contest: CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/B
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
int n,k; 
int a[N];
map<int,int>q;

void work()
{
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	q.clear();
	for (int i=1;i<=n;i++) 
	{
		if (q[a[i]+k])
		{
			printYES;
			return;
		}
		if (q[a[i]-k])
		{
			printYES;
			return;
		}
		q[a[i]]=1;
	}
	printNO;
	return;
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