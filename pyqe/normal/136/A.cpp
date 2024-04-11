#include <iostream>

using namespace std;

int main()
{
	long long n,i,j;
	
	cin>>n;
	long long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		if(i>0)
		{
			cout<<" ";
		}
		for(j=0;j<n;j++)
		{
			if(a[j]==i+1)
			{
				cout<<j+1;
				break;
			}
		}
	}
	cout<<endl;
}