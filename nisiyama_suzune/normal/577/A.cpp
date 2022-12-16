#include <iostream>

using namespace std;

int main ()
{
	int N, X;
	int ans = 0;
	cin >> N >> X;
	for (int i = 1; i <= N; i++)
		if (X % i == 0 && X / i <= N)
			ans++;
	cout << ans << endl;
	return 0;
}