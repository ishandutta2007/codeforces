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
#define N 400010
using namespace std;
ll n,m,k,cnt,cnt2,bel[N],dfn[N],lw[N],ans[N];
vector<ll> vt[N];
bool vis[N],inq[N];
stack<ll> stk;
ll getid(ll n0,ll k0,ll c1){return (n0*k+k0-1)*2+c1;}
void addedge(ll n1,ll k1,ll c1,ll n2,ll k2,ll c2)
{
//	cout<<n1<<","<<k1<<","<<c1<<": "<<getid(n1,k1,c1)<<" --> "<<n2<<","<<k2<<","<<c2<<": "<<getid(n2,k2,c2)<<endl;
	vt[getid(n1,k1,c1)].push_back(getid(n2,k2,c2));
	vt[getid(n2,k2,c2^1)].push_back(getid(n1,k1,c1^1));
	return;
}
void init()
{
	ll i;
	for(i=0;i<n*k*2;i++)
	{
		vis[i]=false;
		inq[i]=false;
		vt[i].clear();
	}
	cnt=cnt2=0;
	while(!stk.empty())
	{
		stk.pop();
	}
	return;
}
void dfs(ll x)
{
	vis[x]=inq[x]=true;
	stk.push(x);
	dfn[x]=lw[x]=++cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i]])
		{
			dfs(vt[x][i]);
			lw[x]=min(lw[x],lw[vt[x][i]]);
		}
		else if(inq[vt[x][i]])
		{
			lw[x]=min(lw[x],dfn[vt[x][i]]);
		}
	}
	if(lw[x]==dfn[x])
	{
		do
		{
			i=stk.top();
			stk.pop();
			inq[i]=false;
			bel[i]=cnt2;
		}while(i!=x);
		cnt2++;
	}
	return;
}
int main(){
	ll T,i,j,tp,x,y,z;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		init();
		for(i=0;i<n;i++)
		{
			addedge(i,1,0,i,1,1);
			for(j=1;j<=k;j++)
			{
				if(j<k)
				{
					addedge(i,j+1,1,i,j,1);
				}
				if(i+1<n)
				{
					addedge(i,j,1,i+1,j,1);
				}
			}
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&tp,&x);
			x--;
			if(tp==1)
			{
				scanf("%lld",&z);
				if(z<k)
				{
					addedge(x,z,1,x,z+1,1);
				}
				else
				{
					addedge(x,z,1,x,z,0);
				}
			}
			else if(tp==2)
			{
				scanf("%lld%lld",&y,&z);
				y--;
				for(j=1;j<=k;j++)
				{
					if(z-j+1<=k)
					{
						if(z-j+1>0)
						{
							addedge(x,j,1,y,z-j+1,0);
							addedge(y,j,1,x,z-j+1,0);
						}
						else
						{
							addedge(x,j,1,x,j,0);
							addedge(y,j,1,y,j,0);
						}
					}
				}
			}
			else
			{
				scanf("%lld%lld",&y,&z);
				y--;
				for(j=1;j<=k;j++)
				{
					if(z-j+1>0)
					{
						if(z-j+1<=k)
						{
							addedge(x,j,0,y,z-j+1,1);
							addedge(y,j,0,x,z-j+1,1);
						}
						else
						{
							addedge(x,j,0,x,j,1);
							addedge(y,j,0,y,j,1);
						}
					}
				}
			}
		}
		for(i=0;i<n*k;i++)
		{
			if(!vis[i<<1])
			{
				dfs(i<<1);
			}
		}
		for(i=0;i<n*k;i++)
		{
			if(!vis[(i<<1)|1])
			{
				dfs((i<<1)|1);
			}
		}
		bool isok=true;
		for(i=0;i<n;i++)
		{
			ans[i]=k+1;
			for(j=1;j<=k;j++)
			{
				x=getid(i,j,0),y=getid(i,j,1);
//				cout<<i<<","<<j<<": "<<x<<": "<<bel[x]<<" , "<<y<<": "<<bel[y]<<endl;
				if(bel[x]==bel[y])
				{
					isok=false;
				}
				else if(bel[x]<bel[y]&&j>1)
				{
					ans[i]=min(ans[i],j);
				}
			}
		}
		if(isok)
		{
			for(i=0;i<n;i++)
			{
				printf("%lld ",ans[i]-1);
			}
			puts("");
		}
		else
		{
			puts("-1");
		}
	}
	return 0;
}