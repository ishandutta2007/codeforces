
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n<m)
		cout<<"-1\n";
	else
	{
		n=(n+1)/2;
		while(n%m)
			n++;
		cout<<n;
	}
	return 0;
}