#include <iostream>

using namespace std;

int main()
{
	long long n,z=0,i;
	
	cin>>n;
	for(i=1;i<n;i++)
	{
		z+=i*(n-i);
	}
	z+=n;
	cout<<z<<"\n";
}