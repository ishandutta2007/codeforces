#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n , cnt2 = 0 , cnt3 = 0;
		cin >> n;
		while(n % 2 == 0)
		{
			cnt2++;
			n /= 2;
		}
		while(n % 3 == 0)
		{
			cnt3++;
			n /= 3;
		}
		if(n > 1)
			cout << -1 << endl;
		else if(cnt2 > cnt3)
			cout << -1 << endl;
		else
			cout << 2 * cnt3 - cnt2 << endl;
	}
	return 0;
}