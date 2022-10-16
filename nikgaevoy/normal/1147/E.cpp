#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const string test = "BG";


string ask_string(const vector<int> &q)
{
	string ans;

	for (int i = 1; i < (int) q.size(); i += 2)
		ans += test[q[i - 1]] == test[q[i]] ? '1' : '0';

	return ans;
}


string ask_cin(const vector<int> &q)
{
	int n = q.size();

	if (n < 2)
		return "";

	cout << "Q " << n / 2;

	for (int i = 1; i < n; i += 2)
		cout << ' ' << q[i - 1] + 1 << ' ' << q[i] + 1;
	cout << endl << flush;

	string ans;

	cin >> ans;

	return ans;
}


#ifdef LOCAL
auto ask = ask_string;
#else
auto ask = ask_cin;
#endif


string ask_row(vector<int> q)
{
	if (q.size() < 2)
		return "";

	string ans0, ans1;

	ans0 = ask(q);

	q.erase(q.begin());

	ans1 = ask(q);

	string ret;

	ret.reserve(ans0.size() + ans1.size());
	reverse(ans0.begin (), ans0.end ());
	reverse(ans1.begin (), ans1.end ());

	while (!ans0.empty())
	{
		ret += ans0.back();
		ans0.pop_back();

		if (!ans1.empty())
		{
			ret += ans1.back();
			ans1.pop_back();
		}
	}

	return ret;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

#ifdef LOCAL
	n = test.size();
#else
	cin >> n;
#endif

	if (n == 1)
	{
		cout << "A 1 0 0" << endl;
		cout << 1 << endl << endl << endl << flush;

		return;
	}

	vector<int> arr(n);

	iota(arr.begin(), arr.end(), 0);

	auto nc = ask_row(arr);

	vector<int> even = {0}, odd;

	for (int i = 0; i < (int) nc.size(); i++)
		if (nc[i] == '0')
		{
			odd.push_back(i + 1);
			odd.swap(even);
		}

	if (even[0] != 0)
		even.swap(odd);

	auto ec = ask_row(even);
	auto oc = ask_row(odd);

	vector<vector<int>> packs(3);
	packs[0] = {0};

	oc = '1' + oc;

	int cur = 0, prev = 1;
	int ep = 0, op = 0;

	for (int i = 1; i < n; i++)
	{
		if (nc[i - 1] == '0')
		{
			if (oc[op++] == '0')
			{
				int nxt = 3 - prev - cur;

				prev = cur;
				cur = nxt;
			}
			else
				swap(cur, prev);

			swap(ep, op);
			ec.swap(oc);
		}

		packs[cur].push_back(i);
	}

	cout << 'A';

	for (const auto &it : packs)
		cout << ' ' << it.size();
	cout << endl;

	for (const auto &row : packs)
	{
		for (auto it : row)
		{
			cout << it + 1 << ' ';

#ifdef LOCAL
			if (test[it] != test[row.front ()])
				cout << "(bad) ";
#endif
		}
		cout << endl;
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

#ifndef LOCAL
	cin >> t;
#endif

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve();

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}