#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const string out[2]={"Blue","Red"};
const int inf=1e9+7;
const pair<pair<int,int>,pair<int,int>>null=make_pair(make_pair(inf,0),make_pair(-inf,0));

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
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		pair<int,int>mn,mx;
		node(){mn=null.first,mx=null.second;}
		friend node operator +(const node &a,const node &b)
		{
			node ret;
			ret.mn=min(a.mn,b.mn);
			ret.mx=max(a.mx,b.mx);
			return ret;
		}
		void operator =(const pair<pair<int,int>,pair<int,int>>x)
		{
			mn=x.first;
			mx=x.second;
		}
	}t[N*4];
	set<pair<int,int>>s[N];
	void change(int w,int l,int r,int x,pair<pair<int,int>,pair<int,int>>y)
	{
		if (l==r) return t[w]=y;
		if (x<=mid) change(ls,l,mid,x,y);
			   else change(rs,mid+1,r,x,y);
		t[w]=t[ls]+t[rs];
	}
	node query(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w];
		if (qr<=mid) return query(ls,l,mid,ql,qr);
		if (ql>mid) return query(rs,mid+1,r,ql,qr);
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	#undef mid
	#undef rs
	#undef ls
}t[2];
bool vis[2][N];
vector<int>e[2][N],q[2];
int st[2][N],ed[2][N],cnt[2],fa[2][N],ndfn[2][N],n,x;
void dfs(int p,int now)
{
	ndfn[p][st[p][now]=++cnt[p]]=now;
	for (int to:e[p][now]) dfs(p,to);
	ed[p][now]=cnt[p];
}
void add(int p,int i)
{
	int x=i,y=fa[p][i];
	for (int T=0;T<=1;T++,swap(x,y))
	{
		pair<pair<int,int>,pair<int,int>>tmp;
		t[!p].s[st[!p][x]].insert(make_pair(st[!p][y],i));
		tmp.first=(*t[!p].s[st[!p][x]].begin());
		tmp.second=(*t[!p].s[st[!p][x]].rbegin());
		t[!p].change(1,1,n,st[!p][x],tmp);
	}
}
void erase(int p,int i)
{
	int x=i,y=fa[p][i];
	for (int T=0;T<=1;T++,swap(x,y))
	{
		pair<pair<int,int>,pair<int,int>>tmp;
		t[!p].s[st[!p][x]].erase(make_pair(st[!p][y],i));
		if (t[!p].s[st[!p][x]].empty()) tmp=null;
		else
			tmp.first=*(t[!p].s[st[!p][x]].begin()),
			tmp.second=*(t[!p].s[st[!p][x]].rbegin());
		t[!p].change(1,1,n,st[!p][x],tmp);
	}
}

signed main()
{
	n=read();
	for (int j=0;j<=1;j++)
	for (int i=2;i<=n;i++) e[j][fa[j][i]=read()].push_back(i);
	q[0].push_back(x=read()+1);
	vis[0][x]=1;
	dfs(0,1),dfs(1,1);
	for (int j=0;j<=1;j++)
	for (int i=2;i<=n;i++) if (!vis[j][i]) add(j,i);
	for (int p=0;;p^=1)
	{
		sort(q[p].begin(),q[p].end());
		puts(out[p].c_str());
		for (int i:q[p]) print(i-1,' ');
		puts("");
		for (int i:q[p])
		while ("myhmd")
		{
			auto tmp=t[p].query(1,1,n,st[p][i],ed[p][i]);
			auto mn=tmp.mn,mx=tmp.mx;
			bool flag=0;
			if (mn.second&&mn.first<st[p][i])
			{
				flag=1;
				erase(!p,mn.second);
				q[!p].push_back(mn.second);
			}
			if (mx.second&&mx.first>ed[p][i])
			{
				flag=1;
				erase(!p,mx.second);
				q[!p].push_back(mx.second);
			}
			if (!flag) break;
		}
		if (q[!p].empty()) break;
		q[p].clear();
	}
	
	return 0;
}