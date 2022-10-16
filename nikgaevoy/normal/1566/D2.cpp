#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


class segtree
{
	vector<int> arr;

public:
	explicit segtree(size_t n = 0) : arr(2 * n)
	{}

	void add(int wh, int x = 1)
	{
		wh += arr.size() / 2;

		while (wh > 0)
		{
			arr[wh] += x;
			wh /= 2;
		}
	}


	[[nodiscard]] int sum(int l, int r) const
	{
		l += arr.size() / 2;
		r += arr.size() / 2;

		int sum = 0;

		while (l < r)
		{
			if (l & 1)
				sum += arr[l++];
			if (r & 1)
				sum += arr[--r];

			l /= 2;
			r /= 2;
		}

		return sum;
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<int> arr(n * m);

	for (auto &it: arr)
		cin >> it;

	vector<int> ord(arr.size());

	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&arr](int a, int b)
	{
		if (arr[a] == arr[b])
			return a < b;
		return arr[a] < arr[b];
	});

	vector<int> mapping(ord.size(), -1);

	for (int l = 0, r; l < ord.size(); l = r)
	{
		for (r = l; r < ord.size() && arr[ord[l]] == arr[ord[r]]; r++);

		int cur = l;

		while (cur < r)
		{
			auto rb = cur - cur % m + m;
			rb = min(rb, r);

			auto pos = rb;

			while (cur < rb)
				mapping[ord[cur++]] = --pos;
		}
	}

	{
		auto tmp = mapping;
		sort(tmp.begin(), tmp.end());

		for (int i = 0; i < tmp.size(); i++)
			assert(tmp[i] == i);
	}

	vector<segtree> rows(n, segtree(m));

	int ans = 0;

	for (auto it: mapping)
	{
		auto rw = it / m;

		ans += rows[rw].sum(0, it % m);
		rows[rw].add(it % m);
	}

	cout << ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}