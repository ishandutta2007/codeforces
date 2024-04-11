#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n,i,j,k,r,rr;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		r=sqrt(k);
		if(k!=1&&r*r==k)
		{
			for(j=2;j*j<=r;j++)
			{
				if(r%j==0)
				{
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				cout<<"YES\n";
				continue;
			}
		}
		cout<<"NO\n";
	}
}