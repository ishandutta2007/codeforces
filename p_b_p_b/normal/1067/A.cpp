#include<bits/stdc++.h>
#define sz 100020
#define mod 998244353
using namespace std;
typedef long long ll;
#define int ll
struct FastIO
{
    inline FastIO& operator>>(int& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    #ifndef int
    inline FastIO& operator>>(ll& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    #endif
    inline FastIO& operator>>(double& x)
    {
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
            while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file()
{
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
ll dp[2][233][2];
ll sum[2][233][2];
int a[sz];
int n;
void getsum(int n)
{
	for (int k=0;k<2;k++)
		for (int i=1;i<=200;i++)
			(sum[n][i][k]=sum[n][i-1][k]+dp[n][i][k])%=mod;
}
signed main()
{
	file();
	int i;
	read>>n;
	for (i=1;i<=n;i++) read>>a[i];
	if (a[1]==-1)
		for (i=1;i<=200;i++) 
			dp[1][i][0]=1;
	else dp[1][a[1]][0]=1;
	getsum(1);
	for (i=2;i<=n;i++)
	{
		int c=i&1,cc=c^1;
		memset(dp[c],0,sizeof(dp[c]));
		if (a[i]!=-1)
		{
			dp[c][a[i]][0]=(sum[cc][a[i]-1][0]+sum[cc][a[i]-1][1])%mod;
			dp[c][a[i]][1]=(sum[cc][200][1]-sum[cc][a[i]-1][1])%mod;
			(dp[c][a[i]][1]+=dp[cc][a[i]][0])%=mod;
		}
		else for (a[i]=1;a[i]<=200;a[i]++)
		{
			dp[c][a[i]][0]=(sum[cc][a[i]-1][0]+sum[cc][a[i]-1][1])%mod;
			dp[c][a[i]][1]=(sum[cc][200][1]-sum[cc][a[i]-1][1])%mod;
			(dp[c][a[i]][1]+=dp[cc][a[i]][0])%=mod;
		}
		getsum(c);
	}
	ll ans=sum[n&1][200][1];
	cout<<(ans%mod+mod)%mod;
}