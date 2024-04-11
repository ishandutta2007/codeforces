//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,q,ans[N],mxdep[N],hson[N],tp[N],dep[N],res,curans=0;
vector<ll> vt[N];
void dfs(ll x,ll lst,ll d)
{
	ll i;
	dep[x]=d;
	mxdep[x]=d;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x,d+1);
			if(mxdep[vt[x][i]]>mxdep[x])
			{
				hson[x]=vt[x][i];
				mxdep[x]=mxdep[vt[x][i]];
			}
		}
	}
	return;
}
void dfs2(ll x,ll lst,bool typ)
{
	tp[x]=(typ?tp[lst]:x);
	ll i;
	if(hson[x]!=-1)
	{
		dfs2(hson[x],x,true);
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst&&vt[x][i]!=hson[x])
		{
			dfs2(vt[x][i],x,false);
		}
	}
	return;
}
vector<ll> con;
int main(){
    ll i,x,y;
    scanf("%lld%lld",&n,&q);
    memset(hson,-1,sizeof(hson));
    for(i=1;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        x--,y--;
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    dfs(0,-1,0);
    dfs2(0,-1,false);
    for(i=0;i<n;i++)
    {
    	if(hson[i]==-1)
    	{
    		con.push_back(dep[i]-dep[tp[i]]+1);
		}
	}
	sort(con.begin(),con.end());
	reverse(con.begin(),con.end());
    ans[0]=min(n,n/2);
    res=-(n-ans[0])*ans[0];
    for(i=1;i<=q;i++)
    {
    	if(i>con.size())
    	{
    		res=max(res,(n-i)*i);
    		continue;
		}
    	curans+=con[i-1];
        ans[i]=min(n-curans,n/2);
        res=max(res,(n-ans[i]-i)*(i-ans[i]));
    }
    printf("%lld\n",res);
    return 0;
}