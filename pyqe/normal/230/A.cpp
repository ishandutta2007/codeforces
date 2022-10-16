#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	long long s,n,i;
	pair <long long,long long> a[1000];
	
	cin>>s>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(s<=a[i].first)
		{
			cout<<"NO\n";
			return 0;
		}
		s+=a[i].second;
	}
	cout<<"YES\n";
}