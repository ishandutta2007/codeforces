#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=55;
const ll inf=1e18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline void ckmn(int &x,int y){if (x>y) x=y;}
int n,k,a[N],b[N],c[N],dp[N][N][N][2][2][2][2];
int dfs(int i,int l,int r,int l1,int l2,int r1,int r2)
{
	if (i==k) return l>r?0:inf;
	int &now=dp[i][l][r][l1][l2][r1][r2];
	if (~now) return now;
	int L=((l1?b[l-1]:a[l-1])>>i)^l2,R=((r1?b[r+1]:a[r+1])>>i)^r2;
	now=inf;
	ckmn(now,dfs(i+1,l,r,l1,0,r1,0)+(l>1&&r<n&&(L^R)%2?c[i]:0));
	for (int k=l;k<=r;k++)
	for (int t=0;t<=1;t++)
	{
		if (!i) ckmn(now,dfs(i,l,k-1,l1,l2,t,0)+dfs(i,k+1,r,t,0,r1,r2));
		int val=((t?b[k]:a[k])>>i)^1,left=a[k]>>i,right=b[k]>>i;
		if (left<val&&val<right) ckmn(now,dfs(i,l,k-1,l1,l2,t,1)+dfs(i,k+1,r,t,1,r1,r2));
	}
	return now;
}

signed main()
{
	memset(dp,-1,sizeof(dp));
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for (int i=0;i<k;i++) c[i]=read();
	print(dfs(0,1,n,0,0,0,0));
	
	return 0;
}