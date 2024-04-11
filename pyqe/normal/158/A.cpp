#include <iostream>

using namespace std;

int main()
{
	long long n,k,i,c=0,b,m;
	
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>m;
		if(m>0)
		{
			if(i<k)
			{
				c++;
				if(i==k-1)
				{
					b=m;
				}
			}
			else if(m==b)
			{
				c++;
			}
		}
	}
	cout<<c<<endl;
}