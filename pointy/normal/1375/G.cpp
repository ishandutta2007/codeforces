// Author: Little09
// Problem: G. Tree Modification
// Contest: Codeforces Global Round 9
// URL: https://codeforces.com/contest/1375/problem/G
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
vector<int>t[N];
int dis[N];

void dfs(int x,int f)
{
	dis[x]=dis[f]^1;
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs(i,x);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		t[x].push_back(y);
		t[y].push_back(x);
	}
	dis[1]=0;
	dfs(1,0);
	int ans=0;
	for (int i=1;i<=n;i++) ans+=(dis[i]==1);
	cout << min(ans,n-ans)-1;
	return 0;
}