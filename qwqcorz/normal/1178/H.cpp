#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4405;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
namespace Flow
{
	const int N=::N*5;
	const int M=::N*9;
	const int inf=1<<30;
	int n,S,T;
	struct edge
	{
		int to,nxt,w,p;
	}e[M*2];
	int head[N],cnt;
	inline void add_edge(int u,int v,int w,int p)
	{
		e[++cnt].to=v;
		e[cnt].w=w;
		e[cnt].p=p;
		e[cnt].nxt=head[u];
		head[u]=cnt;
		assert(cnt<M*2);
	}
	inline void add(int u,int v,int w,int p)
	{
//		print(u,' '),print(v,' '),print(w,','),print(p);
		add_edge(u,v,w,p);
		add_edge(v,u,0,-p);
	}
//	now,flow,pre,id,pay;
	queue<int>q;
	bool vis[N];
	int pay[N],vFlow[N],vPre[N],vId[N],ans1,ans2;
	inline bool spfa()
	{
		for (int i=0;i<=n;i++) vPre[i]=-1,pay[i]=inf;
		int x=-114514;
		vFlow[S]=inf;
		q.push(S);
		pay[S]=0;
		while (!q.empty())
		{
			int now=q.front(),flow=vFlow[now],p=pay[now];
			vis[now]=0;
			q.pop();
			#define to e[i].to
			for (int i=head[now];~i;i=e[i].nxt)
			if (e[i].w&&pay[to]>p+e[i].p&&to!=S)
			{
				pay[to]=p+e[i].p;
				vFlow[to]=min(flow,e[i].w);
				vPre[to]=now;
				vId[to]=i;
				if (!vis[to]) q.push(to),vis[to]=1;
				if (to==T) x=T;
			}
			#undef to
		}
		if (x<0) return 0;
		int f=vFlow[x];
		ans1+=f;
		ans2+=f*pay[x];
		while (~vPre[x])
		{
			e[vId[x]].w-=f;
			e[vId[x]^1].w+=f;
			x=vPre[x];
		}
		return 1;
	}
	inline void send(int _n,int _S,int _T)
	{
		cnt=-1;
		memset(head,-1,sizeof(head));
		n=_n,S=_S,T=_T;
		ans1=ans2=0;
	}
	inline void solve()
	{
		while (spfa());
	}
}
ll mx[N];
int k[N],b[N];
bool check(int n,int t)
{
	vector<int>p;
	for (int i=1;i<=n*2;i++) p.push_back(i);
	sort(p.begin(),p.end(),[&](int x,int y){return b[x]<b[y];});
	for (int i=1;i<=n*2;i++) mx[i]=1LL*k[i]*t+b[i];
	ll tmp=0;
	for (int i=0,j=0;i<n*2;i++)
	{
		tmp=max(tmp,mx[p[i]]);
		if (i+1==n*2||b[p[i]]!=b[p[i+1]]) for (;j<=i;j++) mx[p[j]]=tmp;
	}
	sort(mx+1,mx+n+1,greater<ll>());
	for (int i=n+1;i<=n*2;i++) mx[i]=1LL*k[i]*t+b[i];
	sort(mx+n+1,mx+n*2+1,greater<ll>());
//	if (t==5) for (int i=1;i<=n*2;i++) print(mx[i]);
	for (int i=n+1,j=1,tot=0;i<=n*2;i++)
	{
		while (j<=n&&mx[j]>=mx[i]) j++,tot++;
		if (--tot<0) return 0;
	}
	return 1;
}
ll c[N],d[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n*2;i++) k[i]=read(),b[i]=read();
	int l=0,r=1e9;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(n,mid)) r=mid-1;
					 else l=mid+1;
	}
//	print(check(n,5));
	if (l>(int)1e9) return puts("-1"),0;
	n*=2;
	for (int i=1;i<=n;i++) c[i]=b[i];
	for (int i=1;i<=n;i++) d[i]=1LL*k[i]*l+b[i];
	sort(c+1,c+1+n);
	sort(d+1,d+1+n);
	int cnt1=unique(c+1,c+1+n)-c-1;
	int cnt2=unique(d+1,d+1+n)-d-1;
	int S=0,T=n*3+cnt1+cnt2+1;
	Flow::send(T,S,T);
	for (int i=1;i<=n/2;i++) Flow::add(S,i,1,0);
	for (int i=n/2+1;i<=n;i++) Flow::add(n*2+cnt1+cnt2+i,T,1,0);
	for (int i=1;i<=n;i++) Flow::add(i,n+cnt1+i,n,0);
	for (int i=1;i<=n;i++) Flow::add(n+cnt1+i,n*2+cnt1+cnt2+i,n,0);
	for (int i=2;i<=cnt1;i++) Flow::add(n+i,n+i-1,n,0);
	for (int i=2;i<=cnt2;i++) Flow::add(n*2+cnt1+i,n*2+cnt1+i-1,n,0);
	for (int i=1;i<=n;i++)
	{
		int x=lower_bound(c+1,c+1+cnt1,b[i])-c;
		Flow::add(i,n+x,n,0);
		Flow::add(n+x,n+cnt1+i,n,1);
	}
	for (int i=1;i<=n;i++)
	{
		int x=lower_bound(d+1,d+1+cnt2,1LL*k[i]*l+b[i])-d;
		Flow::add(n+cnt1+i,n*2+cnt1+x,n,0);
		Flow::add(n*2+cnt1+x,n*2+cnt1+cnt2+i,n,1);
	}
	Flow::solve();
	assert(Flow::ans1==n/2);
	print(l,' '),print(Flow::ans2);
	
	return 0;
}