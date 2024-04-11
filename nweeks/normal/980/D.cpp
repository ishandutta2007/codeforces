#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
const int PREF = 1e8;
int arr[MAXN];
int sol[MAXN+1];
bool seen[(int)2e8];

void transform(int &x)
{
	if (x == 0)
	{
		x = 1e9;
		return ;
	}
	bool neg = (x<0 ? true : false);
	x = abs(x);
	list<int> factors;
	for (int i(2); i*i <= x; ++i)
		if (x % i == 0)
		{
			bool keep = false;
			while (x % i == 0)
			{
				x /= i;
				keep ^= 1;
			}
			if (keep)
				factors.push_back(i);
		}
	if (x != 1)
		factors.push_back(x);
	if (factors.empty())
	{
		if (x == 1)
			x = neg ? -1 : 1;
		else
			x = neg ? -1e9 : 1e9;
	}
	else
	{
		x = neg ? -1 : 1;
		for (auto e : factors)
			x *= e;
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i(0); i < N; ++i)
	{
		cin >> arr[i];
		transform(arr[i]);
	}

	for (int i(0); i < N; ++i)
	{
		int sz(0);
		for (int j(0); j < N; ++j)
			if (abs(arr[j]) != 1e9)
				seen[PREF + arr[j]] = false;
		bool neg_zero = false, positive_zero = false;
		bool ato = false;
		for (int j(i); j < N; ++j)
		{
			if (arr[j] < 0 and arr[j] != -1e9)
				ato = true;
			if (arr[j] == 1e9)
				positive_zero = true;
			else if (arr[j] == -1e9)
				neg_zero = true;
			else if (!seen[arr[j]+PREF])
				seen[arr[j] + PREF] = true, sz++;
			int ans = 0;
			if (sz == 0)
				ans = positive_zero + neg_zero;
			else
				ans = sz + (ato ? 0 : neg_zero);
			sol[ans]++;
		}
	}
	for (int i(1); i <= N; ++i)
		cout << sol[i] << ' ';
	cout << endl;
}