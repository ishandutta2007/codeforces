#include <iostream>

using namespace std;

int main()
{
	long long n,p,k,i,j;
	
	cin>>n;
	long long arr[n];
	for(i=0;i<n;i++)
	{
		arr[i]=0;
	}
	for(j=0;j<2;j++)
	{
		cin>>p;
		for(i=0;i<p;i++)
		{
			cin>>k;
			arr[k-1]=1;
		}
	}
	p=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			p=1;
		}
	}
	if(p==0)
	{
		cout<<"I become the guy.\n";
	}
	else
	{
		cout<<"Oh, my keyboard!\n";
	}
}