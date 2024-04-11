#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
/**********/
#define MAXN 200011
struct node{int ls,rs;}t[MAXN*80];
int root[MAXN],n,cnt=0;
#define rt t[num]
void insert(int& num,un pos,un l=1,un r=n)
{
	if(!num)num=++cnt;
	if(l==r)return;
	un mid=(l+r)>>1;
	if(pos<=mid)insert(rt.ls,pos,l,mid);
	else insert(rt.rs,pos,mid+1,r);
}
bool Query(int num,un ql,un qr,un l=1,un r=n)
{
	if(!num)return 0;
	if(ql<=l&&r<=qr)return 1;
	un mid=(l+r)>>1;
	if(ql<=mid&&Query(rt.ls,ql,qr,l,mid))return 1;
	if(qr>mid&&Query(rt.rs,ql,qr,mid+1,r))return 1;
	return 0;
}
int merge(int x,int y,un l=1,un r=n)
{
	if(!x||!y)return x|y;
	if(l==r)return x;
	int num=++cnt;
	un mid=(l+r)>>1;
	rt.ls=merge(t[x].ls,t[y].ls,l,mid);
	rt.rs=merge(t[x].rs,t[y].rs,mid+1,r);
	return num;
}
namespace SAM
{
	int t[MAXN][26],pre[MAXN],len[MAXN];
	int last=1,tot=1;
	void extend(int w)
	{
		int pos=last,cur=++tot;
		len[cur]=len[pos]+1,last=cur;
		while(pos&&!t[pos][w])t[pos][w]=cur,pos=pre[pos];
		if(!pos){pre[cur]=1;return;}
		int nxt=t[pos][w];
		if(len[nxt]==len[pos]+1)pre[cur]=nxt;
		else
		{
			int tmp=++tot;
			len[tmp]=len[pos]+1,memcpy(t[tmp],t[nxt],sizeof t[nxt]);
			pre[tmp]=pre[nxt],pre[cur]=pre[nxt]=tmp;
			while(pos&&t[pos][w]==nxt)t[pos][w]=tmp,pos=pre[pos];
		}
	}
	std::vector<int>g[MAXN];
	void dfs(int u)
	{
		for(auto v:g[u])dfs(v),root[u]=merge(root[u],root[v]);
	}
	void build()
	{
		for(int i=2;i<=tot;++i)g[pre[i]].push_back(i);
		dfs(1);
	}
}
int ed[MAXN];
char s[MAXN];
bool check(int u,int len,int ql,int qr)
{
	if(ql+len-1>qr)return 0;
	return Query(root[u],ql+len-1,qr);
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)SAM::extend(s[i]-'a'),insert(root[SAM::last],i);
	SAM::build();
	int m=read();
	while(m--)
	{
		int l=read(),r=read();
		scanf("%s",s+1);
		int m=strlen(s+1),pos=0,ch=0,u=1;
		for(int i=1;i<=m;++i)
		{
			for(int c=s[i]-'a'+1;c<26;++c)
				if(SAM::t[u][c]&&check(SAM::t[u][c],i,l,r)){pos=i;ch=c;break;}
			int c=s[i]-'a';
			if(SAM::t[u][c]&&check(SAM::t[u][c],i,l,r))u=SAM::t[u][c];
			else{u=0;break;}
		}
		if(u)
		{
			bool succ=0;
			for(int c=0;c<26;++c)
				if(SAM::t[u][c]&&check(SAM::t[u][c],m+1,l,r))
				{
					printf("%s%c\n",s+1,'a'+c);
					succ=1;break;
				}
			if(succ)continue;
		}
		if(pos)
		{
			for(int i=1;i<pos;++i)putchar(s[i]);
			putchar('a'+ch),putchar('\n');
		}
		else puts("-1");
	}
	return 0;
}