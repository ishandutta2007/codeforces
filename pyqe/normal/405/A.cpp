#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long i,n;
	
	cin>>n;
	long long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(i>0)
		{
			cout<<" ";
		}
		cout<<a[i];
	}
	cout<<endl;
}