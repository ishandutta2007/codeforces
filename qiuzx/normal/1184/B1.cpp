#include <bits/stdc++.h>
#define N 100010
using namespace std;
int main(){
	long long s,b,x,y,i,pos;
	vector<long long> a,val,d;
	vector<pair<long long,long long> > dg;
	cin>>s>>b;
	for(i=0;i<s;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(i=0;i<b;i++)
	{
		cin>>x>>y;
		d.push_back(x);
		dg.push_back(make_pair(x,y));
	}
	sort(dg.begin(),dg.end());
	sort(d.begin(),d.end());
	val.push_back(0);
	for(i=0;i<dg.size();i++)
	{
		val.push_back(val[i]+dg[i].second);
	}
	for(i=0;i<a.size();i++)
	{
		pos=upper_bound(d.begin(),d.end(),a[i])-d.begin();
		cout<<val[pos]<<" ";
	}
	cout<<endl;
	return 0;
}