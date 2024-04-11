#include <iostream>

using namespace std;

int main()
{
	long long i,j,n,k,b,m;
	
	cin>>n;
	m=0;
	for(i=0;i<n;i++)
	{
		b=0;
		for(j=0;j<3;j++)
		{
			cin>>k;
			b+=k;
		}
		if(b>=2)
		{
			m++;
		}
	}
	cout<<m<<endl;
}