#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(int argc, char** argv) 
{
	int n;
	cin>>n;
	int m[367],z[367],a[n],b[n],max=0,k;
	char c[n];
	fill(m,m+367,0);
	fill(z,z+367,0);
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		cin>>a[i];
		cin>>b[i];
		for(int j=a[i];j<=b[i];j++)
		{
			if (c[i]=='M')
			{
				m[j]++;
			}
			else
			{
				z[j]++;
			}
		}
	}
	for (int i=1;i<=366;i++)
	{
		k=fmin(m[i],z[i]);
		max=max>k?max:k;
		k=0;
	}
	max=2*max;
	cout<<max;
	return 0;
}