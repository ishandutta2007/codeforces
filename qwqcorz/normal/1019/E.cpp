#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct point
{
	int x,y;
	bool operator <(const point &a)const
	{
		return x==a.x?y<a.y:x<a.x;
	}
	point operator +(point a){return (point){x+a.x,y+a.y};}
	point operator -(point a){return (point){x-a.x,y-a.y};}
};
int cross(point a,point b)
{
	auto ret=(__int128)(a.x)*b.y-(__int128)(a.y)*b.x;
	if (ret>0) return 1;
	if (ret==0) return 0;
	if (ret<0) return -1;
}
int cnt,cnte=0;
bool del[N];
struct edge{int to,a,b,id;};
vector<edge>t[N],e[N];
void add_edge(int u,int v,int a,int b)
{
	cnte++;
	e[u].push_back((edge){v,a,b,cnte});
	e[v].push_back((edge){u,a,b,cnte});
}
void dfs0(int now,int father)
{
	vector<edge>son;
	for (edge i:t[now])
	{
		int to=i.to;
		if (to==father) continue;
		dfs0(to,now);
		son.push_back(i);
	}
	if (son.empty()) return;
	add_edge(now,son[0].to,son[0].a,son[0].b);
	if (son.size()==1) return;
	int lst=now;
	for (int i=1;i+1<(int)son.size();i++)
	{
		cnt++;
		add_edge(lst,cnt,0,0);
		add_edge(cnt,son[i].to,son[i].a,son[i].b);
		lst=cnt;
	}
	add_edge(lst,son.back().to,son.back().a,son.back().b);
}
int u,v,w,siz[N],id,a,b;
void find(int now,int father,int tot)
{
	siz[now]=1;
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||del[i.id]) continue;
		find(to,now,tot);
		siz[now]+=siz[to];
		if (abs(siz[to]*2-tot)<w)
		{
			w=abs(siz[to]*2-tot);
			u=to,v=now,id=i.id,a=i.a,b=i.b;
		}
	}
}
void dfs(vector<point>&p,int now,int father,int a,int b)
{
	p.push_back((point){a,b});
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||del[i.id]) continue;
		dfs(p,to,now,a+i.a,b+i.b);
	}
}
vector<point>zyk(vector<point>a)
{
	sort(a.begin(),a.end());
	int top=-1;
	static point st[N];
	for (point i:a)
	{
		if (top>=0&&!i.x&&!i.y) continue;
		while (top>0&&cross(st[top]-st[top-1],i-st[top-1])>=0) top--;
		st[++top]=i;
	}
	vector<point>ret(top+1);
	for (int i=0;i<=top;i++) ret[i]=st[i];
	return ret;
}
vector<point>merge(vector<point>a,vector<point>b)
{
	int n=a.size(),m=b.size();
	for (int i=n-1;i>=1;i--) a[i]=a[i]-a[i-1];
	for (int i=m-1;i>=1;i--) b[i]=b[i]-b[i-1];
	vector<point>ret;
	int i=0,j=0;
	while (i<n&&!a[i].x&&!a[i].y) i++;
	while (j<m&&!b[j].x&&!b[j].y) j++;
	while (i<n&&j<m)
	if (cross(a[i],b[j])<0) ret.push_back(a[i++]);
					   else ret.push_back(b[j++]);
	while (i<n) ret.push_back(a[i++]);
	while (j<m) ret.push_back(b[j++]);
	for (int i=1;i<(int)ret.size();i++) ret[i]=ret[i-1]+ret[i];
	return ret;
}
vector<point>p;
void bfz(int now,int tot)
{
	if (tot==1) return;
	w=tot,find(now,0,tot),del[id]=1;
	vector<point>A,B({(point){0,0}});
	dfs(A,u,v,0,0),dfs(B,v,u,a,b);
	auto C=merge(zyk(A),zyk(B));
	for (auto i:C) p.push_back(i);
	int su=siz[u],sv=tot-su,uu=u,vv=v;
	bfz(uu,su),bfz(vv,sv);
}

signed main()
{
	int n=cnt=read(),m=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),a=read(),b=read();
		t[u].push_back((edge){v,a,b,0});
		t[v].push_back((edge){u,a,b,0});
	}
	dfs0(1,0);
	bfz(1,cnt);
	p.push_back((point){0,0});
	p=zyk(p);
	int s=p.size();
	for (int i=0,j=0;i<m;i++)
	{
		while (j+1<s&&i*p[j].x+p[j].y<=i*p[j+1].x+p[j+1].y) j++;
		print(i*p[j].x+p[j].y," \n"[i+1==m]);
	}
	
	return 0;
}