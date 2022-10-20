#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int debug=0;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct bit
{
	const int n=1e6;
	int t[N];
	void clear(int x){for (;x<=n;x+=x&-x) t[x]=0;}
	void add(int x){for (;x<=n;x+=x&-x) t[x]++;}
	int query(int x)
	{
		if (!x) return 0;
		int ret=0;
		for (;x;x=x&(x-1)) ret+=t[x];
		return ret;
	}
	int query(int l,int r){return query(r)-query(l-1);}
}tr;
vector<int>Son[N];
struct node
{
	int son[26],fail,end,id;
}t[N];
int cnt=0,dfn[N],siz[N],cntdfn=0;
void insert(string a,int id)
{
	int n=a.length(),now=0;
	#define to t[now].son[a[i]-'a']
	for (int i=0;i<n;i++)
	{
		if (!to) to=++cnt;
		now=to;
	}
	#undef to
	t[now].end=id;
}
void dfs(int now)
{
	siz[now]=1;
	dfn[now]=++cntdfn;
	for (int i:Son[now])
	{
		dfs(i);
		siz[now]+=siz[i];
	}
}
int q[N],he=1,ta=0;
void build()
{
	if (debug)
	for (int i=0;i<=cnt;i++)
	for (int j=0;j<26;j++) if (t[i].son[j]) print(i,' '),print(t[i].son[j],' '),putchar(j+'a'),puts("");
	for (int i=0;i<26;i++) if (t[0].son[i]) q[++ta]=t[0].son[i];
	while (he<=ta)
	{
		int now=q[he++];
		Son[t[now].fail].push_back(now);
		for (int i=0;i<26;i++)
		if (t[now].son[i])
		{
			t[t[now].son[i]].fail=t[t[now].fail].son[i];
			q[++ta]=t[now].son[i];
		}
		else t[now].son[i]=t[t[now].fail].son[i];
		if (t[now].end) t[now].id=now;
				   else t[now].id=t[t[now].fail].id;
	}
	if (debug)
	for (int i=0;i<=cnt;i++)
	{
		print(i,':');
		print(t[i].end,' ');
		print(t[i].id,' ');
		print(t[i].fail);
	}
}
string a[N],b[N];
int l[N],len[N],p[N];
bool vis[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) cin>>b[i],len[i]=b[i].length(),p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return len[x]<len[y];});
	for (int i=1;i<=n;i++) a[i]=b[p[i]];
	for (int i=1;i<=n;i++) insert(a[i],i);
	if (debug) for (int i=1;i<=n;i++) cout<<a[i]<<endl;
	build();
	dfs(0);
	for (int i=1;i<=n;i++)
	{
		len[i]=a[i].length();
		for (int j=0,now=0;j<len[i];j++)
		{
			now=t[now].son[a[i][j]-'a'];
			l[j]=j+1==len[i]?t[t[now].fail].id:t[now].id;
		}
		if (debug)
		for (int j=0;j<len[i];j++) print(l[j]," \n"[j+1==len[i]]);
		for (int j=0;j<len[i];j++) vis[l[j]]=0;
		for (int j=len[i]-1,L=len[i];j>=0;j--)
		if (l[j])
		{
			if (!tr.query(dfn[l[j]],dfn[l[j]])) tr.add(dfn[l[j]]);
			if (L<=j-len[t[l[j]].end]+1) vis[l[j]]=1;
			else L=j-len[t[l[j]].end]+1;
		}
		for (int j=0;j<len[i];j++)
		if (l[j]&&!vis[l[j]]&&tr.query(dfn[l[j]],dfn[l[j]]+siz[l[j]]-1)==1) ans++,vis[l[j]]=1;
		for (int j=0;j<len[i];j++) if (l[j]) tr.clear(dfn[l[j]]);
	}
	print(ans);
	
	return 0;
}