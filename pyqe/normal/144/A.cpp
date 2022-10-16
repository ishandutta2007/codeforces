#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n,i,b=0,d=1000000000,p,q,z=0;
	
	cin>>n;
	long long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>b)
		{
			b=a[i];
		}
		if(a[i]<d)
		{
			d=a[i];
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==b)
		{
			break;
		}
	}
	p=i;
	for(i=n-1;i>=0;i--)
	{
		if(a[i]==d)
		{
			break;
		}
	}
	q=i;
	if(q<p)
	{
		z--;
	}
	z+=p+(n-1-q);
	cout<<z<<endl;
}