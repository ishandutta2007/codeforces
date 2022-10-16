#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define mp make_pair
#define fr first
#define sc second

long long n,m,t,sz=0,z[500069];
pair<long long,long long> d[500069],qq[500069];
vector<pair<long long,long long>> v;
vector<long long> ps;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> superset;
superset pbds;

int main()
{
	long long i,k,ls=0,w,p,j,mdd;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=m;i++)
	{
		d[i].sc=i;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		d[k].fr++;
	}
	sort(d+1,d+m+1);
	v.push_back(mp(0,0));
	sz++;
	for(i=1;i<=m;i++)
	{
		if(v[sz-1].fr<d[i].fr+1)
		{
			v.push_back(mp(d[i].fr+1,v[sz-1].sc+1));
			ps.push_back(ls+(v[sz].fr-v[sz-1].fr)*v[sz-1].sc);
			ls=ps[sz-1];
			sz++;
		}
		else
		{
			v[sz-1].sc++;
		}
	}
	ps.push_back(1e18);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&qq[i].fr);
		qq[i].sc=i;
	}
	sort(qq,qq+t);
	for(i=0,j=0;i<t;i++)
	{
		k=qq[i].fr-n;
		w=qq[i].sc;
		p=lower_bound(ps.begin(),ps.end(),k)-ps.begin();
		for(;j<=m&&d[j].fr+1<=v[p].fr;j++)
		{
			pbds.insert(d[j].sc);
		}
		mdd=(k-ps[p-1]-1)%v[p].sc+1;
		z[w]=*pbds.find_by_order(mdd);
	}
	for(i=0;i<t;i++)
	{
		printf("%lld\n",z[i]);
	}
}