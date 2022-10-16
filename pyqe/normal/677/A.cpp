#include <iostream>

using namespace std;

int main()
{
	long long n,m,i,z=0,k;
	
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>k;
		if(k>m)
		{
			z++;
		}
		z++;
	}
	cout<<z<<endl;
}