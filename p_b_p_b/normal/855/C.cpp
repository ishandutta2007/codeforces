#include<bits/stdc++.h>
#define sz 100010
#define mod (int)(1e9+7)
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
int n,m,X,K;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}
#define go(x) for (int _=head[x];_;_=edge[_].nxt)
#define o edge[_].t
ll dp[sz][12][3];//<,=,>
int size[sz];
ll t[12][3];
void dfs(int x,int fa)
{
	dp[x][0][0]=K-1,dp[x][1][1]=1,dp[x][0][2]=m-K;
	size[x]=1;
	int i,j,k;
	go(x) if (o!=fa)
	{
		dfs(o,x);
		memset(t,0,sizeof(t));
		for (i=0;i<=size[x]&&i<=X;i++)
		{
			for (j=0;j<=size[o]&&(k=i+j)<=X;j++)
			{
				(t[k][0]+=dp[x][i][0]*((dp[o][j][0]+dp[o][j][1]+dp[o][j][2])%mod)%mod)%=mod;
				if (i) (t[k][1]+=dp[x][i][1]*dp[o][j][0])%=mod;
				(t[k][2]+=dp[x][i][2]*((dp[o][j][0]+dp[o][j][2])%mod)%mod)%=mod;
			}
		}
		size[x]+=size[o];
		for (i=0;i<=size[x]&&i<=X;i++)
			for (j=0;j<3;j++)
				dp[x][i][j]=t[i][j];
	}
}
int main()
{
	file();
	int i,j,k,x,y,z;
	read>>n>>m;
	for (i=1;i<n;i++) read>>x>>y,make_edge(x,y);
	read>>K>>X;
	dfs(1,0);
	ll ans=0;
	for (i=0;i<=X;i++) 
		for (j=0;j<3;j++)
			(ans+=dp[1][i][j])%=mod;
	cout<<ans;
}