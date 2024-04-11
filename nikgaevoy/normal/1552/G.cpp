#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr string_view acc = "ACCEPTED", rej = "REJECTED";


template<size_t n>
bool foo(const vector<bitset<n>> &arr, int t = 0, const bitset<n> &zero = 0, const bitset<n> &one = 0)
{
	assert((zero & one).none());

	if (t == arr.size())
		return ((zero >> 1) & one).none() && (zero | one).all();

	const auto &row = arr[t];

	const auto zeros = (row & zero).count();
	const auto ones = (row & one).count();
	const auto all = row.count();

	auto no = one | row;
	auto nz = zero & ~row;

	if (zeros == 0 && !foo(arr, t + 1, nz, no))
		return false;

	for (int i = 0, cur = 0; i < n; i++)
		if (row[i])
		{
			nz[i] = true;
			no[i] = false;
			cur++;

			if (zeros <= cur && cur <= all - ones && !foo<n>(arr, t + 1, nz, no))
				return false;
		}

	return true;
}


template<int n>
void solve(int tn, int tk, istream &cin = std::cin, ostream &cout = std::cout)
{
	if constexpr(n == 1)
	{
		cout << acc << endl;

		return;
	}

	if (tn != n)
	{
		solve<max(0, n - 1)>(tn, tk, cin, cout);

		return;
	}

	vector<bitset<n>> arr(tk);

	for (auto &row : arr)
	{
		int q;

		cin >> q;

		for (int i = 0; i < q; i++)
		{
			int pos;
			cin >> pos;
			pos--;

			row[pos] = true;
		}
	}

	cout << (foo<n>(arr) ? acc : rej) << endl;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	solve<40>(n, k, cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}