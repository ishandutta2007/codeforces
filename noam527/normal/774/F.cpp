#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, a[50005], b[50005], minv = 1000000007, tosub;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n % 7 == 0)
	{
		int day = 0;
		for (int i = 0; i < n / 7; i++)
			for (int j = 0; j < 6; j++)
				b[i * 6 + j] = a[i * 7 + j];
		for (int i = 0; i < n - n / 7; i++)
			if (b[i] < minv)
			{
				minv = b[i];
				day = i + i / 6;
			}
		cout << day + 1 << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
			minv = min(minv, a[i]);
		tosub = (minv - 1) / 6 * 6;
		for (int i = 0; i < n; i++)
			a[i] -= tosub;
		int j = 0, day = 1;
		a[0]--;
		while (a[j] > 0)
		{
			j = (j + 1) % n;
			day = (day + 1) % 7;
			if (day != 0)
				a[j]--;
		}
		cout << j + 1 << endl;
	}
}