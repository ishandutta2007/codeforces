#include <iostream>

using namespace std;

int main()
{
	long long n,z=5,c=1;
	string s[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
	
	cin>>n;
	while(n>z)
	{
		n-=z;
		c*=2;
		z*=2;
	}
	cout<<s[(n-1)/c]<<'\n';
}