#include<bits/stdc++.h>
#define sz 200020
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
int deg[sz];
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
	deg[f]++;deg[t]++;
}
#define go(x) for (int k=head[x];k;k=edge[k].nxt)
#define o edge[k].t
int n,K;
int dep[sz];
bool in[sz];
int vis[sz][25];
int main()
{
	file();
	int i,j,k,x,y,z,sum=0;
	read>>n>>K;if (n<4) return puts("No"),0;
	for (i=1;i<n;i++) read>>x>>y,make_edge(x,y);
	for (i=1;i<=n;i++) if (deg[i]==1){deg[i]=0;vis[i][1]=1;++sum;}
	for (i=2;i<=K+1;i++)
	{
		for (j=1;j<=n;j++) if (vis[j][i-1])
		{
			go(j) if (!vis[o][i-2])
			{
				if (vis[o][i-1]) return puts("No"),0;
				vis[o][i]++;
			}
		}
		for (j=1;j<=n;j++) 
			if (vis[j][i]==1||vis[j][i]==2) return puts("No"),0;
			else if (vis[j][i]) ++sum;
		if (sum==n&&i!=K+1) return puts("No"),0;
	}
	if (sum!=n) return puts("No"),0;
	x=0;
	for (i=1;i<=n;i++) if (vis[i][K+1]) ++x;
	if (x!=1) return puts("No"),0;
	puts("Yes");
}