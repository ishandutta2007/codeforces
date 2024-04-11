#include <iostream>

using namespace std;

int A[1100];
int K[1100] = {0};

int main ()
{
	int N, M;
	
	cin >> N >> M;
	if (N >= M)
	{
		cout << "YES" << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		if (K[A[i] % M] == 0) K[A[i] % M] = i;
		for (int j = 0; j < M; j++)
			if (K[j] > 0 && K[j] < i)
			{
				if (K[(j + A[i] % M) % M] == 0)
					K[(j + A[i] % M) % M] = i;
			}
	}
	if (K[0] > 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}