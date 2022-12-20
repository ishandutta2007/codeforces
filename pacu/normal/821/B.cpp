#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m,b;
	cin >> m >> b;
	long long ans = 0;
	for(int x=0;x<=m*b;x++)
	{
		int y = -(x/m) + b;
		if(x > m*(b-y)) y--;
		ans = max(ans,(x+1)*((long long)(y+1))*((long long)(x+y)));
	}
	cout << ans/2 << '\n';
}