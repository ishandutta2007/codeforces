#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);

const int mod = 1e9 + 7, mult = 736, omult = 273097828;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string str;

	cin >> str;

	map<int, int> pos;

	vector<int> cnt, ps(str.size() + 1), os(str.size() + 1), lb(str.size(), -1), rb(str.size(), -1);

	for (int l = 0, z = 0, r; l < str.size(); l = r)
	{
		if (str[l] == '1')
		{
			for (r = l; r < str.size() && str[r] == '1'; r++);

			if ((r - l) % 2 != 0)
			{
				assert(l == 0 || z > 0);
				pos[l] = cnt.size();
				cnt.push_back(z);
				z = 0;
			}

			for (int i = l; i < r; i++)
			{
				lb[i] = l;
				rb[i] = r;
			}
		}
		else
		{
			z++;
			r = l + 1;
		}
	}

	pos[str.size()] = cnt.size();

	for (int i = 1; i < ps.size(); i++)
	{
		ps[i] = ps[i - 1] + (str[i - 1] - '0');

		if (i % 2 == 0)
			os[i] = os[i - 1] + (str[i - 1] - '0');
		else
			os[i] = os[i - 1];
	}

	vector<int> pw(cnt.size() + 1), opw(cnt.size() + 1);
	opw[0] = pw[0] = 1;

	for (int i = 1; i < pw.size(); i++)
	{
		pw[i] = pw[i - 1] * (ll) mult % mod;
		opw[i] = opw[i - 1] * (ll) omult % mod;
	}

	vector<int> hs(cnt.size() + 1);

	for (int i = 1; i < hs.size(); i++)
		hs[i] = (hs[i - 1] + cnt[i - 1] * (ll) pw[i - 1]) % mod;

	int q;

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int a, b, len;

		cin >> a >> b >> len;
		a--;
		b--;

		int ca = ps[a + len] - ps[a];
		int cb = ps[b + len] - ps[b];
		int oa = os[a + len] - os[a];
		int ob = os[b + len] - os[b];

		if (a % 2 != 0)
			oa = ca - oa;
		if (b % 2 != 0)
			ob = cb - ob;

		if (ca != cb || oa != ob)
		{
			cout << "No\n";

			continue;
		}

		auto abeg = *pos.lower_bound(a + 1), aend = *pos.lower_bound(a + len);
		auto bbeg = *pos.lower_bound(b + 1), bend = *pos.lower_bound(b + len);

		auto add_odd_left = [&str, &rb, &len](int pos, int beg)
		{
			if (str[pos] == '0')
				return 0;
			if (str[pos] == '1' && beg != pos)
				return (min(rb[pos], pos + len) - pos) % 2;
			return 0;
		};

		auto check_right = [&str, &rb, &lb, &len](int pos, int beg)
		{
			return str[pos + len - 1] == '1' && lb[pos + len - 1] > pos &&
			       (rb[pos + len - 1] - lb[pos + len - 1]) % 2 != 0;
		};

		auto add_odd_right = [&str, &rb, &lb, &len, &check_right](int pos, int beg)
		{
			if (str[pos + len - 1] == '0')
				return 0;
			if (str[pos + len - 1] == '1' && lb[pos + len - 1] > pos &&
			    (rb[pos + len - 1] - lb[pos + len - 1]) % 2 == 0)
				return (pos + len - lb[pos + len - 1]) % 2;
			if (check_right(pos, beg))
				return (pos + len - lb[pos + len - 1]) % 2 == 0 ? -1 : 0;
			return 0;
		};

		int siza = max(0, aend.second - abeg.second) + add_odd_left(a, abeg.first) + add_odd_right(a, abeg.first);
		int sizb = max(0, bend.second - bbeg.second) + add_odd_left(b, bbeg.first) + add_odd_right(b, bbeg.first);
		if (check_right(a, abeg.first))
			aend.second--;
		if (check_right(b, bbeg.first))
			bend.second--;

		if (siza != sizb)
		{
			cout << "No\n";

			continue;
		}

		auto get_first = [&str, &lb, &rb, &ps](int pos, int len, int beg)
		{
			beg = min(beg, pos + len);
			if (str[pos] == '0' || (str[pos] == '1' && (min(rb[pos], pos + len) - pos) % 2 == 0))
				return make_tuple('0', beg - pos - (ps[beg] - ps[pos]));
			return make_tuple('1', beg - pos - (ps[beg] - ps[pos + 1]));
		};

		if (get_first(a, len, abeg.first) != get_first(b, len, bbeg.first))
		{
			cout << "No\n";

			continue;
		}

		auto get_hash = [&hs, &pw, &opw](int l, int r)
		{
			if (r <= l)
				return -1;

			return int((hs[r] - hs[l] + (ll) mod) * opw[l] % mod);
		};

		cout << (get_hash(abeg.second + 1, aend.second) == get_hash(bbeg.second + 1, bend.second) ? "Yes\n" : "No\n");
	}
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string str;

	cin >> str;

	auto mvones = [](string str)
	{
		bool loop = true;

		while (loop)
		{
			loop = false;

			for (int j = 0; j + 2 < str.size(); j++)
				if (str[j] == '1' && str[j + 1] == '1' && str[j + 2] == '0')
				{
					swap(str[j], str[j + 2]);
					loop = true;
				}
		}

		return str;
	};

	int q;

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int a, b, len;

		cin >> a >> b >> len;
		a--;
		b--;

		cout << (mvones(str.substr(a, len)) == mvones(str.substr(b, len)) ? "Yes\n" : "No\n");
	}
}


void gen(ostream &cout = std::cout)
{
	assert(mult * (ll) omult % mod == 1);

	string str(10, '0');

	uniform_int_distribution<char> type('0', '1');

	for (auto &it : str)
		it = type(mt);

	cout << str.size() << endl;
	cout << str << endl;

	const int q = 1;

	cout << q << endl;

	uniform_int_distribution<int> len(1, str.size());

	for (int i = 0; i < q; i++)
	{
		int l = len(mt);

		uniform_int_distribution<int> pos(1, str.size() + 1 - l);

		cout << pos(mt) << ' ' << pos(mt) << ' ' << l << endl;
	}
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

	int cnt = 0;

	while (true)
	{
		stringstream ss, in1, in2, out1, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "Fail: " << cnt << endl;
			cout << ss.str() << endl;
			cout << "solve" << endl;
			cout << out1.str() << endl;
			cout << "stress" << endl;
			cout << out2.str() << endl;

			break;
		}
		else if (++cnt % 10 == 0)
			cout << "Ok: " << cnt << endl;
	}

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}