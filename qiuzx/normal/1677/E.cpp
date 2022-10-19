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
#define N 1000010
using namespace std;
struct BIT{
	ll val[N];
	void upd(ll x,ll v)
	{
		++x;
		while(x<N)
		{
			val[x]+=v;
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		ll ret=0;
		++x;
		while(x>0)
		{
			ret+=val[x];
			x-=x&(-x);
		}
		return ret;
	}
}bit1,bit2,bit3,bit4;
ll n,q,p[N],id[N],sp[N][20],ans[N];
vector<pair<pair<ll,ll>,pair<ll,ll> > > upd;
vector<pair<ll,ll> > upds[N];
vector<pair<pair<ll,ll>,ll> > qrys[N];
ll qrynxtl(ll x,ll v)
{
	ll i;
	for(i=19;i>=0;i--)
	{
		ll plc=x-(1<<i)+1;
		if(plc>0&&sp[plc][i]<=v)
		{
			x=plc-1;
		}
	}
	return x+1;
}
ll qrynxtr(ll x,ll v)
{
	ll i;
	for(i=19;i>=0;i--)
	{
		ll plc=x+(1<<i)-1;
		if(plc<=n&&sp[x][i]<=v)
		{
			x=plc+1;
		}
	}
	return x-1;
}
void solve(ll x)
{
	ll i,nl=qrynxtl(x-1,p[x]),nr=qrynxtr(x+1,p[x]);
	vector<pair<ll,ll> > allseg,rseg;
	for(i=1;i*i<=p[x];i++)
	{
		if(p[x]%i==0)
		{
			ll curx=id[i],cury=id[p[x]/i];
			if(curx==cury)
			{
				continue;
			}
			if(curx>cury)
			{
				swap(curx,cury);
			}
			if(curx<nl||cury>nr)
			{
				continue;
			}
			allseg.push_back(make_pair(min(curx,x),max(cury,x)));
		}
	}
	sort(allseg.begin(),allseg.end());
	for(i=0;i<allseg.size();i++)
	{
		while(rseg.size()&&rseg[rseg.size()-1].S>=allseg[i].S)
		{
			rseg.pop_back();
		}
		rseg.push_back(allseg[i]);
	}
	if(!rseg.empty())
	{
		upd.push_back(make_pair(make_pair(nl,rseg[0].F),make_pair(rseg[0].S,nr)));
	}
	for(i=0;i+1<rseg.size();i++)
	{
		if(rseg[i].F<rseg[i+1].F)
		{
			upd.push_back(make_pair(make_pair(rseg[i].F+1,rseg[i+1].F),make_pair(rseg[i+1].S,nr)));
		}
	}
	return;
}
int main(){
	ll i,j,l,r;
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
		sp[i][0]=p[i];
		id[p[i]]=i;
	}
	for(i=1;i<20;i++)
	{
		for(j=1;j+(1<<(i-1))<=n;j++)
		{
			sp[j][i]=max(sp[j][i-1],sp[j+(1<<(i-1))][i-1]);
		}
	}
	for(i=1;i<=n;i++)
	{
		solve(i);
	}
	for(i=0;i<upd.size();i++)
	{
		upds[upd[i].F.F].push_back(make_pair(upd[i].S.F,1));
		upds[upd[i].F.F].push_back(make_pair(upd[i].S.S+1,-1));
		upds[upd[i].F.S+1].push_back(make_pair(upd[i].S.F,-1));
		upds[upd[i].F.S+1].push_back(make_pair(upd[i].S.S+1,1));
	}
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld",&l,&r);
		qrys[r].push_back(make_pair(make_pair(r,1),i));
		qrys[r].push_back(make_pair(make_pair(l-1,-1),i));
		qrys[l-1].push_back(make_pair(make_pair(r,-1),i));
		qrys[l-1].push_back(make_pair(make_pair(l-1,1),i));
	}
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<upds[i].size();j++)
		{
			bit1.upd(upds[i][j].F,upds[i][j].S);
			bit2.upd(upds[i][j].F,i*upds[i][j].S);
			bit3.upd(upds[i][j].F,upds[i][j].F*upds[i][j].S);
			bit4.upd(upds[i][j].F,i*upds[i][j].F*upds[i][j].S);
		}
		for(j=0;j<qrys[i].size();j++)
		{
			ll l=i,r=qrys[i][j].F.F;
			ans[qrys[i][j].S]+=(bit1.qry(r)*(l+1)*(r+1)-bit2.qry(r)*(r+1)-bit3.qry(r)*(l+1)+bit4.qry(r))*qrys[i][j].F.S;
		}
	}
	for(i=0;i<q;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}