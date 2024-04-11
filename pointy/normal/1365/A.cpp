// Author: Little09
// Problem: A. Matrix Game
// Contest: Codeforces Round #648 (Div. 2)
// URL: https://codeforces.com/contest/1365/problem/A
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=55;
int n,m; 
int a[N][N],b[N],c[N];


void work()
{
	cin >> n >> m;
	mem(b),mem(c);
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=m;j++)
		{
			int x;
			cin >> x;
			if (x==1) b[i]=1,c[j]=1;
		}
	}
	int uu=0,vv=0;
	for (int i=1;i<=n;i++) uu+=(b[i]==0);
	for (int i=1;i<=m;i++) vv+=(c[i]==0);
	uu=min(uu,vv);
	if (uu%2==0) cout << "Vivek\n";
	else cout << "Ashish\n";
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