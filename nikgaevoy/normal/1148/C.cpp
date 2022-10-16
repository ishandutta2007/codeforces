#include <bits/stdc++.h>

using namespace std;

using ll = long long;


vector<pair<int, int>> moves;


template<class T>
void swap(vector<T> &arr, int i, int j)
{
	const int n = arr.size();

	if (i == j)
		return;

	if (j < i)
		swap(i, j);

	swap(arr[i], arr[j]);

	if (2 * (j - i) >= n)
	{
		moves.emplace_back(i, j);

		return;
	}

	if (i + n / 2 < n)
	{
		if (j + n / 2 < n)
		{
			moves.emplace_back(i, n - 1);
			moves.emplace_back(j, n - 1);
			moves.emplace_back(i, n - 1);
		}
		else
		{
			moves.emplace_back(i, n - 1);
			moves.emplace_back(j, 0);
			moves.emplace_back(0, n - 1);
			moves.emplace_back(i, n - 1);
			moves.emplace_back(j, 0);
		}
	}
	else
	{
		moves.emplace_back(i, 0);
		moves.emplace_back(j, 0);
		moves.emplace_back(i, 0);
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> perm(n);

	for (auto &it : perm)
	{
		cin >> it;
		it--;
	}

	vector<int> wh(n);

	for (int i = 0; i < n; i++)
		wh[perm[i]] = i;

	for (int i = 0; i < (int)perm.size(); i++)
	{
		int j = wh[i];

		wh[perm[i]] = j;
		wh[i] = i;

		swap(perm, i, j);
	}

	assert(is_sorted(perm.begin (), perm.end ()));

	cout << moves.size () << endl;

	for (auto it : moves)
		cout << it.first + 1 << ' ' << it.second + 1 << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}