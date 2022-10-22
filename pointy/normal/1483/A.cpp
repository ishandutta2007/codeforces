// Author: Little09
// Problem: C. Basic Diplomacy
// Contest: Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/C
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
int a[N][2],b[N],c[N];


void work()
{
	cin >> n >> m;
	for (int i=1;i<=m;i++)
	{
		int x;
		cin >> x;
		b[i]=min(x,2);
		for (int j=0;j<x;j++)
		{
			int y;
			cin >> y;
			if (j<=1) a[i][j]=y;
		}
	}
	for (int i=1;i<=n;i++) c[i]=0;
	for (int i=1;i<=m;i++)
	{
		if (b[i]==1) c[a[i][0]]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (c[i]>(m+1)/2)
		{
			printNO;
			return;
		}
	}
	printYES;
	for (int i=1;i<=m;i++)
	{
		if (b[i]==2) c[a[i][0]]++;
	}
	int ans=1;
	for (int i=1;i<=n;i++) if (c[i]>c[ans]) ans=i;
	if (c[ans]<=(m+1)/2)
	{
		for (int i=1;i<=m;i++) cout << a[i][0] << " ";
		cout << endl;
		return;
	}
	for (int i=1;i<=m;i++)
	{
		if (b[i]==1) continue;
		if (c[a[i][0]]>(m+1)/2)
		{
			swap(a[i][0],a[i][1]);
			c[a[i][1]]--;
		}
	}
	for (int i=1;i<=m;i++) cout << a[i][0] << " ";
		cout << endl;
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