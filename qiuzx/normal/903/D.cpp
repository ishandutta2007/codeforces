#include <bits/stdc++.h>
using namespace std;
vector<long double> v;
vector<pair<long double,long double> > smm;
long double n,sum=0,ans=0;
int main(){
	long double x,i,smn,bgn;
	pair<long double,long double> p1,p2;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	for(i=0;i<n;i++)
	{
		smm.push_back(make_pair(v[i],i));
	}
	sort(smm.begin(),smm.end());
	for(i=0;i<n;i++)
	{
		ans+=v[i]*i-sum;
		sum+=v[i];
		p1=make_pair(v[i]-1,0);
		p2=make_pair(v[i]-1,i);
		smn=upper_bound(smm.begin(),smm.end(),p2)-lower_bound(smm.begin(),smm.end(),p1);
		p1=make_pair(v[i]+1,0);
		p2=make_pair(v[i]+1,i);
		bgn=upper_bound(smm.begin(),smm.end(),p2)-lower_bound(smm.begin(),smm.end(),p1);
		ans=ans-smn+bgn;
	}
	cout<<fixed<<setprecision(0)<<ans<<endl;
	return 0;
}