#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

const ull bnd = 0.5e18;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int x;

	cin >> x;

	unordered_set<ull> board = {(ull) x};

	int cnt = 0;
	stringstream ans;

	auto make_xor = [&](ull a, ull b)
	{
		assert(board.count(a));
		assert(board.count(b));

		if (!board.count(a ^ b))
		{
			board.insert(a ^ b);

			ans << a << " ^ " << b << '\n';
			cnt++;
		}

		return a ^ b;
	};

	auto make_plus = [&](ull a, ull b)
	{
		assert(board.count(a));
		assert(board.count(b));

		if (!board.count(a + b))
		{
			board.insert(a + b);

			ans << a << " + " << b << '\n';
			cnt++;
		}

		return a + b;
	};

	auto last_bit = [](ull x)
	{
		return x ^ (x & (x - 1ull));
	};

	function<ull(ull)> first_bit = [&first_bit, &last_bit](ull x)
	{
		return x == last_bit(x) ? x : first_bit(x ^ last_bit(x));
	};

	auto gen_pw = [&make_plus](ull t)
	{
		while (t * 2 < bnd)
			t = make_plus(t, t);
	};

	make_xor(x, make_plus(x, x));

	ull q = 0;

	for (auto it : board)
		if (it % 4 == 1)
		{
			q = it;

			break;
		}

	assert(q != 0);

	gen_pw(q);

	{
		auto w = q * first_bit(q) / last_bit(q);

		q = make_xor(make_xor(make_plus(w, q), w), q);
	}

	assert(q == last_bit(q));

	gen_pw(q);

	while (!board.count(1))
	{
		q = 1;

		while (!board.count(q))
			q <<= 1u;

		ull w = x;

		while (2 * last_bit(w) < q)
		{
			make_plus(w, w);
			w *= 2;
		}

		auto lb = last_bit(w);

		while (w != lb)
			w = make_xor(w, last_bit(w ^ lb));
	}

	assert(cnt <= (int) 1e5);

	cout << cnt << endl << ans.str();
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