#include <iostream>

using namespace std;

int main()
{
	int n , ans = 0;
	string last = "aa" , temp;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> temp;
		if(temp != last)
			ans++;
		last = temp;
	}
	cout << ans << endl;
	return 0;
}