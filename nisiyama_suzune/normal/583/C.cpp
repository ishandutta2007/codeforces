#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
int A[1000000];
int P[1000], PCount = 0;
map <int, int> M;

int gcd (int x, int y)
{
	if (x == 0) return y;
	if (y == 0) return x;
	if (x < y) return gcd (x, y % x);
	return gcd (x % y, y);
}

int main ()
{
	cin >> N;
	for (int i = 0; i < N * N; i++)
		cin >> A[i];
	sort (A, &A[N * N]);
	P[0] = A[N * N - 1]; PCount++;
	for (int i = N * N - 2; i >= 0; i--)
	{
		if (M[A[i]] == 0)
		{
			for (int j = 0; j < PCount; j++)
				M[gcd (A[i], P[j])] = M[gcd (A[i], P[j])] + 2;
			P[PCount] = A[i];
			PCount++;
			if (PCount == N) break;
		}
		else
			M[A[i]]--;
	}
	cout << P[0];
	for (int i = 1; i < N; i++) cout << " " << P[i];
	cout << endl;
}