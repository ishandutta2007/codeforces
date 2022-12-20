#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long n,K;
	cin >> n >> K;
	long long ans = 0;
	if(K >= 1) ans += 1;
	if(K >= 2) ans += (n*(n-1))/2;
	if(K >= 3) ans += (n*(n-1)*(n-2))/3;
	if(K >= 4) ans += (n*(n-1)*(n-2)*(n-3))/4;
	if(K >= 4) ans += (n*(n-1)*(n-2)*(n-3))/8;
	cout << ans << '\n';
}