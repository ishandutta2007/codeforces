#include<bits/stdc++.h>

#define N 6000010
using namespace std;
int n,m,S,T,tmp1,tmp2,tot;
int en=1,head[N],h[N],q[N],ans1[N],ans2[N];
struct Edge{
    int to,next,v;
}e[N];
bool b[N];
inline void insert(int u,int v,int f)
{
    e[++en].to=v;e[en].v=f;e[en].next=head[u];head[u]=en;
    e[++en].to=u;e[en].v=0;e[en].next=head[v];head[v]=en;
}
inline bool bfs()
{
    int f=0,t=0;
    memset(h,-1,sizeof(h));
    q[t++]=S;h[S]=0;
    while(f<t)
    {
        int now=q[f++];
        for(int i=head[now];i;i=e[i].next)
        {
            int v=e[i].to;
            if(h[v]==-1&&e[i].v)
            {
                h[v]=h[now]+1;
                q[t++]=v;
            }
        }
    }
    if(h[T]!=-1)return 1;
    return 0;
}
inline int dfs(int x,int f)
{
    if(x==T)return f;
    int w,used=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(h[v]==h[x]+1&&e[i].v)
        {
            w=dfs(v,min(f-used,e[i].v));
            e[i].v-=w;
            e[i^1].v+=w;
            used+=w;
            if(used==f)return f;
        }
    }
    if(!used)h[x]=-1;
    return used;
}
void dinic()
{
    while(bfs())
        tot+=dfs(S,0x3f3f3f3f);
}
int c=0,a[N];

map<int,vector<int> >pos;

map<int,int>cnt;

vector<pair<int,int> >ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		if(a[i]*2>m)
		{
			puts("-1");
			return 0;
		}
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	vector<int>L,R;
	for(int i=1;i<=n;i++)
		if(a[i]*3<=m)
			R.push_back(a[i]),pos[a[i]].push_back(R.size());
		else
			L.push_back(a[i]);
	int c=L.size();
	for(int i=0;i<L.size();i++)
	{
		for(int j=1;j*j<=L[i];j++)
		{
			if(L[i]%j!=0)
				continue;
			if(2*L[i]+j<=m)
				for(auto p:pos[j])
					insert(i+1,p+c,1);
			if(j*j!=L[i]&&2*L[i]+L[i]/j<=m)
				for(auto p:pos[L[i]/j])
					insert(i+1,p+c,1);
		}
	}
    S=0,T=n+1;
    for(int i=1;i<=c;i++)insert(S,i,1);
    for(int i=c+1;i<=n;i++)insert(i,T,1);
    dinic();
    if(tot<L.size())
    {
        puts("-1");
        return 0;
    }
    for(int i=2;i<=en;i=i+2)
    {
        if(e[i].to!=S&&e[i^1].to!=S)
        if(e[i].to!=T&&e[i^1].to!=T)
        if(e[i^1].v!=0)
        {
            // printf("%d %d\n",a[e[i^1].to],a[e[i].to]);
			int mx=max(a[e[i^1].to],a[e[i].to]);
			int mn=min(a[e[i^1].to],a[e[i].to]);
			ans.push_back({2*mx+mn,mx+mn});
			cnt[mn]--,cnt[mx]--;
        }
    }
	for(auto [x,y]:cnt)
		if(y)
		{
			for(int j=1;j<=y;j++)
				ans.push_back({x*2,x*3});
		}
	printf("%d\n",ans.size());
	for(auto [x,y]:ans)
		printf("%d %d\n",x,y);
    return 0;
}