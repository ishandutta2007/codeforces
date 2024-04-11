#include <iostream>

using namespace std;

int main()
{
	long long n,k;
	
	cin>>n>>k;
	if(k<=(n-1)/2+1)
	{
		cout<<2*k-1<<endl;
	}
	else
	{
		k-=(n-1)/2+1;
		cout<<2*k<<endl;
	}
}