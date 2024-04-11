#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long a,b,c,i,j,r,k,z=0;
	
	cin>>a>>b>>c;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			if(j==0)
			{
				k=a+b;
			}
			else
			{
				k=a*b;
			}
			for(r=0;r<2;r++)
			{
				if(r==0)
				{
					k+=c;
				}
				else
				{
					k-=c;
					k*=c;
				}
				if(k>z)
				{
					z=k;
				}
			}
		}
		swap(a,c);
	}
	cout<<z<<endl;
}