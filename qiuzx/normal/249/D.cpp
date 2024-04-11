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
#define N 100010
using namespace std;
ll n,a,b,c,d,dx[N],dy[N];
vector<ll> allx,ally,coord[N];
struct BIT{
	ll val[N];
	void upd(ll x,ll v)
	{
		++x;
		while(x<N)
		{
			val[x]=max(val[x],v);
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		++x;
		ll ret=0;
		while(x>0)
		{
			ret=max(ret,val[x]);
			x-=x&(-x);
		}
		return ret;
	}
}bit;
pair<ll,ll> trs(string s)
{
	ll x=0,y=0,i,t;
	for(i=0,t=0;i<s.size();i++)
	{
		if(s[i]=='/')
		{
			t=1;
		}
		else if(t==0)
		{
			x=x*10+(s[i]-'0');
		}
		else
		{
			y=y*10+(s[i]-'0');
		}
	}
	return make_pair(x,y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,x,y;
	string s1,s2;
	cin>>n>>s1>>s2;
	pair<ll,ll> x1=trs(s1);
	a=x1.F,b=x1.S;
	x1=trs(s2);
	c=x1.F,d=x1.S;
	dx[0]=dy[0]=0;
	allx.push_back(0);ally.push_back(0);
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		dx[i]=b*y-a*x;dy[i]=-(d*y-c*x);
		allx.push_back(dx[i]);ally.push_back(dy[i]);
	}
	sort(allx.begin(),allx.end());allx.erase(unique(allx.begin(),allx.end()),allx.end());
	sort(ally.begin(),ally.end());ally.erase(unique(ally.begin(),ally.end()),ally.end());
	for(i=0;i<=n;i++)
	{
		dx[i]=lower_bound(allx.begin(),allx.end(),dx[i])-allx.begin();dy[i]=lower_bound(ally.begin(),ally.end(),dy[i])-ally.begin();
		coord[dx[i]].push_back(dy[i]);
	}
	for(i=0;i<allx.size();i++)
	{
		sort(coord[i].begin(),coord[i].end());
		for(j=coord[i].size()-1;j>=0;j--)
		{
			bit.upd(coord[i][j]+1,(allx[i]<=0||ally[coord[i][j]]<=0)?0:bit.qry(coord[i][j])+1);
		}
	}
	cout<<bit.qry(ally.size()+2)<<endl;
	return 0;
}