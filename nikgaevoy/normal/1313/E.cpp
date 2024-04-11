#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


vector<int> z_function(const string &str)
{
	vector<int> z(str.size());

	int pos = 0, rb = 0;

	for (int i = 1; i < z.size(); i++)
	{
		if (i < rb)
			z[i] = min(rb - i, z[i - pos]);

		while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]])
			z[i]++;

		if (i + z[i] > rb)
		{
			pos = i;
			rb = i + z[i];
		}
	}

	return z;
}


int up(int n)
{
	int r = 1;

	while (r < n)
		r *= 2;

	return r;
}


class segtree
{
	vector<ll> arr;


	ll sum(int l, int r, int cl, int cr, int v)
	{
		if (r <= cl || cr <= l)
			return 0;
		if (l <= cl && cr <= r)
			return arr[v];

		auto ct = (cl + cr) / 2;

		return sum(l, r, cl, ct, 2 * v) + sum(l, r, ct, cr, 2 * v + 1);
	}

public:
	segtree(int n) : arr(2 * up(n))
	{}

	void add(int wh, ll x)
	{
		wh += arr.size() / 2;

		while (wh > 0)
		{
			arr[wh] += x;
			wh /= 2;
		}
	}

	ll sum(int l, int r)
	{
		return sum(l, r, 0, arr.size() / 2, 1);
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	string a, b, s;

	cin >> a >> b >> s;

	auto pref = z_function(s + '#' + a);
	reverse(b.begin(), b.end());
	reverse(s.begin(), s.end());
	auto suff = z_function(s + '#' + b);

	pref.erase(pref.begin(), pref.begin() + s.size() + 1);
	suff.erase(suff.begin(), suff.begin() + s.size() + 1);

	reverse(suff.begin(), suff.end());
	reverse(b.begin(), b.end());
	reverse(s.begin(), s.end());

	vector<pair<int, int>> quer;
	quer.reserve(pref.size());

	for (int i = 0; i < pref.size(); i++)
		if (pref[i] > 0)
			quer.emplace_back(max((int)s.size() - pref[i], 1), i);

	sort(quer.begin(), quer.end(), greater<>());

	segtree st(b.size()), cnt(b.size());

	vector<pair<int, int>> pnt;
	pnt.reserve(suff.size());

	for (int i = 0; i < suff.size(); i++)
		if (suff[i] > 0)
			pnt.emplace_back(min((int) s.size() - 1, suff[i]), i);

	sort(pnt.begin(), pnt.end());

	ll ans = 0;

	for (auto it : quer)
	{
		while (!pnt.empty() && pnt.back().first >= max(1, it.first))
		{
			st.add(pnt.back().second, pnt.back().first + 1);
			cnt.add(pnt.back().second, 1);
			pnt.pop_back();
		}

		int l = it.second, r = min(b.size(), it.second + s.size() - 1);

		ans += st.sum(l, r) - cnt.sum(l, r) * it.first;

//		cerr << it.first << '\t' << it.second << endl;
//		cerr << ans << endl;
	}

	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}