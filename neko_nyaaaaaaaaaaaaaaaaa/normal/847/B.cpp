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
		while (right - 1 > 0 && a[right] < a[right - 1])
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
				left++;
			}
		}
	}
	cout << result << endl;
	cin >> n;
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

void B()
{
	int n;
	cin >> n;
	vector<vector<int>> result;
	int levels = (int)ceil(log(n) / log(2)) + 1;
	vector<vector<int>> tree;
	for (int i = 0; i < levels; i++)
	{
		int nmem = (int)pow(2, i);
		vector<int> te;
		for (int j = 0; j < nmem; j++)
			te.push_back(0);
		tree.push_back(te);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		int k = 0;
		int l = 0;
		if (tree[0][0] == 0 || tree[0][0] > a)
		{
			k = result.size();
			vector<int> v;
			v.push_back(a);
			result.push_back(v);
		}
		else
		{
			k = 0, l = 0;
			while (l + 1 < levels)
			{
				l++;
				k *= 2;
				if (tree[l][k] > a)
					k++;
			}
			result[k].push_back(a);
		}
		l = levels - 1;
		tree[l][k] = a;
		while (l > 0)
		{
			l--;
			k /= 2;
			if (tree[l + 1][2 * k + 1] == 0 || tree[l + 1][2 * k] < tree[l + 1][2 * k + 1])
				tree[l][k] = tree[l + 1][2 * k];
			else
				tree[l][k] = tree[l + 1][2 * k + 1];
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	B();
	return 0;
}