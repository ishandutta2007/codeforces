#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int ans = 0;
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 5; j++)
		{
			int x;
			cin >> x;
			if(x == 1)
				ans = abs(3 - i) + abs(3 - j);
		}
	cout << ans << endl;
	return 0;
}