#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n , ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string a;
		cin >> a;
		if(a[0] == 'T')
			ans += 4;
		else if(a[0] == 'C')
			ans += 6;
		else if(a[0] == 'O')
			ans += 8;
		else if(a[0] == 'D')
			ans += 12;
		else
			ans += 20;
	}
	cout << ans << endl;
	return 0;
}