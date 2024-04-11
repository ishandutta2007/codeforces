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
#define db long double
#define N 250010
using namespace std;
db eps=1e-8,cur;
ll n,sx[N],sy[N],dirx[N],diry[N],spd[N];
pair<db,db> lft[N],rht[N];
vector<pair<pair<db,db>,pair<ll,ll> > > segs;
struct Cmp{
	bool operator () (const ll &x,const ll &y) const{
		db coord1=(db)lft[x].S+(cur-(db)lft[x].F)*(db)diry[x]/(db)dirx[x];
		db coord2=(db)lft[y].S+(cur-(db)lft[y].F)*(db)diry[y]/(db)dirx[y];
		return (coord1!=coord2)?(coord1<coord2):(x<y);
	}
};
ll sgn(db x)
{
	return (x<-eps)?-1:((x>eps)?1:0);
}
db cross(pair<db,db> x,pair<db,db> y)
{
	return x.F*y.S-x.S*y.F;
}
bool check(ll x,ll y)
{
	if(lft[x]>lft[y])
	{
		swap(x,y);
	}
	if(dirx[x]*diry[y]==diry[x]*dirx[y])
	{
		db slp=(db)(rht[x].S-rht[x].S)/(db)(lft[x].F-lft[x].F),slp2=(db)(lft[y].S-lft[x].S)/(db)(lft[y].F-lft[x].F);
		if(abs(slp-slp2)<=eps)
		{
			return (rht[x].F>=lft[y].F)&&(rht[y].F>=lft[x].F);
		}
	}
	pair<db,db> inda=lft[x],indb=rht[x],indc=lft[y],indd=rht[y];
	return (sgn(cross(make_pair(indb.F-inda.F,indb.S-inda.S),make_pair(indd.F-inda.F,indd.S-inda.S)))*sgn(cross(make_pair(indb.F-inda.F,indb.S-inda.S),make_pair(indc.F-inda.F,indc.S-inda.S)))<=0)&&(sgn(cross(make_pair(indd.F-indc.F,indd.S-indc.S),make_pair(indb.F-indc.F,indb.S-indc.S)))*sgn(cross(make_pair(indd.F-indc.F,indd.S-indc.S),make_pair(inda.F-indc.F,inda.S-indc.S)))<=0);
}
set<ll,Cmp> st;
bool check(db lim)
{
	ll i;
	segs.clear();
	for(i=0;i<n;i++)
	{
		db dis=(lim*(db)spd[i])/sqrt((db)(dirx[i]*dirx[i]+diry[i]*diry[i]));
		pair<db,db> nxt=make_pair(sx[i]+dis*(db)dirx[i],sy[i]+dis*(db)diry[i]);
		if(dirx[i]<0)
		{
			lft[i]=nxt;
			rht[i]=make_pair(sx[i],sy[i]);
		}
		else
		{
			lft[i]=make_pair(sx[i],sy[i]);
			rht[i]=nxt;
		}
		segs.push_back(make_pair(lft[i],make_pair(0,i)));
		segs.push_back(make_pair(rht[i],make_pair(1,i)));
	}
	sort(segs.begin(),segs.end());
	cur=segs[0].F.F;
	st.clear();
	for(i=0;i<segs.size();i++)
	{
		ll id=segs[i].S.S;
		cur=segs[i].F.F;
		Cmp _unknown_name_;
		if(segs[i].S.F==1)
		{
			set<ll,Cmp>::iterator it=st.lower_bound(id),it2;
			it2=it;
			it2++;
			if(it2!=st.end())
			{
				if(check(*it2,*it))
				{
					return true;
				}
			}
			it2=it;
			if(it!=st.begin())
			{
				it2--;
				if(check(*it2,*it))
				{
					return true;
				}
			}
			st.erase(it);
		}
		else
		{
			st.insert(id);
			set<ll,Cmp>::iterator it=st.lower_bound(id),it2;
			it2=it;
			it2++;
			if(it2!=st.end())
			{
				if(check(*it2,*it))
				{
					return true;
				}
			}
			it2=it;
			if(it!=st.begin())
			{
				it2--;
				if(check(*it2,*it))
				{
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld%lld",&sx[i],&sy[i],&dirx[i],&diry[i],&spd[i]);
	}
	if(!check(6e9))
	{
		puts("No show :(");
		return 0;
	}
	db l=0,r=6e9;
	while(l+eps<r)
	{
		db mid=(l+r)*(db)0.5;
		if(check(mid))
		{
			r=mid-eps;
		}
		else
		{
			l=mid+eps;
		}
	}
	printf("%.15Lf\n",l);
	return 0;
}