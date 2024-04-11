// By: Little09qwq
// Problem: D. Permutation Graph
// Contest: Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N],dp[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
int fax[N][25],fin[N][25];
void STwork()
{
	for (int i=1;i<=n;i++) fax[i][0]=a[i];
	for (int i=1;i<=n;i++) fin[i][0]=a[i];
	int t=log(n)/log(2);
	for (int j=1;j<=t;j++)
	{
		for (int i=1;i<=n-(1<<j)+1;i++)
		{
			fax[i][j]=max(fax[i][j-1],fax[i+(1<<(j-1))][j-1]);
			fin[i][j]=min(fin[i][j-1],fin[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int STmax(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return max(fax[l][k],fax[r-(1<<k)+1][k]);
}
inline int STmin(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return min(fin[l][k],fin[r-(1<<k)+1][k]);
}
int dfs(int l,int r)
{
	if (l==r) return 0;
	int u=STmax(l,r),v=STmin(l,r);
	u=b[u],v=b[v];
	if ((u==l&&v==r)||(u==r&&v==l)) return 1;
	if (u==l||u==r)
	{
		return dfs(l,v)+dfs(v,r);
	}
	return dfs(l,u)+dfs(u,r);
}

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]=i;
	STwork();
	if (n==1)
	{
		printf("0\n");
		return;
	}
	int ans=dfs(1,n);
	printf("%d\n",ans);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}