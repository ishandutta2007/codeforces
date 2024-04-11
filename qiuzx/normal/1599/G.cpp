//ANMHLIJKTJIY!
#pragma GCC optimize(2)
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
ll n,k,badnd,dx[N],dy[N];
map<pair<ll,ll>,pair<ll,ll> > mp;
vector<pair<ll,ll> > nd;
double ans;
double getdist(ll tx1,ll ty1,ll tx2,ll ty2)
{
	return sqrt((double)((tx1-tx2)*(tx1-tx2))+(double)((ty1-ty2)*(ty1-ty2)));
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&k);
	k--;
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&dx[i],&dy[i]);
	}
	for(i=1;i<n;i++)
	{
		pair<ll,ll> gras=make_pair(dx[i]-dx[0],dy[i]-dy[0]);
		if(gras.F<0)
		{
			gras.F=-gras.F;
			gras.S=-gras.S;
		}
		ll g=__gcd(gras.F,gras.S);
		if(g==0)
		{
			continue;
		}
		gras.F/=g;
		gras.S/=g;
		if(mp.count(gras))
		{
			mp[gras].F++;
		}
		else
		{
			mp[gras]=make_pair(1,i);
		}
	}
	if(mp.size()==2)
	{
		map<pair<ll,ll>,pair<ll,ll> >::iterator it=mp.begin();
		if(it->S.F==1)
		{
			badnd=it->S.S;
		}
		else
		{
			it++;
			badnd=it->S.S;
		}
	}
	else
	{
		badnd=0;
	}
	for(i=0;i<n;i++)
	{
		if(i!=badnd)
		{
			nd.push_back(make_pair(dx[i],dy[i]));
		}
	}
	sort(nd.begin(),nd.end());
	ll stx=nd[0].F,sty=nd[0].S,edx=nd[nd.size()-1].F,edy=nd[nd.size()-1].S;
	if(k==badnd)
	{
		ans=min(getdist(stx,sty,dx[k],dy[k]),getdist(edx,edy,dx[k],dy[k]))+getdist(stx,sty,edx,edy);
	}
	else
	{
		for(i=0;i<nd.size();i++)
		{
			if(nd[i].F==dx[k]&&nd[i].S==dy[k])
			{
				k=i;
				break;
			}
		}
		ans=LINF;
		for(i=0;i<nd.size();i++)
		{
			//k->0->n->badnd or k->n->0->badnd
			double cur=getdist(nd[k].F,nd[k].S,stx,sty)+getdist(edx,edy,dx[badnd],dy[badnd]);
			cur=min(cur,getdist(nd[k].F,nd[k].S,edx,edy)+getdist(stx,sty,dx[badnd],dy[badnd]));
			cur+=getdist(stx,sty,edx,edy);
			ans=min(ans,cur);
			//k->i->badnd->0/n
			cur=getdist(nd[k].F,nd[k].S,nd[i].F,nd[i].S)+getdist(nd[i].F,nd[i].S,dx[badnd],dy[badnd])+getdist(dx[badnd],dy[badnd],stx,sty);
			if(i>0&&k>0)
			{
				ans=min(ans,cur+getdist(stx,sty,nd[min(i-1,k-1)].F,nd[min(i-1,k-1)].S)+2*getdist(nd[max(i,k)].F,nd[max(i,k)].S,edx,edy));
			}
			cur+=getdist(stx,sty,edx,edy);
			ans=min(ans,cur);
			cur=getdist(nd[k].F,nd[k].S,nd[i].F,nd[i].S)+getdist(nd[i].F,nd[i].S,dx[badnd],dy[badnd])+getdist(dx[badnd],dy[badnd],edx,edy);
			if(max(k,i)<nd.size())
			{
				ans=min(ans,cur+getdist(edx,edy,nd[max(i+1,k+1)].F,nd[max(i+1,k+1)].S)+2*getdist(nd[min(i,k)].F,nd[min(i,k)].S,stx,sty));
			}
			cur+=getdist(stx,sty,edx,edy);
			ans=min(ans,cur);
			//k->0/n->badnd->i
			cur=getdist(nd[k].F,nd[k].S,stx,sty)+getdist(stx,sty,dx[badnd],dy[badnd])+getdist(dx[badnd],dy[badnd],nd[i].F,nd[i].S);
			if(i<=k)
			{
				cur+=getdist(nd[i].F,nd[i].S,edx,edy);
			}
			else
			{
				cur+=min(getdist(nd[i].F,nd[i].S,nd[k+1].F,nd[k+1].S),getdist(nd[i].F,nd[i].S,edx,edy))+getdist(nd[k+1].F,nd[k+1].S,edx,edy);
			}
			ans=min(ans,cur);
			cur=getdist(nd[k].F,nd[k].S,edx,edy)+getdist(edx,edy,dx[badnd],dy[badnd])+getdist(dx[badnd],dy[badnd],nd[i].F,nd[i].S);
			if(i>=k)
			{
				cur+=getdist(nd[i].F,nd[i].S,stx,sty);
			}
			else
			{
				cur+=min(getdist(nd[i].F,nd[i].S,nd[k-1].F,nd[k-1].S),getdist(nd[i].F,nd[i].S,stx,sty))+getdist(nd[k-1].F,nd[k-1].S,stx,sty);
			}
			ans=min(ans,cur);
			//k->i->badnd->i+1->n
			if(i+1<nd.size())
			{
				cur=getdist(nd[k].F,nd[k].S,stx,sty)+getdist(stx,sty,nd[i].F,nd[i].S)+getdist(nd[i].F,nd[i].S,dx[badnd],dy[badnd]);
				cur+=getdist(dx[badnd],dy[badnd],nd[i+1].F,nd[i+1].S)+getdist(nd[i+1].F,nd[i+1].S,edx,edy);
				ans=min(ans,cur);
			}
			//k->i->badnd->i-1->n
			if(i>0)
			{
				cur=getdist(nd[k].F,nd[k].S,edx,edy)+getdist(edx,edy,nd[i].F,nd[i].S)+getdist(nd[i].F,nd[i].S,dx[badnd],dy[badnd]);
				cur+=getdist(dx[badnd],dy[badnd],nd[i-1].F,nd[i-1].S)+getdist(nd[i-1].F,nd[i-1].S,stx,sty);
				ans=min(ans,cur);
			}
		}
	}
	printf("%.15lf\n",ans);
	return 0;
}