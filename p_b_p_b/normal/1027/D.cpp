#include<bits/stdc++.h>
using namespace std;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(long long& x)
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
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1;
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
#define sz 401010
int c[sz],go[sz];
int n;
int rd[sz];
int tag[sz];
void topo()
{
	int i,x,o;
	queue<int>q;
	for (i=1;i<=n;i++) if (!rd[i]) q.push(i);
	while (!q.empty())
	{
		x=q.front();q.pop();
		o=go[x];rd[o]--;
		if (!rd[o]) q.push(o);
	}
	for (i=1;i<=n;i++) if (!tag[i])
	{
		o=c[i];
		if (rd[i])
			for (x=go[i];x!=i;x=go[x]) 
				o=min(o,c[x]),tag[x]=i;
		c[i]=o;
	}
}
//int dp[sz],mc[sz];
//struct hh{int t,nxt;}edge[sz<<1];
//int head[sz],cnt;
//void make_edge(int f,int t){edge[++cnt]=(hh){t,head[f]};head[f]=cnt;}
//int dfs(int x,int fa,int mv)
//{
//	int ret=0;
//	for (int i=head[x];i;i=edge[i].nxt)
//	{
//		int o=edge[i].t;
//		
//	}
//}
int main()
{
	read>>n;
	int i,j,k,x=0,y,z;
	for (i=1;i<=n;i++) read>>c[i];
	for (i=1;i<=n;i++) read>>go[i],rd[go[i]]++;
	topo();
//	for (i=1;i<=n;i++) 
//		if (!tag[i]&&go[i]!=i) 
//			make_edge(tag[go[i]]?tag[go[i]]:go[i],i);
	for (i=1;i<=n;i++) 
		if (!tag[i]&&(go[i]==i||tag[go[i]]==i))
			x+=c[i];
	cout<<x;
}