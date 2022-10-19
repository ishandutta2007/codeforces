//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 200010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,m,val[12][N],mxid[12];
vector<ll> v;
set<vector<ll> > mp,vis;
priority_queue<pair<ll,vector<ll> > > pq;
int main(){
	ll i,j,sum=0;
	n=rint();
	for(i=0;i<n;i++)
	{
		mxid[i]=rint();
		for(j=0;j<mxid[i];j++)
		{
			val[i][j]=rint();
		}
	}
	m=rint();
	v.resize(n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			v[j]=rint()-1;
		}
		mp.insert(v);
	}
	for(i=0;i<n;i++)
	{
		v[i]=mxid[i]-1;
		sum+=val[i][v[i]];
	}
	pq.push(make_pair(sum,v));
	vis.insert(v);
	while(!pq.empty())
	{
		v=pq.top().S;
		sum=pq.top().F;
		pq.pop();
		if(mp.find(v)==mp.end())
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			if(v[i]>0)
			{
				v[i]--;
				sum=sum+val[i][v[i]]-val[i][v[i]+1];
				if(vis.find(v)==vis.end())
				{
					vis.insert(v);
					pq.push(make_pair(sum,v));
				}
				sum=sum+val[i][v[i]+1]-val[i][v[i]];
				v[i]++;
			}
		}
	}
	for(i=0;i<v.size();i++)
	{
		printf("%d ",v[i]+1);
	}
	puts("");
	return 0;
}