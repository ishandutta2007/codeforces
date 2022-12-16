#include <iostream>

using namespace std;

int N, A[10000], T = 0;
bool P[10000] = {false};

int main ()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	int s = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			if (A[j] <= s && P[j] == false)
			{
				s++;
				P[j] = true;
			}
		if (s < N)
			T++;
		else
			break;
		for (int j = N; j >= 1; j--)
			if (A[j] <= s && P[j] == false)
			{
				s++;
				P[j] = true;
			}
		if (s < N)
			T++;
		else
			break;
	}
	cout << T << endl;
}