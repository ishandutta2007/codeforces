#include <iostream>

using namespace std;

int N;
int A[200000], P[200000];

int main ()
{
	cin >> N;
	int m = 1000;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i] >> P[i];
		if (m > P[i]) m = P[i];
		ans += m * A[i];
	}
	cout << ans << endl;
}