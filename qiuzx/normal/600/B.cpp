#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,i,x,pos;
	vector<long long> a,b;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(i=0;i<m;i++)
	{
		cin>>x;
		b.push_back(x);
	}
	sort(a.begin(),a.end());
	for(i=0;i<b.size();i++)
	{
		pos=upper_bound(a.begin(),a.end(),b[i])-a.begin();
		cout<<pos<<" ";
	}
	cout<<endl;
	return 0;
}