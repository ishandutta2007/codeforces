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
#define ll int
#define N 1010
using namespace std;
ll n;
bool islf[N],vis[N];
bitset<N> nei[N],allnd,poss[N],rnei[N];
vector<pair<ll,ll> > ed;
vector<ll> vt[N];
bool check0()
{
	ll i;
	for(i=1;i<n;i++)
	{
		if(nei[i]!=nei[i-1])
		{
			return false;
		}
	}
	return true;
}
void solve(ll id)
{
	bitset<N> nds=(nei[id]^(nei[id]&allnd)),cur=(nei[id]&allnd);
	ll i,j;
	for(i=0;i<n;i++)
	{
		if((nei[i]&nei[id]).count()==1)
		{
			cur[(nei[i]&nei[id])._Find_first()]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		if(nds[i])
		{
			poss[i]=cur;
		}
	}
	return;
}
int main(){
	ll i,j,k,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&y);
		while(y--)
		{
			scanf("%d",&x);
			nei[i][x-1]=1;
		}
	}
	if(n==2||check0())
	{
		for(i=1;i<n;i++)
		{
			printf("1 %d\n",i+1);
		}
		return 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			bitset<N> cur=nei[i]&nei[j];
			if(cur.count()==2)
			{
				x=cur._Find_first();
				y=cur._Find_next(x);
				allnd[x]=1;allnd[y]=1;
				ed.push_back(make_pair(x,y));
				vt[x].push_back(y);vt[y].push_back(x);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		ll cnt=0;
		for(j=0;j<n;j++)
		{
			if((nei[j]&nei[i])==nei[i])
			{
				cnt++;
			}
		}
		islf[i]=(cnt==nei[i].count());
	}
	for(i=0;i<n;i++)
	{
		if(islf[i])
		{
			solve(i);
			for(j=i+1;j<n;j++)
			{
				if(nei[j]==nei[i])
				{
					islf[j]=false;
				}
			}
		}
	}
	queue<ll> q;
	for(i=0;i<n;i++)
	{
		if(poss[i].count()==1)
		{
			vis[i]=true;
			q.push(i);
		}
	}
	if(q.empty())
	{
		for(i=0;i<n;i++)
		{
			if(islf[i])
			{
				x=i;
				break;
			}
		}
		ll y=(nei[x]^(nei[x]&allnd))._Find_first();
		ll p1=poss[y]._Find_first(),p2=poss[y]._Find_next(p1);
		for(i=0;i<n;i++)
		{
			if(i==p1||i==p2)
			{
				continue;
			}
			if(nei[x][i])
			{
				ed.push_back(make_pair(p1,i));
			}
			else
			{
				ed.push_back(make_pair(p2,i));
			}
		}
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		y=poss[x]._Find_first();
		ed.push_back(make_pair(y,x));
		for(i=0;i<n;i++)
		{
			if((!vis[i])&&poss[i][y])
			{
				poss[i][y]=0;
				if(poss[i].count()==1)
				{
					q.push(i);
					vis[i]=true;
				}
			}
		}
	}
	for(i=0;i<ed.size();i++)
	{
		if(ed[i].F>ed[i].S)
		{
			swap(ed[i].F,ed[i].S);
		}
	}
	sort(ed.begin(),ed.end());
	ed.erase(unique(ed.begin(),ed.end()),ed.end());
	for(i=0;i<ed.size();i++)
	{
		printf("%d %d\n",ed[i].F+1,ed[i].S+1);
	}
	return 0;
}