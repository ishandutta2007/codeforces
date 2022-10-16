#include <iostream>

using namespace std;

int main()
{
	long long n,m,z=0,k=0,l=0;
	
	cin>>n>>m;
	while(n>0)
	{
		z+=n;
		k=(k+n%m)%m;
		n=(n+l)/m;
		l=k;
	}
	cout<<z<<'\n';
}