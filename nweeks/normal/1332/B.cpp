#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int primes[11] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	vector<int> numbers[11];
	for (auto v : arr)
	{
		int i(0);
		while (i < 11 and v % primes[i])
			++i;
		assert( i < 11);
		numbers[i].push_back(v);
	}

	int cnt(0);
	for (int i(0); i < 11; ++i)
		cnt += SZ(numbers[i])>0;
	cout << cnt << '\n';
	int color[11];
	int prev(0);
	for (int i(0); i < 11; ++i)
		if (SZ(numbers[i]) > 0)
			color[i] = ++prev;
	
	for (auto v : arr)
	{
		int i(0);
		while (i < 11 and v%primes[i])
			++i;
		assert(i < 11);
		cout << color[i] << ' ';
	}
	cout << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}