#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n,m,i,b;
	
	cin>>n>>m;
	long long a[m];
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+m);
	b=a[m-1];
	for(i=0;i<=m-n;i++)
	{
		if(a[i+n-1]-a[i]<b)
		{
			b=a[i+n-1]-a[i];
		}
	}
	cout<<b<<endl;
	
}