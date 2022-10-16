#include <iostream>

using namespace std;

int main()
{
	long long n,i,k,l,c=0;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k>>l;
		if(l-k>=2)
		{
			c++;
		}
	}
	cout<<c<<endl;
}