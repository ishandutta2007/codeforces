#include <iostream>

using namespace std;

int main()
{
	long long n,i,k,c=0,b=0;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		c-=k;
		cin>>k;
		c+=k;
		if(c>b)
		{
			b=c;
		}
	}
	cout<<b<<endl;
}