#include <iostream>

using namespace std;

int n , a[102];
int ans = 0;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		if(a[i] + a[i + 1] == 5)
		{
			cout << "Infinite" << endl;
			return 0;
		}
		ans += a[i] + a[i + 1];
	}
	for(int i = 1; i <= n - 2; i++)	
		if(a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2)
			ans--;
	cout << "Finite" << endl;
	cout << ans << endl;
	return 0;
}