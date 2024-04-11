#include <iostream>

using namespace std;

int main()
{
	long long i,n,k,m,c=1,b=1;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		if(i>0)
		{
			if(k<m)
			{
				if(c>b)
				{
					b=c;
				}
				c=1;
			}
			else
			{
				c++;
			}
			if(i==n-1)
			{
				if(c>b)
				{
					b=c;
				}
			}
		}
		m=k;
	}
	cout<<b<<endl;
}