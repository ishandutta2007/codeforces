#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=100010;
const int S=26;
ll ans;
namespace SAM1
{
	int tot=1,last=1,pre[N<<1],son[N<<1][S],ml[N<<1],n;
	void extend(int w){
		int p=++tot,x=last,r,q;
		for(ml[last=p]=ml[x]+1;x&&!son[x][w];x=pre[x])son[x][w]=p;
		if(!x)pre[p]=1;
		else if(ml[x]+1==ml[q=son[x][w]])pre[p]=q;
		else{
			pre[r=++tot]=pre[q];memcpy(son[r],son[q],sizeof son[r]);
			ml[r]=ml[x]+1;pre[p]=pre[q]=r;
			for(;x&&son[x][w]==q;x=pre[x])son[x][w]=r;
		}
	}
	vector<int>g[N<<1];
	int dfn[N<<1],dep[N<<1],par[17][N<<1],ti;
	void dfs(int p)
	{
		dfn[p]=++ti;
		rep(i,16)par[i][p]=par[i-1][par[i-1][p]];
		for(auto i:g[p])dep[i]=dep[p]+1,par[0][i]=p,dfs(i);
	}
	int id[N];
	void work(char* s)
	{
		n=strlen(s+1);
		rep(i,n)
		{
			id[i]=tot+1;
			extend(s[i]-'a');
			if(i>=n-1)rep(j,tot)if(j!=1)ans+=ml[j]-ml[pre[j]];
		}
		rep(i,tot)if(i!=1)g[pre[i]].pb(i);
		dfs(1);
	}
	int lca(int x,int y)
	{
		if(dep[x]>dep[y])swap(x,y);
		if(dep[y]>dep[x])for(int i=16;i>=0;i--)if(dep[par[i][y]]>=dep[x])y=par[i][y];
		if(x==y)return x;
		for(int i=16;i>=0;i--)if(par[i][x]!=par[i][y])x=par[i][x],y=par[i][y];
		return par[0][x];
	}
	int query(int x,int y){return ml[lca(x,y)];}
}
namespace SAM2
{
	int tot=1,last=1,pre[N<<1],son[N<<1][S],ml[N<<1],n;
	void extend(int w){
		int p=++tot,x=last,r,q;
		for(ml[last=p]=ml[x]+1;x&&!son[x][w];x=pre[x])son[x][w]=p;
		if(!x)pre[p]=1;
		else if(ml[x]+1==ml[q=son[x][w]])pre[p]=q;
		else{
			pre[r=++tot]=pre[q];memcpy(son[r],son[q],sizeof son[r]);
			ml[r]=ml[x]+1;pre[p]=pre[q]=r;
			for(;x&&son[x][w]==q;x=pre[x])son[x][w]=r;
		}
	}
	vector<int>g[N<<1];
	struct cmp{bool operator()(int x,int y)const {return SAM1::dfn[x]<SAM1::dfn[y];}};
	set<int,cmp>s[N<<1];
	ll sum[N<<1];
	int id[N<<1];
	void dfs(int p)
	{
		if(id[p]&&id[p]<=n-2)s[p].insert(SAM1::id[n-id[p]-1]),sum[p]=SAM1::ml[SAM1::id[n-id[p]-1]];
		for(auto i:g[p])
		{
			dfs(i);
			if(s[i].size()>s[p].size())swap(s[i],s[p]),sum[p]=sum[i];
			for(auto j:s[i])
			{
				s[p].insert(j);sum[p]+=SAM1::ml[j];
				auto it=s[p].find(j);int l,r;
				if(it!=s[p].begin())it--,l=*it,it++;else l=0;
				it++;if(it!=s[p].end())r=*it;else r=0;
				if(l&&r)sum[p]+=SAM1::query(l,r);
				if(l)sum[p]-=SAM1::query(l,j);
				if(r)sum[p]-=SAM1::query(r,j);
			}
		}
		ans+=sum[p]*(ml[p]-ml[pre[p]]);
	}
	void work(char* s)
	{
		n=strlen(s+1);
		rep(i,n)
		{
			id[tot+1]=i;
			extend(s[i]-'a');
			if(i==n-1)rep(j,tot)if(j!=1)ans+=ml[j]-ml[pre[j]];
		}
		rep(i,tot)if(i!=1)g[pre[i]].pb(i);
		dfs(1);
	}
}
char s[N];
int main()
{
	scanf("%s",s+1);int n=strlen(s+1);
	SAM1::work(s);
	reverse(s+1,s+n+1);
	SAM2::work(s);
	printf("%lld\n",ans+2);
	return 0;
}