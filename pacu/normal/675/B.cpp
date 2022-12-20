#include <iostream>
using namespace std;

int main()
{
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	long long ans = 0;
	for(int i=1;i<=n;i++)
	{
		int k11 = i;
		int k13 = k11 + b - c;
		int k33 = k13 + a - d;
		int k31 = k33 + c - b;
		if(1 <= k13 && k13 <= n && 1 <= k33 && k33 <= n && 1 <= k31 && k31 <= n)
			ans += n;
	}
	cout << ans << '\n';
}