#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=2e3+10;
const int N=1e6+10;
int n,cnt1,cnt2,s1,s2,vis[M];
pii p[M];
pair<pii,pii>p1[M],p2[M],ans1[M],ans2[M];

int de[M],cur[M];
struct edge{int to,next,w;}e[N<<1];int cnt=1,head[M];
void add(int u,int to,int w){e[++cnt].to=to,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;}
void adde(int u,int to,int w){add(u,to,w),add(to,u,0);}

int bfs(int s,int t)
{
	memset(de,0,sizeof(de));
	memcpy(cur,head,sizeof(cur));
	queue<int>q;q.push(s),de[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=head[u];i;i=e[i].next)
		{
			int to=e[i].to;
			if (de[to]||!e[i].w)continue;
			de[to]=de[u]+1,q.push(to);
		}
	}
	return de[t]!=0;
}

int dfs(int s,int t,int now)
{
	if (s==t)return now;int res=0;
	for (int i=cur[s];i;i=e[i].next)
	{
		int to=e[i].to;cur[s]=i;
		if (de[to]!=de[s]+1)continue;
		int x=dfs(to,t,min(now,e[i].w));
		res+=x,now-=x,e[i].w-=x,e[i^1].w+=x;
		if (now==0)break;
	}return res;
}

int dinic(int s,int t)
{
	int res=0;
	while(bfs(s,t))res+=dfs(s,t,inf);
	return res;
}

bool cmp1(pii a,pii b){return a.x<b.x||((a.x==b.x)&&(a.y<b.y));}
bool cmp2(pii a,pii b){return a.y<b.y||((a.y==b.y)&&(a.x<b.x));}

void dfs(int u)
{
	if (u>cnt1+cnt2)return;
	if (u>cnt1)
	{
		if (!vis[u])return;
		else vis[u]=0;
	}
	else
	{
		if (vis[u])return;
		else vis[u]=1;
	}
	for (int i=head[u];i;i=e[i].next)
		if (e[i].w==0)dfs(e[i].to);
}

signed main()
{
	s1=s2=n=read();
	for (int i=1;i<=n;i++)p[i].x=read(),p[i].y=read();
	for (int i=1;i<=n;i++)ans1[i]=ans2[i]=mp(p[i],p[i]);
	sort(p+1,p+1+n,cmp1);int l=1;
	for (int i=1;i<=n;i++)
	{
		if (i!=n&&p[i].x==p[i+1].x)continue;
		for (int j=l;j<i;j++)
			p1[++cnt1]=mp(p[j],p[j+1]);
		l=i+1;
	}
	sort(p+1,p+1+n,cmp2);l=1;
	for (int i=1;i<=n;i++)
	{
		if (i!=n&&p[i].y==p[i+1].y)continue;
		for (int j=l;j<i;j++)
			p2[++cnt2]=mp(p[j],p[j+1]);
		l=i+1;
	}int s=cnt1+cnt2+1,t=s+1;
	for (int i=1;i<=cnt1;i++)adde(s,i,1);
	for (int i=1;i<=cnt2;i++)adde(i+cnt1,t,1);
	for (int i=1;i<=cnt1;i++)
		for (int j=1;j<=cnt2;j++)
			if (p1[i].x.y<p2[j].x.y&&p1[i].y.y>p2[j].x.y&&p2[j].x.x<p1[i].x.x&&p2[j].y.x>p1[i].x.x)
				adde(i,j+cnt1,1);//,cout<<i<<' '<<j<<'\n';
	int res=2*n+dinic(s,t)-cnt1-cnt2; 
//	cout<<res<<'\n'; 
	for (int i=1;i<=cnt2;i++)vis[i+cnt1]=1;
	for (int i=head[t];i;i=e[i].next)
		if (!e[i].w)dfs(e[i].to);
//	for (int i=1;i<=cnt1+cnt2;i++)cout<<vis[i]<<' '; 
	for (int i=1;i<=cnt1;i++)
	{
		if (vis[i])continue;
		int ps1=-1,ps2=-1;
		for (int j=1;j<=s1;j++)
		{
			if (ans1[j].x.x==p1[i].x.x&&ans1[j].y.y==p1[i].x.y)ps1=j;
			if (ans1[j].x.x==p1[i].x.x&&ans1[j].x.y==p1[i].y.y)ps2=j;
		}
		assert(ps1!=-1&&ps2!=-1);
		pair<pii,pii>qwq=mp(mp(p1[i].x.x,ans1[ps1].x.y),mp(p1[i].x.x,ans1[ps2].y.y));
		if (ps1>ps2)swap(ps1,ps2);
		for (int j=ps1+1;j<ps2;j++)ans1[j-1]=ans1[j];
		for (int j=ps2+1;j<=s1;j++)ans1[j-2]=ans1[j];
		ans1[--s1]=qwq;
	}
	for (int i=1;i<=cnt2;i++)
	{
		if (vis[i+cnt1])continue;
		int ps1=-1,ps2=-1;
		for (int j=1;j<=s2;j++)
		{
			if (ans2[j].x.y==p2[i].x.y&&ans2[j].y.x==p2[i].x.x)ps1=j;
			if (ans2[j].x.y==p2[i].x.y&&ans2[j].x.x==p2[i].y.x)ps2=j;
		}
		assert(ps1!=-1&&ps2!=-1);
		pair<pii,pii>qwq=mp(mp(ans2[ps1].x.x,p2[i].x.y),mp(ans2[ps2].y.x,p2[i].x.y));
		if (ps1>ps2)swap(ps1,ps2);
		for (int j=ps1+1;j<ps2;j++)ans2[j-1]=ans2[j];
		for (int j=ps2+1;j<=s2;j++)ans2[j-2]=ans2[j];
		ans2[--s2]=qwq;
	}
	assert(res==s1+s2);
	cout<<s2<<'\n';
	for (int i=1;i<=s2;i++)
		cout<<ans2[i].x.x<<' '<<ans2[i].x.y<<' '<<ans2[i].y.x<<' '<<ans2[i].y.y<<'\n';
	cout<<s1<<'\n';
	for (int i=1;i<=s1;i++)
		cout<<ans1[i].x.x<<' '<<ans1[i].x.y<<' '<<ans1[i].y.x<<' '<<ans1[i].y.y<<'\n';
	return 0;
}