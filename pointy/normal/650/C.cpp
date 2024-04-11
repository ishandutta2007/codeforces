#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
struct point
{
	int x,y,z,w;
	bool operator < (const point & o) const
	{
		return w<o.w;
	}
};
vector<point>a[N];
point e[N*2];
point b[N];
int fa[N],tot,d[N];
vector<int>t[N*2],r[N*2];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline int calc(int x,int y)
{
	return (x-1)*m+y;
}
void add(int x,int y)
{
	x=find(x),y=find(y);
	t[x].push_back(y);
	r[y].push_back(x);
	d[y]++;
	//cout << x <<" " <<y<<endl;
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}

void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return;
	fa[x]=y;
}
void work(int tp,int x)
{
	int cnt=0;
	if (tp==0) for (int i=1;i<=m;i++) b[++cnt]=a[x][i];
	else for (int i=1;i<=n;i++) b[++cnt]=a[i][x];
	sort(b+1,b+cnt+1);
	for (int i=2;i<=cnt;i++)
	{
		if (b[i].w==b[i-1].w) merge(b[i].z,b[i-1].z);
		else 
		{
			++tot;
			e[tot].x=b[i-1].z,e[tot].y=b[i].z;
		}
	}
}
int ans[N];
bool vis[N];
queue<int>q;
void ddd(int x)
{
	int u=0;
	for (int i=0;i<r[x].size();i++)
	{
		u=max(u,ans[r[x][i]]);
	}
	ans[x]=u+1;
}
void topo()
{
	for (int i=1;i<=n*m;i++)
	{
		if (find(i)!=i)
		{
			vis[i]=1;
			continue;
		}
		if (d[i]==0) q.push(i);
	}
	while (!q.empty())
	{
		int u=q.front();
		//cout << u << endl;
		q.pop();
		ddd(u);
		for (int i=0;i<t[u].size();i++)
		{
			int v=t[u][i];
			d[v]--;
			if (d[v]==0) q.push(v);
		}
	}
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i].push_back((point){0,0,0,0});
		for (int j=1;j<=m;j++)
		{
			int x=read();
			a[i].push_back((point){i,j,(i-1)*m+j,x});
		}
	}
	for (int i=1;i<=n*m;i++) fa[i]=i;
	for (int i=1;i<=m;i++) work(1,i);
	for (int i=1;i<=n;i++) work(0,i);
	for (int i=1;i<=tot;i++) add(e[i].x,e[i].y);
	topo();
	for (int i=1;i<=n*m;i++)
	{
		printf("%d ",ans[find(i)]);
		if (i%m==0) printf("\n");
	}
	return 0;
}