// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int MAGIC=300;

int ch[100111][26],tot,fail[100111];
int insert(int cur,int c){if(ch[cur][c]==0)ch[cur][c]=++tot;return ch[cur][c];}
int que[100111],rear;
void getfail()
{
	rear=0;
	for(int i=0;i<26;i++)if(ch[0][i])
	{
		fail[ch[0][i]]=0;
		que[rear++]=ch[0][i];
	}
	for(int _=0;_<rear;_++)
	{
		int x=que[_];
		for(int i=0;i<26;i++)
		{
			int u=ch[x][i],v=fail[x];
			if(!u){ch[x][i]=ch[v][i];continue;}
			que[rear++]=u;
			while(v&&!ch[v][i])v=fail[v];
			fail[u]=ch[v][i];
		}
	}
}

vector<int> have[100111],ed[100111],g[100111];
vector<pair<pii,int> >qb[100111],qs[100111];
int n,q,now[100111],len[100111];

LL ans[100111],pre[100111],pre_block[100111/MAGIC+100];
void add(int x,int v){for(;x<=n&&x%MAGIC;x++)pre[x]+=v;for(;x<=n;x+=MAGIC)pre_block[x/MAGIC]+=v;}
LL query(int x){return pre[x]+pre_block[x/MAGIC];}

LL bdfs(int x,int cur)
{
	LL sum=0;
	for(auto&v:have[x])if(v==cur)sum++;
	for(auto&v:g[x])sum+=bdfs(v,cur);
	for(auto&v:ed[x])pre[v]=sum;
	return sum;
}
void sdfs(int x)
{
	for(auto&v:ed[x])add(v,1);
	for(auto&v:have[x])for(auto&q:qs[v])ans[q.ss]+=query(q.ff.ss)-query(q.ff.ff-1);
	for(auto&v:g[x])sdfs(v);
	for(auto&v:ed[x])add(v,-1);
}
char s[100111];
int main()
{
	get2(n,q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);len[i]=strlen(s+1);
		now[i]=0;
		for(int j=1;j<=len[i];j++)
		{
			now[i]=insert(now[i],s[j]-'a');
			have[now[i]].pb(i);
		}
		ed[now[i]].pb(i);
	}
	getfail();for(int i=1;i<=tot;i++)g[fail[i]].pb(i);
	for(int i=1,l,r,k;i<=q;i++)
	{
		get3(l,r,k);
		if(len[k]>MAGIC)qb[k].pb(mp(mp(l,r),i));
		else qs[k].pb(mp(mp(l,r),i));
	}
	for(int i=1;i<=n;i++)
	{
		if(len[i]>MAGIC)
		{
			bdfs(0,i);
			for(int j=1;j<=n;j++)pre[j]+=pre[j-1];
			for(auto&q:qb[i])ans[q.ss]=pre[q.ff.ss]-pre[q.ff.ff-1];
		}
	}
	memset(pre,0,sizeof(pre));memset(pre_block,0,sizeof(pre_block));
	sdfs(0);
	for(int i=1;i<=q;i++)printendl(ans[i]);
	return 0;
}