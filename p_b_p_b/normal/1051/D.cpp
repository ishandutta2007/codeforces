#include<bits/stdc++.h>
#define sz 1010
#define mod 998244353ll
using namespace std;
typedef long long ll;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
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
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n,K;
ll dp[sz][sz<<1][4];
/*
0: W W
1: W B
2: B W
3: B B
*/
int main()
{
	file();
	int i,j,k,x,y,z;
	read>>n>>K;
	dp[1][1][0]=dp[1][1][3]=1;dp[1][2][1]=dp[1][2][2]=1;
	for (i=2;i<=n;i++)
	{
		for (j=1;j<=K&&j<=i*2;j++)
		{
			for (k=0;k<4;k++)
			{
//				for (t=0;t<=1;t++)
//				{
					dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]
								+dp[i-1][j-1][3];
					dp[i][j][1]+=dp[i-1][j][1]
								+dp[i-1][j-1][0]+dp[i-1][j-1][3]
								+dp[i-1][j-2][2];
					dp[i][j][2]+=dp[i-1][j][2]
								+dp[i-1][j-1][0]+dp[i-1][j-1][3]
								+dp[i-1][j-2][1];
					dp[i][j][3]+=dp[i-1][j][3]+dp[i-1][j][1]+dp[i-1][j][2]
								+dp[i-1][j-1][0];
//				}
				for (k=0;k<3;k++) dp[i][j][k]%=mod;
			}
		}
	}
	ll ans=0;
	for (k=0;k<4;k++) (ans+=dp[n][K][k])%=mod;
	cout<<ans;
}