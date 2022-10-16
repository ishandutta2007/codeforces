#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n,i=0,c=0;
	
	cin>>n;
	while(n>=0)
	{
		i++;
		c+=i;
		n-=c;
	}
	cout<<i-1<<endl;
}