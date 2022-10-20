//just for practise
//code 2
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,m,k,fo[N],bk[N],sp[N],ans=0;
vector<ll> vt[N];
vector<pair<ll,ll> > v1;
vector<pair<pair<ll,ll>,ll> > v2;
int main(){
	ll i,j,x,y,l,r,mid;
	cin>>n>>m>>k;
	for(i=0;i<k;i++)
	{
		cin>>sp[i];
		sp[i]--;
	}
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	priority_queue<pair<ll,ll> > pq;
	memset(fo,127,sizeof(fo));
	fo[0]=0;
	pq.push(make_pair(0,0));
	while(!pq.empty())
	{
		x=-pq.top().F;
		y=pq.top().S;
		pq.pop();
		for(i=0;i<vt[y].size();i++)
		{
			if(x+1<fo[vt[y][i]])
			{
				fo[vt[y][i]]=x+1;
				pq.push(make_pair(-(x+1),vt[y][i]));
			}
		}
	}
	memset(bk,127,sizeof(bk));
	bk[n-1]=0;
	pq.push(make_pair(0,n-1));
	while(!pq.empty())
	{
		x=-pq.top().F;
		y=pq.top().S;
		pq.pop();
		for(i=0;i<vt[y].size();i++)
		{
			if(x+1<bk[vt[y][i]])
			{
				bk[vt[y][i]]=x+1;
				pq.push(make_pair(-(x+1),vt[y][i]));
			}
		}
	}
	for(i=0;i<k;i++)
	{
		v1.push_back(make_pair(fo[sp[i]],bk[sp[i]]));
	}
	sort(v1.begin(),v1.end());
	for(i=0;i<v1.size();i++)
	{
		while(v2.size()&&v2[v2.size()-1].F.F==v1[i].F)
		{
			ans=max(ans,min(v2[v2.size()-1].F.F+v1[i].S,v2[v2.size()-1].F.S+v1[i].F)+1);
			v2.erase(v2.end()-1);
		}
		if(v2.size())
		{
			ans=max(ans,min(v2[v2.size()-1].F.F+v1[i].S,v2[v2.size()-1].F.S+v1[i].F)+1);
		} 
		v2.push_back(make_pair(make_pair(v1[i].F,v1[i].S),i));
	}
	for(i=0;i<k;i++)
	{
		l=0;
		r=v2.size();
		while(l<r)
		{
			mid=(l+r)/2;
			if(v2[mid].F.F+v1[i].S>=v2[mid].F.S+v1[i].F)//if this place is after i.(Considering the path from 0~n-1 only)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		if(v2[l].S!=i&&l<v2.size())
		{
			ans=max(ans,min(v2[l].F.F+v1[i].S,v2[l].F.S+v1[i].F)+1);
		}
		if(v2[l-1].S!=i&&l>0)
		{
			ans=max(ans,min(v2[l-1].F.F+v1[i].S,v2[l-1].F.S+v1[i].F)+1);
		}
	}
	cout<<min(ans,fo[n-1])<<endl;
	return 0;
}