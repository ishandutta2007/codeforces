#include <iostream>

using namespace std;

long long N;

int main ()
{
	long long p = 1;
	cin >> N;
	for (long long i = 2; i <= 1000000; i++)
	{
		if (N % i == 0)
		{
			p *= i;
			while (N % i == 0) N /= i;
		}
	}
	cout << N * p << endl;
}