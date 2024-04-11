#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	auto last = -1;
	bool res = false;

	auto ask = [&](int bit)
	{
		vector<int> q;

		for (int i = 1; i <= n; i++)
			if (i & (1u << bit))
				q.push_back(i);

		if (q.empty())
			return false;

		last = bit;

		cout << "? " << q.size();

		for (auto it: q)
			cout << ' ' << it;
		cout << endl;

		string str;

		cin >> str;

		return res = (str == "YES");
	};

	vector<bool> val(17);
	vector<int> ref(17);

	set<int> unk;

	for (int i = 0; i < ref.size(); i++)
		unk.insert(i);

	while (unk.size() > 1)
	{
		auto a = unk.contains(last) ? last : *unk.begin();
		int b;

		{
			auto it = unk.begin();

			while (*it == a)
				++it;

			b = *it;
		}

		cerr << a << ' ' << b << endl;

		auto q = a == last ? res : ask(a);
		auto w = ask(b);
		auto e = ask(b);

		if (w == e)
		{
			unk.erase(b);
			val[b] = w;
			ref[b] = b;
		}
		else
		{
			auto r = ask(a);

			if (q == r)
			{
				unk.erase(a);
				val[a] = q;
				ref[a] = a;
			}
			else
			{
				unk.erase(b);
				ref[b] = q == e ? a : ~a;
			}
		}
	}

	assert(unk.size() == 1);

	function<bool(int)> get = [&](int v) -> bool
	{
		if (v == *unk.begin() || ref[v] == v)
			return val[v];
		return ref[v] < 0 ? !get(~ref[v]) : get(ref[v]);
	};

	auto answer = [&](int val)
	{
		cerr << "answer " << val << endl;

		if (val < 1 || n < val)
			return false;

		cout << "! " << val << endl;

		string res;

		cin >> res;

		return res == ":)";
	};

	int ans = 0;

	for (int i = 0; i < ssize(val); i++)
		ans |= (get(i) ? 1 : 0) << i;

	if (answer(ans))
		return;

	ans = 0;
	val[*unk.begin()] = true;

	for (int i = 0; i < ssize(val); i++)
		ans |= (get(i) ? 1 : 0) << i;

	if (answer(ans))
		return;

	assert(false);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	solve();

#ifdef STRESS
	for (int cnt = 1;; cnt++)
	{
		stringstream ss, in1, out1, in2, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail: " << cnt << endl;
			cout << ss.str();
			cout << "solve:" << endl;
			cout << out1.str();
			cout << "stress:" << endl;
			cout << out2.str();

			break;
		}
		else if (cnt % 100 == 0)
			cout << "ok: " << cnt << endl;
	}
#endif

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}