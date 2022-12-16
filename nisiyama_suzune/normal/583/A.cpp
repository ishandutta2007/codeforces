#include <iostream>

using namespace std;

bool L[100] = {false}, R[100] = {false};

int main ()
{
	int N, A, B;
	cin >> N;
	cin >> A >> B;
	L[A] = R[B] = true;
	cout << "1";
	for (int i = 2; i <= N * N; i++)
	{
		cin >> A >> B;
		if (L[A] == false && R[B] == false)
		{
			L[A] = R[B] = true;
			cout << " " << i;
		}
	}
}