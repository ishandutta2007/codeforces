// Author: Little09
// Problem: D. Slime Escape
// Contest: Codeforces - Codeforces Round #822 (Div. 2)
// URL: https://codeforces.com/contest/1734/problem/D
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll a[N],s[N];
ll f[N][21],g[N][21];
void STwork()
{
	for (int i=0;i<=n;i++) f[i][0]=s[i],g[i][0]=s[i];
	int t=log2(n);
	for (int i=1;i<=t;i++)
	{
		for (int j=0;j<=n-(1<<i)+1;j++)
		{
			f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
			g[j][i]=max(g[j][i-1],g[j+(1<<(i-1))][i-1]);
		}
	}
}
ll STquerymin(int l,int r)
{
	int t=log2(r-l+1);
	return min(f[l][t],f[r-(1<<t)+1][t]);
}
ll STquerymax(int l,int r)
{
	int t=log2(r-l+1);
	return max(g[l][t],g[r-(1<<t)+1][t]);
}
bool check(int l,int r,int tp,ll x)
{
	if (tp==0)
	{
		for (;l>1;) 
		{
			if (x+a[l-1]>=0) x+=a[l-1],l--;
			else return 0;
		}
		return 1;
	}
	else
	{
		for (;r<n;) 
		{
			if (x+a[r+1]>=0) x+=a[r+1],r++;
			else return 0;
		}
		return 1;
	}
}

void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	STwork();
	ll x=a[m];
	int L=m,R=m;
	while (L>1&&R<n)
	{
		int l=1,r=L-1;
		// for (int i=1;i<=L;i++) cout << STquerymin(i-1,L-1) << ' ';
		// cout << endl;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (STquerymin(mid-1,L-1)<s[L-1]) l=mid+1;
			else r=mid-1;
		}
		if (r!=0)
		{
			if (STquerymax(r-1,L-1)<=s[L-1]+x) 
			{
				x+=s[L-1]-s[r-1];
				L=r;
				continue;
			}
		}
		l=R+1,r=n;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (STquerymax(R+1,mid)>s[R]) r=mid-1;
			else l=mid+1;
		}
		if (l!=n+1)
		{
			if (STquerymin(R+1,l)>=s[R]-x) 
			{
				x+=s[l]-s[R];
				R=l;
				continue;
			}
		}
		break;
	}
	if (check(L,R,0,x)||check(L,R,1,x)) printYES;
	else printNO;
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