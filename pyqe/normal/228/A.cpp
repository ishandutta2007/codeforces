#include <iostream>
#include <map>

using namespace std;

int main()
{
	long long i,k,c=0;
	map <int,bool> m;
	
	for(i=0;i<4;i++)
	{
		cin>>k;
		if(m[k]==0)
		{
			m[k]=true;
		}
		else
		{
			c++;
		}
	}
	cout<<c<<'\n';
}