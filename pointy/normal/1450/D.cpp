// Author: Little09
// Problem: D. Rating Compression
// Contest: Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/D
// Memory Limit: 256 MB
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
int a[N],c[N];
int res[N];

int f[N][21];
void STwork()
{
	for (int i=1;i<=n;i++) f[i][0]=a[i];
	int t=log2(n);
	for (int i=1;i<=t;i++)
	{
		for (int j=1;j<=n-(1<<i)+1;j++)
		{
			f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
		}
	}
}
int STquery(int l,int r)
{
	int t=log2(r-l+1);
	return min(f[l][t],f[r-(1<<t)+1][t]);
}

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) c[i]=0,res[i]=0;
	for (int i=1;i<=n;i++) c[a[i]]++;
	STwork();
	int fl=1,mn=n+1;
	for (int i=1;i<=n;i++)
	{
		mn=min(mn,a[i]);
		if (c[i]!=1) fl=0;
	}
	cout << fl;
	if (n==1)
	{
		cout << endl;
		return;
	}
	int l=1,r=n;
	int tot=0;
	while (l<=r)
	{
		++tot;
		if (c[tot]>1) break;
		if (a[l]!=tot&&a[r]!=tot) break;
		if (a[l]==tot) l++;
		else r--;
		if (l>r) res[tot]=1;
		else res[tot]=(STquery(l,r)==tot+1);
	}
	for (int i=2;i<n;i++) cout << res[n-i];
	cout << (mn==1) << endl;
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