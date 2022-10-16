#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
T remin(T &x, const T &y)
{
	return x = min(x, y);
}


template<class T>
T remax(T &x, const T &y)
{
	return x = max(x, y);
}


pair<int, int> slv(const pair<int, int> &a, pair<int, int> b, const int va, int vb)
{
	assert(a.first == 0 || a.second == 0);

	auto memb = b;
	auto memvb = vb;

	if (a.first == 1 && b.first == 1)
	{
		b.first = 0;
		vb -= va;
	}
	else if (a.second == 1 && b.second != 0)
	{
		b.second = 0;
		vb += va;
	}

	pair<int, int> ans;

	if (a.first == 0)
		ans.second = va / a.second;
	else
		ans.first = va / a.first;

	if (b.first == 0)
		ans.second = vb / b.second;
	else
		ans.first = vb / b.first;

	assert(a.first * ans.first + a.second * ans.second == va);
	assert(memb.first * ans.first + memb.second * ans.second == memvb);

	return ans;
}


pair<int, int> check(const vector<pair<int, int>> &arr, int t)
{
	const vector<pair<int, int>> func = {{1, 0},
	                                     {0, 1},
	                                     {1, -1}};

	vector<int> bndl(func.size(), numeric_limits<int>::max()), bndr(func.size(), numeric_limits<int>::min());

	for (auto it : arr)
	{
		for (int i = 0; i < func.size(); i++)
		{
			remin(bndl[i], it.first * func[i].first + it.second * func[i].second);
			remax(bndr[i], it.first * func[i].first + it.second * func[i].second);
		}
	}

	for (auto &it : bndl)
		it += t;
	for (auto &it : bndr)
		it -= t;

	for (int i = 0; i < func.size(); i++)
		if (bndl[i] < bndr[i])
			return {-1, -1};

	vector<pair<int, int>> cand = {{0, 0}};

	for (int i = 0; i < func.size(); i++)
		for (int j = i + 1; j < func.size(); j++)
		{
			cand.push_back(slv(func[i], func[j], bndl[i], bndl[j]));
			cand.push_back(slv(func[i], func[j], bndl[i], bndr[j]));
			cand.push_back(slv(func[i], func[j], bndr[i], bndl[j]));
			cand.push_back(slv(func[i], func[j], bndr[i], bndr[j]));
		}

	int to = cand.size();

	const int sz = 2;

	for (int j = 0; j < to; j++)
		for (int dx = -sz; dx <= sz; dx++)
			for (int dy = -sz; dy <= sz; dy++)
				cand.push_back({cand[j].first + dx, cand[j].second + dy});

	for (auto it : cand)
		if (it.first >= 0 && it.second >= 0 && (it.first > 0 || it.second > 0))
		{
			bool ok = true;

			for (int i = 0; ok && i < func.size(); i++)
				ok &= (bndl[i] >= func[i].first * it.first + func[i].second * it.second &&
				       func[i].first * it.first + func[i].second * it.second >= bndr[i]);

			if (ok)
				return it;
		}

	cerr << "wut?\t" << t << endl;

	return {-1, -1};
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> arr(n);

	for (auto &it : arr)
	{
		string str;

		cin >> str;

		it = {count(str.begin(), str.end(), 'B'), count(str.begin(), str.end(), 'N')};

		assert(it.first + it.second == str.size());
	}

	int l = -1, r = (int) 5e5 + 1;

	while (l + 1 < r)
	{
		int t = (l + r) / 2;

		if (check(arr, t).first == -1)
			l = t;
		else
			r = t;
	}

	cout << r << endl;

	auto ans = check(arr, r);

	cerr << ans.first << ' ' << ans.second << endl;

	cout << string(ans.first, 'B') << string(ans.second, 'N') << endl;
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