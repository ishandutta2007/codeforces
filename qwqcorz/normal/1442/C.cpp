#include<bits/stdc++.h>
#define mk make_pair
#define x first
#define y second
#define int long long
using namespace std;
const int N=2e5+5;
const int p=998244353;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
struct edge
{
	bool f;
	int to,nxt;
}e[N*2];
int head[N],cnt=0;
void add(int u,int v,bool w)
{
	e[++cnt].f=w;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int n,m,tim[N],dis[N][20];
deque<int>dq;
void bfs0()
{
	memset(tim,0x3f,sizeof(tim));
	dq.clear();
	tim[1]=0;
	dq.push_back(1);
	while (!dq.empty())
	{
		int now=dq.front();
		dq.pop_front();
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to,f=e[i].f^(tim[now]&1);
			if (f)
			{
				if (tim[to]>tim[now]+1)
				{
					tim[to]=tim[now]+1;
					dq.push_back(to);
				}
			}
			else
			{
				if (tim[to]>tim[now])
				{
					tim[to]=tim[now];
					dq.push_front(to);
				}
			}
		}
	}
}
queue<pair<int,int> >q;
void bfs1()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1][0]=0;
	q.push(mk(1,0));
	while (!q.empty())
	{
		pair<int,int>now=q.front();
//		print(now.x,':');print(now.y);
		q.pop();
		for (int i=head[now.x];i;i=e[i].nxt)
		{
			int to=e[i].to,f=e[i].f^(now.y&1);
			if (now.y+f-tim[to]>=20) continue;
//			print(to,' ');print(dis[now.x][now.y-tim[now.x]]);
			if (dis[to][now.y+f-tim[to]]>dis[now.x][now.y-tim[now.x]]+1)
			{
				dis[to][now.y+f-tim[to]]=dis[now.x][now.y-tim[now.x]]+1;
				q.push(mk(to,now.y+f));
			}
		}
	}
}
struct answer
{
	int k,val;
	bool operator <(const answer &a)const
	{
		if (max(k,a.k)>20) return k<a.k;
		return (1<<k)+val<(1<<a.k)+a.val;
	}
}ans({1919810,0});

signed main()
{
	n=read();
	m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v,0);
		add(v,u,1);
	}
	bfs0();
	bfs1();
//	for (int i=1;i<=n;i++) print(tim[i]);
//	for (int i=1;i<=n;i++,puts(""))
//	for (int j=0;j<=n;j++) print(dis[i][j],' ');
//	for (int i=0;i<20;i++) print(tim[n]+i,' '),print(dis[n][i]);
	for (int i=0;i<20;i++) ans=min(ans,(answer){tim[n]+i,dis[n][i]});
//	print(ans.k,',');
//	print(ans.val);
	print((power(2,ans.k)-1+ans.val)%p);

	return 0;
}