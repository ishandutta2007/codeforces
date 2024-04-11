#include <iostream>

using namespace std;

int main()
{
	long long m,n,i,k,p=1,c=0;
	
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>k;
		if(k>=p)
		{
			c+=k-p;
		}
		else
		{
			c+=n-p+k;
		}
		p=k;
	}
	cout<<c<<'\n';
}