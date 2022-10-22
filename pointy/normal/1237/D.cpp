// Author: Little09
// Problem: D. Balanced Playlist
// Contest: Codeforces Global Round 5
// URL: https://codeforces.com/contest/1237/problem/D
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

int f[N][21],g[N][21];
int ans[N];
void STwork()
{
	for (int i=1;i<=3*n;i++) f[i][0]=a[i],g[i][0]=a[i];
	int t=log2(3*n);
	for (int i=1;i<=t;i++)
	{
		for (int j=1;j<=3*n-(1<<i)+1;j++)
		{
			f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
			g[j][i]=min(g[j][i-1],g[j+(1<<(i-1))][i-1]);
		}
	}
}
int STquerymax(int l,int r)
{
	if (l>r) return 0;
	int t=log2(r-l+1);
	return max(f[l][t],f[r-(1<<t)+1][t]);
}
int STquerymin(int l,int r)
{
	if (l>r) return 1000000333;
	int t=log2(r-l+1);
	return min(g[l][t],g[r-(1<<t)+1][t]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int mx=0,mn=1e9;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) mx=max(mx,a[i]),mn=min(mn,a[i]);
	if (mn*2>=mx)
	{
		for (int i=1;i<=n;i++) cout << "-1 ";
		return 0;
	}
	//cout << endl;
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	for (int i=1;i<=n;i++) a[i+n+n]=a[i];
	STwork();
	for (int i=3*n;i>=1;i--)
	{
		int l=i,r=3*n;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (STquerymax(i+1,mid)>a[i]) r=mid-1;
			else l=mid+1;
		}
		int x=l;
		l=i,r=3*n;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (STquerymin(i+1,mid)<=(a[i]-1)/2) r=mid-1;
			else l=mid+1;
		}
		int y=l;
		//cout << x << " " << y << " " << (a[i]-1)/2 << STquerymin(2,12)<< endl;
		if (x==n*3+1&&y==n*3+1) continue;
		if (x<y) ans[i]=ans[x];
		else ans[i]=y;
	}
	for (int i=1;i<=n;i++) cout << ans[i]-i << " ";
	return 0;
}