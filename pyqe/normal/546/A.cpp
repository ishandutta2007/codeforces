#include <iostream>

using namespace std;

int main()
{
	long long k,n,w,z;
	
	cin>>k>>n>>w;
	z=w*(w+1)/2*k-n;
	if(z<0)
	{
		z=0;
	}
	cout<<z<<endl;
}