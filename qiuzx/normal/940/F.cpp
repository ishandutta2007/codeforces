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
#define B 2100
using namespace std;
ll n,q,m,a[N],ans[N],updid[N],qryid[N],cnt[N],app[N];
pair<pair<ll,ll>,ll> qry[N],upd[N];
vector<ll> allv;
bool cmp(pair<pair<ll,ll>,ll> x,pair<pair<ll,ll>,ll> y)
{
	return (x.F.F/B==y.F.F/B)?((x.F.S/B==y.F.S/B)?x.S<y.S:x.F.S<y.F.S):(x.F.F<y.F.F);
}
void del(ll x)
{
	--app[cnt[a[x]]];
	--cnt[a[x]];
	assert(cnt[a[x]]>=0);
	++app[cnt[a[x]]];
	return;
}
void add(ll x)
{
	assert(cnt[a[x]]>=0);
	--app[cnt[a[x]]];
	++cnt[a[x]];
	++app[cnt[a[x]]];
	return;
}
int main(){
	ll i,j,k,l,r,tp;
	scanf("%lld%lld",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		allv.push_back(a[i]);
	}
	for(i=0;i<q;i++)
	{
		updid[i]=-1;
	}
	for(i=0,j=0;i<q;i++)
	{
		scanf("%lld%lld%lld",&tp,&l,&r);
		if(tp==1)
		{
			qryid[j]=i;
			qry[j].F.F=l-1,qry[j].F.S=r-1,qry[j].S=j;
			++j;
		}
		else
		{
			--l;
			updid[i]=i;
			upd[i].S=l;
			upd[i].F.F=a[l];
			a[l]=r;
			upd[i].F.S=a[l];
			allv.push_back(a[l]);
		}
	}
	m=q,q=j;
	sort(qry,qry+q,cmp);
	sort(allv.begin(),allv.end());
	allv.erase(unique(allv.begin(),allv.end()),allv.end());
	for(i=0;i<n;i++)
	{
		a[i]=lower_bound(allv.begin(),allv.end(),a[i])-allv.begin();
	}
	for(i=0;i<m;i++)
	{
		upd[i].F.F=lower_bound(allv.begin(),allv.end(),upd[i].F.F)-allv.begin();
		upd[i].F.S=lower_bound(allv.begin(),allv.end(),upd[i].F.S)-allv.begin();
	}
	k=m-1;
	l=r=0;
	for(i=0;i<q;i++)
	{
		while(r<=qry[i].F.S)
		{
			add(r++);
		}
		while(l>qry[i].F.F)
		{
			add(--l);
		}
		while(r>qry[i].F.S+1)
		{
			del(--r);
		}
		while(l<qry[i].F.F)
		{
			del(l++);
		}
		while(k>qryid[qry[i].S])
		{
			if(updid[k]!=-1)
			{
				if(upd[k].S>=qry[i].F.F&&upd[k].S<=qry[i].F.S)
				{
					del(upd[k].S);
				}
				a[upd[k].S]=upd[k].F.F;
				if(upd[k].S>=qry[i].F.F&&upd[k].S<=qry[i].F.S)
				{
					add(upd[k].S);
				}
			}
			--k;
		}
		while(k<qryid[qry[i].S])
		{
			++k;
			if(updid[k]!=-1)
			{
				if(upd[k].S>=qry[i].F.F&&upd[k].S<=qry[i].F.S)
				{
					del(upd[k].S);
				}
				a[upd[k].S]=upd[k].F.S;
				if(upd[k].S>=qry[i].F.F&&upd[k].S<=qry[i].F.S)
				{
					add(upd[k].S);
				}
			}
		}
		ans[qry[i].S]=1;
		while(app[ans[qry[i].S]]>0)
		{
			++ans[qry[i].S];
		}
	}
	for(i=0;i<q;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}