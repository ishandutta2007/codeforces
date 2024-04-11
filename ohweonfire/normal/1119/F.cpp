#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const int maxn=300111;

vector<int> edge[maxn],seq[maxn];
int eu[maxn],ev[maxn],ew[maxn];
int n,dgr[maxn];

struct data
{
	priority_queue<int,vector<int>,greater<int> > out;
	priority_queue<int> in;
	LL sum;int sz;
	data(){sum=sz=0;}
	
	void add(int x)
	{
		assert(in.empty()||out.empty()||in.top()<=out.top());
		if(!in.empty()&&in.top()>x)
		{
			in.push(x);
			sz++;
			sum+=x;
		}
		else out.push(x);
	}
	LL query(int nsz)
	{
		if(nsz>sz+(int)out.size())return Linf;
		while(sz>nsz)
		{
			int x=in.top();in.pop();
			out.push(x);sum-=x;sz--;
		}
		while(sz<nsz)
		{
			assert(!out.empty());
			int x=out.top();out.pop();
			in.push(x);sum+=x;sz++;
		}
		return sum;
	}
};
data val[maxn];

vector<int> g[maxn],l[maxn];

int mark[maxn],timer,K;
LL dp[maxn][2];

void dfs(int x,int f)
{
	mark[x]=timer;
	
	LL base=0;
	vector<LL>vs;
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f)
	{
		dfs(g[x][i],x);
		dp[g[x][i]][0]=min(dp[g[x][i]][0],dp[g[x][i]][1]+l[x][i]);
		base+=dp[g[x][i]][0];
		vs.pb(dp[g[x][i]][1]+l[x][i]-dp[g[x][i]][0]);
	}
	sort(vs.begin(),vs.end());
	
	dp[x][0]=dp[x][1]=Linf;
	
	int need;LL sum;
	
	need=dgr[x]-K;sum=0;
	for(int i=0;i<=need&&i<=(int)vs.size();i++)
	{
		dp[x][0]=min(dp[x][0],sum+base+val[x].query(need-i));
		if(i<(int)vs.size())sum+=vs[i];
	}
	
	need=dgr[x]-K-1;sum=0;
	for(int i=0;i<=need&&i<=(int)vs.size();i++)
	{
		dp[x][1]=min(dp[x][1],sum+base+val[x].query(need-i));
		if(i<(int)vs.size())sum+=vs[i];
	}
	
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",eu+i,ev+i,ew+i);
		dgr[eu[i]]++;dgr[ev[i]]++;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<dgr[i];j++)
			seq[j].pb(i);
	}
	
	for(int i=1;i<n;i++)
	{
		if(mp(dgr[eu[i]],eu[i])>mp(dgr[ev[i]],ev[i]))swap(eu[i],ev[i]);
		edge[eu[i]].pb(i);
	}
	
	for(int i=0;i<n;i++)
	{
		if(seq[i].size()==0)
		{
			printf("0 ");
			continue;
		}
		for(auto x:seq[i])
		{
			g[x].clear();
			l[x].clear();
		}
		for(auto x:seq[i])
		{
			for(auto e:edge[x])
			{
				g[x].pb(ev[e]);
				g[ev[e]].pb(x);
				l[x].pb(ew[e]);
				l[ev[e]].pb(ew[e]);
			}
		}
		
		timer++;K=i;
		LL ans=0;
		for(auto x:seq[i])if(mark[x]!=timer)
		{
			dfs(x,0);
			ans+=dp[x][0];
		}
		
		printf("%I64d ",ans);
		
		for(auto x:seq[i])if(dgr[x]==i+1)
		{
			for(auto e:edge[x])if(dgr[ev[e]]>=i)
			{
				//printf("add %d w= %d\n",ev[e],ew[e]);
				val[ev[e]].add(ew[e]);
			}
		}
	}
	
	return 0;
}