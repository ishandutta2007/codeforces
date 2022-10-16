#include <iostream>

using namespace std;

int main()
{
	long long t,i,k,b,d,c=0;
	
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>k;
		if(i==0)
		{
			b=k;
			d=k;
		}
		else
		{
			if(k<d)
			{
				d=k;
				c++;
			}
			if(k>b)
			{
				b=k;
				c++;
			}
		}
	}
	cout<<c<<'\n';
}