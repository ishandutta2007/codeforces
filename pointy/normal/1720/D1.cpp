// Author: Little09
// Problem: D2. Xor-Subsequence (hard version)
// Contest: Codeforces Round #815 (Div. 2)
// URL: https://codeforces.com/contest/1720/problem/D2
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

const int N=300005;
int n; 
int a[N];
int tot;
int ch[N*30][2],s[N*30][2],dp[N];
void insert(int x,int y,int w)
{
	int z=(x^y);
	int p=1;
	for (int i=30;i>=0;i--)
	{
		bool c=(z&(1<<i));
		if (!ch[p][c]) ch[p][c]=++tot;
		p=ch[p][c];
		//cout << p << " " << c << endl;
		if (x&(1<<i)) s[p][1]=max(s[p][1],w);
		else s[p][0]=max(s[p][0],w);
	}
}
int ask(int x,int y)
{
	int z=(x^y);
	int p=1,res=0;
	for (int i=30;i>=0;i--)
	{
		bool c=(z&(1<<i)),d=(y&(1<<i));
		int u=ch[p][c^1];
		p=ch[p][c];
		//int u=ch[p][c^1];
		//cout << "-" << u << " " << (c^1) << endl;
		if (u) res=max(res,s[u][d]);
		if (!p) return res;
	}
	return res;
}


void work()
{
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	tot=1;
	for (int i=0;i<=n*30;i++) ch[i][0]=ch[i][1]=0,s[i][0]=s[i][1]=0;
	for (int i=0;i<n;i++)
	{
		dp[i]=ask(a[i],i)+1;
		insert(a[i],i,dp[i]);
	}
	int ans=0;
	for (int i=0;i<n;i++) ans=max(ans,dp[i]);
	cout << ans << endl;
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