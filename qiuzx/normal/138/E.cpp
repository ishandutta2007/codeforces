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
ll k,lst,mst,ans=0,res=0,app[N];
string s;
vector<ll> lstoc[30];
pair<char,pair<ll,ll> > qry[N];
void update(ll l,ll r,ll v)
{
//	cout<<"update: "<<l<<" ~ "<<r<<" , "<<v<<endl;
	while(l<=r)
	{
		app[l]+=v;
		if((app[l]==mst+1&&v==1)||(app[l]==lst-1&&v==-1))
		{
			--ans;
		}
		if((app[l]==lst&&v==1)||(app[l]==mst&&v==-1))
		{
			++ans;
		}
		++l;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,l,r;
	cin>>s>>k>>lst>>mst;
	for(i=0;i<k;++i)
	{
		cin>>qry[i].F>>qry[i].S.F>>qry[i].S.S;
	}
	for(i=0;i<s.size();++i)
	{
		if(lst==0)
		{
			++ans;
		}
		lstoc[s[i]-'a'].push_back(i);
		for(j=0;j<k;++j)
		{
			if(qry[j].S.F==0)
			{
				update(i,i,1);
			}
			if(qry[j].F==s[i])
			{
				l=lstoc[s[i]-'a'].size()-qry[j].S.F,r=lstoc[s[i]-'a'].size()-qry[j].S.S-1;
				if(qry[j].S.F>0)
				{
					update((l-1<0?-1:lstoc[s[i]-'a'][l-1])+1,(l<0?-1:lstoc[s[i]-'a'][l]),1);
				}
				update((r-1<0?-1:lstoc[s[i]-'a'][r-1])+1,(r<0?-1:lstoc[s[i]-'a'][r]),-1);
			}
		}
		res+=ans;
	}
	cout<<res<<endl;
	return 0;
}