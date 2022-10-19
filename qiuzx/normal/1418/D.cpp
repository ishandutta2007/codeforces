#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,q;
set<ll> st;
multiset<ll> mst;
int main(){
	set<ll>::iterator it,it2,it3;
	multiset<ll>::iterator mit;
	ll i,tp,a;
	scanf("%lld%lld",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a);
		st.insert(a);
		it=st.find(a);
		it2=it;
		it3=it;
		it3++;
		if(st.size()==1)
		{
			continue;
		}
		if(it==st.begin())
		{
			mst.insert((*it3)-(*it));
		}
		else if(it3==st.end())
		{
			it2--;
			mst.insert((*it)-(*it2));
		}
		else
		{
			it2--;
			mst.erase(mst.find((*it3)-(*it2)));
			mst.insert((*it3)-(*it));
			mst.insert((*it)-(*it2));
		}
	}
	if(st.size()<=1)
	{
		puts("0");
	}
	else
	{
		it=st.end();
		it--;
		mit=mst.end();
		mit--;
		printf("%lld\n",(*it)-(*(st.begin()))-(*mit));
	}
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld",&tp,&a);
		if(tp==0)
		{
			it=st.find(a);
			it2=it;
			it3=it;
			it3++;
			if(st.size()==1);
			else if(it==st.begin())
			{
				mst.erase(mst.find((*it3)-(*it)));
			}
			else if(it3==st.end())
			{
				it2--;
				mst.erase(mst.find((*it)-(*it2)));
			}
			else
			{
				it2--;
				mst.erase(mst.find((*it)-(*it2)));
				mst.erase(mst.find((*it3)-(*it)));
				mst.insert((*it3)-(*it2));
			}
			st.erase(it);
		}
		else
		{
			st.insert(a);
			it=st.find(a);
			it2=it;
			it3=it;
			it3++;
			if(st.size()==1);
			else if(it==st.begin())
			{
				mst.insert((*it3)-(*it));
			}
			else if(it3==st.end())
			{
				it2--;
				mst.insert((*it)-(*it2));
			}
			else
			{
				it2--;
				mst.insert((*it)-(*it2));
				mst.insert((*it3)-(*it));
				mst.erase(mst.find((*it3)-(*it2)));
			}
		}
		if(st.size()<=1)
		{
			puts("0");
		}
		else
		{
			it=st.end();
			it--;
			mit=mst.end();
			mit--;
			printf("%lld\n",(*it)-(*(st.begin()))-(*mit));
		}
	}
	return 0;
}