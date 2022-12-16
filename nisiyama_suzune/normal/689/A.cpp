#include <iostream>

using namespace std;

int N;
bool A[20] = {false};

int main ()
{
	cin >> N;
	char c;
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		A[c - '0'] = true;
	}
	if (A[0])
	{
		if (!A[1] && !A[2] && !A[3])
		{
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		return 0;
	}
	if (A[7] == false && A[8] == true && A[9] == false)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (A[1] == false && A[2] == false && A[3] == false)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (A[1] == false && A[4] == false && A[7] == false)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (!A[3] && !A[6] && !A[9])
	{
		cout << "NO" << endl;
		return 0;
	}
	if (!A[7] && !A[8] && !A[9])
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}