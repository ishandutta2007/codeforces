#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define sz 505050
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
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m,K,Q;
struct hh{int u,v,col;}edge[sz];
int id[sz],las[sz],L[sz],R[sz],pre[sz],col[sz];

struct hhhh{int x,y,col;bool s;};

struct hhh
{
	int fa[sz],f[sz],dep[sz];
	int getfa(int x){return x==fa[x]?x:getfa(fa[x]);}
	int getdis(int x){return x==fa[x]?0:f[x]^getdis(fa[x]);}
	void cancel(hhhh a){f[fa[a.x]=a.x]=0;dep[a.y]-=a.s;}
	bool connected(int x,int y){return getfa(x)==getfa(y);}
	hhhh merge(int x,int y,int col)
	{
		int fx=getfa(x),fy=getfa(y);
		if (dep[fx]>dep[fy]) swap(fx,fy),swap(x,y);
		int w=getdis(x)^getdis(y)^1;
		hhhh ret=(hhhh){fx,fy,col,0};
		f[fx]=w;fa[fx]=fy;
		if (dep[fx]==dep[fy]) ++dep[fy],ret.s=1;
		return ret;
	}
}G[55];
void cancel(stack<hhhh>S){while (!S.empty()) G[S.top().col].cancel(S.top()),S.pop();}

vector<int>v[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void insert(int k,int l,int r,int x,int y,int e)
{
	if (x<=l&&r<=y) return (void)(v[k].push_back(e));
	int mid=(l+r)>>1;
	if (x<=mid) insert(lson,x,y,e);
	if (y>mid) insert(rson,x,y,e);
}
void solve(int k,int l,int r)
{
	stack<hhhh>S;
	rep(i,0,(int)v[k].size()-1) 
	{
		hh e=edge[v[k][i]];
		if (!e.col) continue;
		int x=e.u,y=e.v,col=e.col;
		if (G[col].connected(x,y)) continue;
		S.push(G[col].merge(x,y,col));
	}
	if (l==r)
	{
		hh e=edge[id[l]];
		int w=G[col[l]].getdis(e.u)^G[col[l]].getdis(e.v)^1;
		bool t=G[col[l]].connected(e.u,e.v);
		cancel(S);
		if (!t||!w) return (void)(puts("YES"),edge[id[l]].col=col[l]);
		return (void)puts("NO");
	}
	int mid=(l+r)>>1;
	solve(lson);solve(rson);
	cancel(S);
}

int main()
{
	file();
	int x,y;
	read(n,m,K,Q);
	rep(i,1,K) rep(j,1,n) G[i].fa[j]=j;
	rep(i,1,m) read(x,y),edge[i]=(hh){x,y,0}; 
	rep(i,1,Q)
	{
		read(x,y);
		id[i]=x;col[i]=y;
		if (las[x]) R[las[x]]=i-1;
		pre[i]=las[x];las[x]=i;
		L[i]=i+1,R[i]=Q;
	}
	rep(i,1,Q) if (L[i]<=R[i]) insert(1,1,Q,L[i],R[i],id[i]);
	solve(1,1,Q);
	return 0;
}