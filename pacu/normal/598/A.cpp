#include <iostream>
using namespace std;

long long solve(long long n)
{
	long long ans = (n*(n+1))/2;
	long long c = 1;
	while(c <= n)
		c *= 2;
	ans -= 2*(c-1);
	return ans;
}

int main()
{
	int t;
	long long n;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n;
		cout << solve(n) << '\n';
	}
}