#include <iostream>
using namespace std;

int main()
{
	long long p,k;
	cin >> p >> k;
	if(k==0)
	{
		long long ans = 1;
		for(int j=0;j<p-1;j++)
			ans = (ans*p)%1000000007;
		cout << ans << '\n';
		return 0;
	}
	int olen = 1;
	long long c = k;
	while(c != 1)
	{
		olen++;
		c = (c*k)%p;
	}
	int cosets = (p-1)/olen;
	long long ans = 1;
	for(int j=0;j<cosets;j++)
		ans = (ans*p)%1000000007;
	if(k==1)
		ans = (ans*p)%1000000007;
	cout << ans << '\n';
}