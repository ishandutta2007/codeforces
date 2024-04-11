#include <iostream>

using namespace std;

int main()
{
	long long r,k,c=1;
	
	cin>>r>>k;
	r%=10;
	k%=10;
	while((r*c)%10!=k&&(r*c)%10!=0)
	{
		c++;
	}
	cout<<c<<endl;
}