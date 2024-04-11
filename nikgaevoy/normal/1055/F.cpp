#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


ull foo(const vector<ull> &arr, ll k)
{
	ull ans = 0;

	for (unsigned cur = 62;; cur--)
	{
		auto mask = ~((1ull << cur) - 1);

		auto cnt_mask = [&arr, &cur](ull q)
		{
			auto r = lower_bound(arr.begin(), arr.end(), q + (1ull << cur));
			return r != arr.begin() && *(r - 1) >= q ? r - lower_bound(arr.begin(), r, q) : 0;
		};

		ll zer = 0;

		auto mem = numeric_limits<ull>::max();
		int val = 0;

		for (auto it : arr)
		{
			auto q = (it ^ ans) & mask;

			if (q != mem)
			{
				mem = q;
				val = cnt_mask(mem);
			}

			zer += val;
		}

		if (k >= zer)
		{
			ans += 1ull << cur;
			k -= zer;
		}

		if (cur == 0)
			break;
	}

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	ll k;

	cin >> n >> k;
	k--;

	vector<ull> arr(n);

	for (int i = 1; i < arr.size(); i++)
	{
		int p;

		cin >> p >> arr[i];
		p--;

		arr[i] ^= arr[p];
	}

	sort(arr.begin(), arr.end());

	unordered_map<ull, vector<ull>::const_iterator> mem;

	cout << foo(arr, k) << endl;
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	ll k;

	cin >> n >> k;
	k--;

	vector<ull> arr(n);

	for (int i = 1; i < arr.size(); i++)
	{
		int p;

		cin >> p >> arr[i];
		p--;

		arr[i] ^= arr[p];
	}

	vector<ull> paths;
	paths.reserve(arr.size() * arr.size());

	for (auto it : arr)
		transform(arr.begin(), arr.end(), back_inserter(paths), [it](ull q)
		{
			return q ^ it;
		});

	sort(paths.begin(), paths.end());

	cout << paths[k] << endl;
}


void gen(ostream &cout = std::cout)
{
	const int n = 1e6;
	const ll k = uniform_int_distribution<ll>{1, n * (ll) n}(mt);

	cout << n << ' ' << k << endl;

	uniform_int_distribution<ull> w(0, (1ull << 62u) - 1);

	for (int i = 1; i < n; i++)
		cout << uniform_int_distribution<int>{1, i}(mt) << ' ' << w(mt) << endl;
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

	stringstream ss;

	gen(ss);

	solve(ss);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}