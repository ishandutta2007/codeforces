#include<bits/stdc++.h>
#define sz 1000020
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO{
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
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
ll a[22][22];
int n,m;
ll K;
#define fir first
#define sec second
#define itr map<ll,ll>::iterator
map<ll,ll>dp[22][22];
bool vis[22][22];
ll dfs(int x,int y,ll cur)
{
	if (vis[x][y]) 
		return dp[x][y][cur];
	ll ret=0;
	if (x!=1) ret+=dfs(x-1,y,cur^a[x][y]);
	if (y!=1) ret+=dfs(x,y-1,cur^a[x][y]);
	return ret;
}
int main()
{
	file();
	int i,j,k,y,z;ll x;
	read>>n>>m>>K;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) read>>a[i][j];
	dp[1][1][a[1][1]]=1;vis[1][1]=1;
	x=a[1][1];
	for (i=2;i<=m;i++) dp[1][i][x^=a[1][i]]=vis[1][i]=1;
	x=a[1][1];
	for (i=2;i<=n;i++) dp[i][1][x^=a[i][1]]=vis[i][1]=1;
	for (int id=4;id<=(n+m)/2;id++)
	{
		for (i=2;i<=n&&i<=id-2;i++)
		{
			j=id-i;
			if (j>m) continue;
			vis[i][j]=1;
			for (itr it=dp[i-1][j].begin();it!=dp[i-1][j].end();it++) 
				dp[i][j][it->fir^a[i][j]]+=it->sec;
			for (itr it=dp[i][j-1].begin();it!=dp[i][j-1].end();it++) 
				dp[i][j][it->fir^a[i][j]]+=it->sec;
		}
	}
	cout<<dfs(n,m,K);
}