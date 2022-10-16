#include <iostream>

using namespace std;

int main()
{
	long long n,i,l=0,k,c=0;;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		if(k!=l)
		{
			c++;
		}
		l=k;
	}
	cout<<c<<endl;
}