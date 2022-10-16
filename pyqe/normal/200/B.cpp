#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	long long n,i,k,z=0;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		z+=k;
	}
	cout<<setprecision(12)<<fixed<<(double)z/n<<'\n';
}