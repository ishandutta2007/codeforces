#include <bits/stdc++.h>
using namespace std;
struct state {long long t; long long d;} ;

int cmp(state a, state b)
{
	if (a.d-b.d) return (a.d<b.d);
	return (a.t>b.t);
}
int cmp2(state a, state b)
{
	 return (a.d<b.d);
}
long long t,k,n,m,i,j,res=0,a[200001];
vector<state> lisa,lisb; state h;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for (k=1;k<=t;k++)
	{
		cin>>n;
		lisa.clear();
		lisb.clear();
		for (i=1;i<=2*n;i++)
		{
			cin>>a[i];
			if (a[i]==2) a[i]=-1;
		}
		res=0; lisa.push_back({0,0});
		for (i=1;i<=n;i++) {
			res+=a[i];
			lisa.push_back({i,res});
		}
		res=0; lisb.push_back({0,0});
		for (i=1;i<=n;i++) {
			res+=a[2*n+1-i];
			lisb.push_back({i,res});
		}
		sort(lisb.begin(),lisb.end(),cmp);
		res=0;
		for (i=0;i<=n;i++)
		{
		h={1000000,-lisa[i].d};
		auto it=lower_bound(lisb.begin(),lisb.end(),h,cmp2);
		if ((it!=lisb.end())and((*it).d==-lisa[i].d)and((*it).t+i>res)) res=(*it).t+i;
		}
		cout<<2*n-res<<'\n';
	}
}