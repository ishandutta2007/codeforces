// Author: Little09
// Problem: C. Column Swapping
// Contest: Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/C
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

const int N=200005;
int n,m; 
vector<int>a[N],d[N];
bool p[N];
int b[N],c[N];

bool check(int x,int y)
{
	for (int i=1;i<=m;i++) c[i]=i;
	if (x!=y) swap(c[x],c[y]);
	for (int i=1;i<=n;i++)
	{
		for (int j=2;j<=m;j++)
		{
			if (a[i][c[j]]<a[i][c[j-1]]) return 0;
		}
	}
	return 1;
}

void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) a[i].clear();
	for (int i=1;i<=n;i++) d[i].clear();
	for (int i=1;i<=m;i++) p[i]=0;
	for (int i=1;i<=n;i++)
	{
		a[i].push_back(0);
		d[i].push_back(0);
		for (int j=1;j<=m;j++)
		{
			int x;
			cin >> x;
			a[i].push_back(x);
			d[i].push_back(x);
		}
		sort(d[i].begin(),d[i].end());
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]!=d[i][j]) p[j]=1;
		}
	}
	int tot=0;
	for (int i=1;i<=m;i++)
	{
		tot+=p[i];
		if (p[i]) b[tot]=i;
	}
	if (tot>=3)
	{
		cout << -1 << endl;
		return;
	}
	if (tot==0) b[++tot]=1;
	for (int i=1;i<=tot;i++)
	{
		for (int j=i;j<=tot;j++)
		{
			if (check(b[i],b[j]))
			{
				cout <<b[i] <<" "<<b[j]<<endl;
				return;
			}
		}
	}
	cout << -1 << endl;
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