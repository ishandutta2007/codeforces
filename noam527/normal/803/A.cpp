#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, place = 0, place2, matrix[100][100];

int main()
{
	cin >> n >> k;
	if (n * n < k)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) matrix[i][j] = 0;
	while (k > 0 && place < n)
	{
		matrix[place][place] = 1;
		k--;
		if (k >= 2)
		{
			place2 = place + 1;
			while (k > 1 && place2 < n)
			{
				matrix[place][place2] = 1;
				matrix[place2][place] = 1;
				k -= 2;
				place2++;
			}
		}
		place++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}