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
#define N 35
using namespace std;
ll k,bas,hval,ans[N],pw[N];
map<ll,ll> poss[N];
void getval(ll tp)
{
	ll i,mask,cnt,res,ly;
	vector<ll> v;
	for(mask=0;mask<(1<<((1<<(k-1))-1));mask++)
	{
		v.clear();
		for(i=1;i<=(1<<(k-1));i++)
		{
			if(tp==0)
			{
				v.push_back(i);
			}
			else
			{
				v.push_back(i+(1<<(k-1)));
			}
		}
		cnt=0;
		res=0;
		vector<ll> nv;
		ly=k-1;
		while(v.size()>1)
		{
			nv.clear();
			for(i=0;i<v.size();i+=2)
			{
				if(mask&(1<<cnt))
				{
					res=(res+pw[(1<<ly)+1]*v[i+1])%mod;
					nv.push_back(v[i]);
				}
				else
				{
					res=(res+pw[(1<<ly)+1]*v[i])%mod;
					nv.push_back(v[i+1]);
				}
				cnt++;
			}
			ly--;
			v=nv;
		}
		res=(res+pw[2]*v[0])%mod;
		poss[v[0]][res]=1;
	}
	return;
}
void cons(ll cham,ll val)
{
	ll i,mask,cnt,res,ly;
	vector<ll> v;
	for(mask=0;mask<(1<<((1<<(k-1))-1));mask++)
	{
		v.clear();
		for(i=1;i<=(1<<(k-1));i++)
		{
			if(cham<=(1<<(k-1)))
			{
				v.push_back(i);
			}
			else
			{
				v.push_back(i+(1<<(k-1)));
			}
		}
		cnt=0;
		res=0;
		vector<ll> nv;
		ly=k-1;
		while(v.size()>1)
		{
			nv.clear();
			for(i=0;i<v.size();i+=2)
			{
				if(mask&(1<<cnt))
				{
					res=(res+pw[(1<<ly)+1]*v[i+1])%mod;
					ans[v[i+1]]=(1<<ly)+1;
					nv.push_back(v[i]);
				}
				else
				{
					res=(res+pw[(1<<ly)+1]*v[i])%mod;
					ans[v[i]]=(1<<ly)+1;
					nv.push_back(v[i+1]);
				}
				cnt++;
			}
			ly--;
			v=nv;
		}
		res=(res+pw[2]*v[0])%mod;
		ans[v[0]]=2;
		if(v[0]==cham&&res==val)
		{
			return;
		}
	}
	return;
}
int main(){
	ll i,j,l;
	cin>>k>>bas>>hval;
	pw[0]=1;
	for(i=1;i<N;i++)
	{
		pw[i]=(pw[i-1]*bas)%mod;
	}
	getval(0);
	getval(1);
	for(i=1;i<=(1<<k);i++)
	{
		for(map<ll,ll>::iterator it=poss[i].begin();it!=poss[i].end();it++)
		{
			ll nv=((it->F)+mod-((i*pw[2])%mod)+((i*bas)%mod))%mod;
			for(j=1;j<=(1<<k);j++)
			{
				if((j-1)/(1<<(k-1))!=(i-1)/(1<<(k-1)))
				{
					if(poss[j].count((hval+mod-nv)%mod))
					{
						cons(i,it->F);
						cons(j,(hval+mod-nv)%mod);
						ans[i]=1;
						for(i=1;i<=(1<<k);i++)
						{
							cout<<ans[i]<<" ";
						}
						puts("");
						return 0;
					}
				}
			}
		}
	}
	puts("-1");
	return 0;
}