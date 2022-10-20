#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
bool cent[N];
ll n,mod,pw10[N],inv10[N],sonsz[N],mxsz[N];
vector<ll> pas,v1;
map<ll,ll> v2;
vector<pair<ll,ll> > vt[N];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll ret=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return ret;
}
ll get_inv(ll v)
{
	ll x,y;
	exgcd(v,mod,x,y);
	return (x%mod+mod*50)%mod;
}
void prepare()//get pow of 10, inv of 10(using exgcd)
{
	ll i,x,y;
	pw10[0]=1;
	exgcd(1,mod,x,y);
	inv10[0]=get_inv(1);
	for(i=1;i<N;i++)
	{
		pw10[i]=(pw10[i-1]*10)%mod;
		inv10[i]=get_inv(pw10[i]);
	}
	return;
}
//Centroid
//*******************************************************************************************
		void get_sonsize(ll x,ll lst)
		{
			ll i;
			mxsz[x]=0;
			sonsz[x]=1;
			pas.push_back(x);
			for(i=0;i<vt[x].size();i++)
			{
				if(vt[x][i].F==lst||cent[vt[x][i].F])
				{
					continue;
				}
				get_sonsize(vt[x][i].F,x);
				mxsz[x]=max(mxsz[x],sonsz[vt[x][i].F]);
				sonsz[x]+=sonsz[vt[x][i].F];
			}
			return;
		}
		ll get_cent(ll x)
		{
			pas.clear();
			get_sonsize(x,-1);
			ll i,ret=-1;
			for(i=0;i<pas.size();i++)
			{
				if(max((ll)pas.size()-sonsz[pas[i]],mxsz[pas[i]])*2<=pas.size())
				{
					ret=pas[i];
				}
			}
			return ret;
		}
//*******************************************************************************************
ll calc()
{
	ll i,ret=0;
	for(i=0;i<v1.size();i++)
	{
		if(v2.count(v1[i]))
		{
			ret+=v2[v1[i]];
		}
	}
	return ret;
}
void get_val(ll x,ll lst,ll dist,ll dist2,ll dep)
{
	ll i,nv=((mod*(ll)1000000000)-(dist2*inv10[dep])%mod)%mod;
	v1.push_back(dist);
	if(v2.count(nv))
	{
		v2[nv]++;
	}
	else
	{
		v2[nv]=1;
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F==lst||cent[vt[x][i].F])
		{
			continue;
		}
		get_val(vt[x][i].F,x,(dist+((pw10[dep]*vt[x][i].S)%mod))%mod,(dist2*10+vt[x][i].S)%mod,dep+1);
	}
	return;
}
ll dfs(ll x)
{
	ll nw=get_cent(x),i,ret=0;
	cent[nw]=true;
	for(i=0;i<vt[nw].size();i++)
	{
		if(!cent[vt[nw][i].F])
		{
			ret+=dfs(vt[nw][i].F);
			v1.clear();
			v2.clear();
			get_val(vt[nw][i].F,-1,vt[nw][i].S%mod,vt[nw][i].S%mod,1);
			ret-=calc();
		}
	}
	v1.clear();
	v2.clear();
	get_val(nw,-1,0,0,0);
	ret+=calc();
	cent[nw]=false;
	return ret-1;
}
int main(){
	ll i,x,y,z;
	scanf("%lld%lld",&n,&mod);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		vt[x].push_back(make_pair(y,z));
		vt[y].push_back(make_pair(x,z));
	}
	prepare();
	printf("%lld\n",dfs(0));
	return 0;
}