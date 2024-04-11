#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n,i,z=0,m=0;
	
	cin>>n;
	long long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		z+=a[i];
	}
	sort(a,a+n);
	for(i=n-1;i>=0;i--)
	{
		m+=a[i];
		if(m>z/2)
		{
			break;
		}
	}
	cout<<n-i<<endl;
}