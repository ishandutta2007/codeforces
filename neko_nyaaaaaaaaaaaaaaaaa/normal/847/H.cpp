#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void H()
{
	int n;
	int a[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long result = 0;
	int left = 0, right = n - 1;
	while (left < right)
	{
		while (left + 1 < n && a[left] < a[left + 1])
			left++;
		while (right - 1 >= 0 && a[right] < a[right - 1])
			right--;
		if (left < right)
		{
			if (a[left] <= a[right])
			{
				int inc = a[left] + 1 - a[left + 1];
				a[left + 1] += inc;
				result += inc;
				left++;
			}
			else
			{
				int inc = a[right] + 1 - a[right - 1];
				a[right - 1] += inc;
				result += inc;
				right--;
			}
		}
	}
	cout << result << endl;
}

void C()
{
	long long n, k;
	cin >> n >> k;
	vector<long long> result;
	long long sum = 0;
	while (k > 0)
	{
		long long c = (long long)(sqrt(0.25 + 2 * k) - 0.5);
		k -= c * (c + 1) / 2;
		c++;
		result.push_back(c);
		sum += c;
	}
	if (sum <= n)
	{
		for (int i = 0; i < result.size(); i++)
		{
			for (long long j = 0; j < result[i]; j++)
				cout << '(';
			for (long long j = 0; j < result[i]; j++)
				cout << ')';
		}
		for (int i = sum; i < n; i++)
			cout << "()";
		cout << endl;
	}
	else
		cout << "Impossible" << endl;
	cin >> n;
}

int main()
{
	H();
	return 0;
}