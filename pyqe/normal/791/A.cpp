#include <iostream>

using namespace std;

int main()
{
	long long a,b,c=0;
	
	cin>>a>>b;
	while(a<=b)
	{
		a*=3;
		b*=2;
		c++;
	}
	cout<<c<<'\n';
}