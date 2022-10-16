#include <iostream>

using namespace std;

int main()
{
	long long n,k,i=0,z=240;
	
	cin>>n>>k;
	z-=k;
	while(i<=n&&z>=0)
	{
		i++;
		z-=5*i;
	}
	cout<<i-1<<'\n';
}