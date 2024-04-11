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

bool use[300111];
int ver[300111],cmp[300111],vs;
struct twosat
{
	int head[300111],dhead[300111],nxt[2000111],to[2000111],tot;
	void addedge(int u,int v)
	{
//		printf("addedge %d %d\n",u,v);
		nxt[++tot]=head[u];head[u]=tot;
		to[tot]=v;
		nxt[++tot]=dhead[v];dhead[v]=tot;
		to[tot]=u; 
	}
	void dfs(int x)
	{
		use[x]=1;
		for(int i=dhead[x];i;i=nxt[i])
			if(!use[to[i]])
				dfs(to[i]);
		ver[++vs]=x;
	}
	void rdfs(int x,int cc)
	{
		cmp[x]=cc;
		for(int i=head[x];i;i=nxt[i])
			if(!cmp[to[i]])
				rdfs(to[i],cc);
	}
	bool solve(int n)
	{
		memset(use,0,sizeof(use));memset(cmp,0,sizeof(cmp));vs=0;
		for(int i=1;i<=n+n;i++)if(!use[i])dfs(i);
		int k=0;
		for(int i=n+n;i>=1;i--)if(!cmp[ver[i]])rdfs(ver[i],++k);
		for(int i=1;i<=n;i++)if(cmp[i]==cmp[i+n])return false;
		return true;
	}
};
twosat thor,hulk;
vector<int>id[50111];
int n,m,u[50111],v[50111],t[50111],vt[50111];
map<int,int>now[50111];
bool check(int x)
{
	hulk=thor;
	for(int i=1;i<=m;i++)if(t[i]>x)
		hulk.addedge(i+m*3,i);
	return hulk.solve(m*3);
}
int main()
{
	get2(n,m);
	for(int i=1,c;i<=m;i++)
	{
		get2(u[i],v[i]);
		get2(c,t[i]);
		int&t=now[u[i]][c];
		if(t==0)t=i;
		else if(t==-1){puts("No");return 0;}
		else
		{
			thor.addedge(i,t+m*3);
			thor.addedge(t,i+m*3);
			t=-1;
		}
		int&t2=now[v[i]][c];
		if(t2==0)t2=i;
		else if(t2==-1){puts("No");return 0;}
		else
		{
			thor.addedge(i,t2+m*3);
			thor.addedge(t2,i+m*3);
		}
		id[u[i]].pb(i);id[v[i]].pb(i);
	}
	memcpy(vt,t,sizeof(t));sort(vt+1,vt+m+1);
	int sum=m;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)id[i].size();j++)
		{
			sum++;
			thor.addedge(id[i][j]+m*3,sum+m*3);
			thor.addedge(sum,id[i][j]);
			if(j>0)
			{
				thor.addedge(sum+m*3-1,sum+m*3);
				thor.addedge(sum,sum-1);
				thor.addedge(sum+m*3-1,id[i][j]);
				thor.addedge(id[i][j]+m*3,sum-1);
			}
		}
	}
	if(!thor.solve(m*3))puts("No");
	else
	{
		puts("Yes");
		int l=-1,r=m,mid;
		while(l<r-1)
		{
			mid=(l+r+1)>>1;
			if(check(vt[mid]))r=mid;
			else l=mid;
		}
		check(vt[r]);
		int ans=0;
		for(int i=1;i<=m;i++)ans+=(cmp[i]>cmp[i+m*3]);
		printf("%d %d\n",vt[r],ans);
		for(int i=1;i<=m;i++)if(cmp[i]>cmp[i+m*3])printf("%d ",i);
	}
	return 0;
}