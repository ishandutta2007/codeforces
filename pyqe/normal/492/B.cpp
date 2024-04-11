#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n,l,i,b;
	
	cin>>n>>l;
	long long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	b=a[0]*2;
	for(i=1;i<n;i++)
	{
		if(b<a[i]-a[i-1])
		{
			b=a[i]-a[i-1];
		}
	}
	if(b<(l-a[n-1])*2)
	{
		b=(l-a[n-1])*2;
	}
	cout<<b/2<<"."<<b%2*5<<"000000000\n";
}