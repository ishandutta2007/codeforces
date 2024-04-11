#include<bits/stdc++.h>
#define sz 100010
using namespace std;
int num[sz],cnt[sz];
typedef long long ll;
ll dp[666][6666];
int h[6666];
inline int read()
{
    register int ret=0;
    register char ch=getchar();
    while (ch>'9'||ch<'0') ch=getchar();
    while (ch<='9'&&ch>='0') ret=ret*10+ch-48,ch=getchar();
    return ret;
}
int main()
{
    int i,j,k,x,y,z,n,m;
    ll ans=0;
    n=read(),m=read();
    for (i=1;i<=n*m;i++) num[read()]++;
    for (i=1;i<=n;i++) cnt[read()]++;
    for (i=1;i<=m;i++) h[i]=read();
    for (j=1;j<=n*m;j++)
    {
    	dp[1][j]=h[min(m,j)];
		for (i=2;i<=n;i++)
            for (k=0;k<=m&&k<=j;k++)
                dp[i][j]=max(dp[i][j],dp[i-1][j-k]+h[k]);
    }
    for (i=1;i<=100000;i++) ans+=dp[cnt[i]][num[i]];
    cout<<ans; 
}