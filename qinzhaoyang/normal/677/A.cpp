#include <iostream>

using namespace std;

int n , h , ans = 0;

int main()
{
	cin >> n >> h;
	for(int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if(temp > h)
			ans += 2;
		else
			ans++;
	}
	cout << ans << endl;
	return 0;
}