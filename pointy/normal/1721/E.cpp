// Author: Little09 qwq
// Problem: CF1721E Prefix Function Queries
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1721E
// Memory Limit: 250 MB
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
 
const int N=1100005;
int n,m,res,kmp[N],tr[N][26]; 
char a[N],b[N];
 
void prefix_function()
{
	int j=0;
	for (int i=2;i<=n;i++)
	{
		while (j>0&&a[j+1]!=a[i]) j=kmp[j];
		if (a[j+1]==a[i]) j++;
		kmp[i]=j;
	}
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<26;j++)
		{
			if (a[i+1]!='a'+j) tr[i][j]=tr[kmp[i]][j];
			else tr[i][j]=i;
		}
	}
	res=j;
}
 
void work()
{
	cin >> (b+1);
	m=strlen(b+1);
	for (int i=1;i<=m;i++) a[i+n]=b[i];
	int j=res;
	for (int i=n+1;i<=n+m;i++)
	{
		while (j>0&&a[j+1]!=a[i]) 
		{
			if (j>=n) j=kmp[j];
			else j=tr[j][a[i]-'a'];
		}
		if (a[j+1]==a[i]) j++;
		kmp[i]=j;
	}
	for (int i=n+1;i<=n+m;i++) cout << kmp[i] << " ";
	cout << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (a+1);
	n=strlen(a+1);
	prefix_function();
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}