// Author: Little09
// Problem: A. Game of Life
// Contest: Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/A
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
char a[N];
int b[N],c[N];


void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int j=1;j<=n;j++) b[j]=a[j]-'0';
	b[0]=0,b[n+1]=0;
	int las=0;
	for (int j=1;j<=n;j++) las+=b[j];
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (b[j-1]+b[j+1]==1) c[j]=1;
			else if (b[j]==1) c[j]=1;
			else c[j]=0;
		}
		int res=0;
		for (int j=1;j<=n;j++) res+=c[j];
		for (int j=1;j<=n;j++) b[j]=c[j];
		if (res==las) break;
		las=res;
	}
	for (int i=1;i<=n;i++) cout << b[i] ;
	cout << endl;
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