#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define MAXN 300030
	#define MAXM 300030 
	#define mod 998244353
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=x;i<=y;i++)
	#define drep(i,x,y) for (int i=x;i>=y;i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	typedef long long ll;
    template<typename T>
    inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.')
        {
            ch=getchar();
            while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
        }
        t=(f?-t:t);
    }
    template<typename T,typename... Args>
    inline void read(T& t,Args&... args){read(t); read(args...);}
	void file()
	{
		#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
		#endif
	}
	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;
int n;
struct hh{int t,nxt;}edge[MAXM<<1];
int head[MAXN],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}
ll maxv;
ll dp1[MAXN],dp2[MAXN];
bool w[MAXN];
ll val[MAXN];
#define v edge[i].t
void dfs1(int x,int fa)
{
	dp1[x]=val[x];
	go(x) if (v!=fa) {dfs1(v,x);dp1[x]+=max(dp1[v],0ll);}
}
void dfs2(int x,int fa)
{
	dp2[x]=val[x];
	go(x) if (v!=fa){dfs2(v,x);dp2[x]+=max(dp2[v],0ll);}
	if (dp2[x]==maxv) dp2[x]=0,w[x]=1;
}
int main()
{
	file();
	int i,j,k,x,y,z;
	read(n);
	rep(i,1,n) read(val[i]);
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs1(1,0);
	maxv=INT_MIN;
	rep(i,1,n) maxv=max(maxv,dp1[i]);
	dfs2(1,0);
	int ans=0;
	rep(i,1,n) ans+=w[i];
	printf("%I64d %d",maxv*ans,ans);
}
struct note{
//did you check the size?
//do you need twice size?
//did you use long long?
//is the mod correct?
//did you initialize your program?
//did you save your program?
//is this the latest version?
//print '\n' or ' '?
//enough '(',')'?
};