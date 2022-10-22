#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=998244353;
const int M=510;
int dp[M][M],vis[M][M],a[M],n;

int dfs(int l,int r)
{
	if (vis[l][r])return dp[l][r];
	if (l>r)return 1;
	vis[l][r]=1;int sum1=0,sum2=0,maxp=l;
	for (int i=l+1;i<=r;i++)
		if (a[i]<a[maxp])maxp=i;
	for (int i=l;i<=maxp;i++)
		sum1=(sum1+dfs(l,i-1)*dfs(i,maxp-1))%Mod;
	for (int i=maxp;i<=r;i++)
		sum2=(sum2+dfs(maxp+1,i)*dfs(i+1,r))%Mod;
	return dp[l][r]=sum1*sum2%Mod;
}

signed main()
{
	n=read(),read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	cout<<dfs(1,n)<<endl;
	return 0;
}