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
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
bool vis[N];
ll n,m,a[N],b[N],sum[N];
vector<ll> vt[N];
set<ll> st;
queue<pair<ll,ll> > q;
void upd(ll x)
{
	ll i;
	vis[x]=true;
	for(i=0;i<vt[x].size();i++)
	{
		if(vis[vt[x][i]])
		{
			q.push(make_pair(x,vt[x][i]));
		}
	}
	return;
}
void update(ll l,ll r)
{
	if(l>r)
	{
		swap(l,r);
	}
	for(set<ll>::iterator it=st.lower_bound(l);it!=st.end()&&(*it)<=r;)
	{
		set<ll>::iterator it2=it;
		++it;
		upd(*it2);
		st.erase(it2);
	}
	return;
}
int main(){
	ll T,i,j,x,y;
	T=rint();
	while(T--)
	{
		n=rint(),m=rint();
		vt[0].clear();
		for(i=0;i<n;++i)
		{
			vt[i+1].clear();
			a[i]=rint();
		}
		vis[0]=true;
		for(i=0;i<n;++i)
		{
			b[i]=rint();
			sum[i+1]=sum[i]+a[i]-b[i];
			vis[i+1]=(sum[i+1]==0);
		}
		for(i=0;i<m;++i)
		{
			x=rint()-1,y=rint();
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		while(!q.empty())
		{
			q.pop();
		}
		st.clear();
		for(i=0;i<=n;++i)
		{
			if(!vis[i])
			{
				st.insert(i);
			}
		}
		for(i=0;i<=n;++i)
		{
			if(vis[i])
			{
				for(j=0;j<vt[i].size();++j)
				{
					if(vis[vt[i][j]])
					{
						q.push(make_pair(i,vt[i][j]));
					}
				}
			}
		}
		while(!q.empty())
		{
			x=q.front().F,y=q.front().S;
			q.pop();
			update(x,y);
		}
		puts((st.empty())?"YES":"NO");
	}
	return 0;
}