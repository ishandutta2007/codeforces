#include <iostream>

using namespace std;

int main()
{
	long long n;
	
	cin>>n;
	if(n%2==1)
	{
		n*=-1;
		n-=1;
	}
	n/=2;
	cout<<n<<endl;
}