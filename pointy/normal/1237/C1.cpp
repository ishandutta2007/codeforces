// Author: Little09
// Problem: C1. Balanced Removals (Easier)
// Contest: Codeforces Global Round 5
// URL: https://codeforces.com/contest/1237/problem/C1
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
int a[N],b[N],c[N];
bool used[N];
int dis(int x,int y)
{
	return abs(a[x]-a[y])+abs(b[x]-b[y])+abs(c[x]-c[y]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		int mx=1e9,mu=-1;
		for (int j=1;j<=n;j++)
		{
			if (used[j]) continue;
			if (i==j) continue;
			int d=dis(i,j);
			if (d<mx) mx=d,mu=j;
		}
		used[i]=1,used[mu]=1;
		cout << i << " " << mu << endl;
	}
	return 0;
}