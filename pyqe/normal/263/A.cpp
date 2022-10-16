#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i,j,k,l,m;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cin>>k;
			if(k==1)
			{
				l=i;
				m=j;
			}
		}
	}
	cout<<abs(l-2)+abs(m-2)<<endl;
}