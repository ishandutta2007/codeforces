#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int inf=1e18;
const int M=1e5+10;
int n,sz[M],ans,col[M],rt,dfn[M],sum[M],p[M],tt[M],ti;
vector<pair<int,int> >e[M];

void dfs1(int u,int fa)
{
	sz[u]=1;int maxn=0;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;
		if (to==fa)continue;dfs1(to,u);
		ans+=2*w*min(sz[to],n-sz[to]),
		sz[u]+=sz[to],maxn=max(maxn,sz[to]);
	}maxn=max(maxn,n-sz[u]);
	if (maxn<=n/2)rt=u;
}

void dfs2(int u,int fa,int c)
{
	col[u]=c;dfn[u]=++ti,tt[ti]=u,sz[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x;if (to==fa)continue;
		dfs2(to,u,fa==0?to:c);sz[u]+=sz[to];
	}
}

struct segment_tree// min max 
{
	struct tree
	{
		int tl,tr,minn,maxn;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define minn(x) t[(x)].minn
	#define maxn(x) t[(x)].maxn
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		maxn(k)=max(maxn(lson),maxn(rson)),
		minn(k)=min(minn(lson),minn(rson));
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){maxn(k)=sum[l],minn(k)=tt[l];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update1(int k,int l,int z)
	{
		if (l(k)>l||r(k)<l)return;
		if (l(k)==l&&r(k)==l){maxn(k)=z;return;}
		update1(lson,l,z),update1(rson,l,z);
		pushup(k);
	}
	void update2(int k,int l,int z)
	{
		if (l(k)>l||r(k)<l)return;
		if (l(k)==l&&r(k)==l){minn(k)=z;return;}
		update2(lson,l,z),update2(rson,l,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return minn(k);
		if (l(k)>r||r(k)<l)return inf;
		return min(query(lson,l,r),query(rson,l,r)); 
	}
}T;

void del(int x)
{
	T.update2(1,dfn[x],inf);
	T.update1(1,col[x],sum[col[x]]-1);
	sum[col[x]]--;
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].pb(mp(v,w)),e[v].pb(mp(u,w));
	}dfs1(1,0);dfs2(rt,0,rt);
	cout<<ans<<endl;int f=-1; 
	for (int i=1;i<=n;i++)sum[col[i]]+=2;
	for (int i=1;i<=n;i++)sum[rt]-=2;
	T.build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		if (T.t[1].maxn==(n-i+1)) 
		{
			if (f==-1)
			{
				for (int j=1;j<=n;j++)
					if (sum[j]==n-i+1)f=j;
			}
			int L,R;
			if (f==rt)L=R=1;
			else L=dfn[f],R=dfn[f]+sz[f]-1;
			if (col[i]==f)
			{
				int minn=min(T.query(1,1,L-1),T.query(1,R+1,n));
				cout<<minn<<' ';del(minn);assert(minn!=inf);
			}
			else
			{
				int minn=T.query(1,L,R);
				cout<<minn<<' ';del(minn);assert(minn!=inf);
			}
		}
		else
		{
			int f=col[i];int L,R;
			if (f==rt)L=R=0;
			else L=dfn[f],R=dfn[f]+sz[f]-1;
			int minn=min(T.query(1,1,L-1),T.query(1,R+1,n));
//			cout<<T.query(1,R+1,n);
			cout<<minn<<' ';del(minn);assert(minn!=inf);
		}
		T.update1(1,col[i],sum[col[i]]-1);
		sum[col[i]]--;
	}
//	for (int i=1;i<=n;i++)p[i]=read();
	return 0;
}
//*3100 /no  
// WA 