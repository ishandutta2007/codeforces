// Author: Little09
// Problem: C. Nezzar and Nice Beatmap
// Contest: Codeforces Round #698 (Div. 1)
// URL: https://codeforces.com/contest/1477/problem/C
// Memory Limit: 512 MB
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
ll a[N],b[N];
bool vis[N];

ll dis(int x,int y)
{
	return (a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
	int las=1;
	cout << las << " ";
	vis[1]=1;
	for (int i=1;i<n;i++)
	{
		int v=-1;
		for (int j=1;j<=n;j++)
		{
			if (vis[j]) continue;
			if (v==-1||dis(v,las)<dis(j,las)) v=j;
		}
		vis[v]=1;
		las=v;
		cout << las << " ";
	}
	return 0;
}