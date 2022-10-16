#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long a[2],n;
	bool g=0;
	
	cin>>a[0]>>a[1]>>n;
	while(n>=0)
	{
		n-=__gcd(a[g],n);
		g=!g;
	}
	cout<<g<<'\n';
}