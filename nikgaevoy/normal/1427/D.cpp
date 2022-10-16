#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


auto erase_0(vector<int> &q)
{
	int sz = 0;

	for (int i = 0; i < q.size(); i++)
		if (q[i] != 0)
			q[sz++] = q[i];

	q.resize(sz);
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	vector<vector<int>> op;

	auto srt = arr;

	sort(srt.begin(), srt.end());

	auto make_op = [&arr](const vector<int> &op)
	{
		vector<vector<int>> tmp;

		int pos = 0;

		for (auto it : op)
		{
			tmp.emplace_back(arr.begin() + pos, arr.begin() + pos + it);
			pos += it;
		}

		assert(pos == arr.size());

		reverse(tmp.begin(), tmp.end());

		pos = 0;

		for (auto &row : tmp)
		{
			copy(row.begin(), row.end(), arr.begin() + pos);
			pos += row.size();
		}

		assert(pos == arr.size());
	};

	bool rev = false;

	while (arr != srt)
	{
		if (rev)
		{
			reverse(arr.begin(), arr.end());
		}

		int fp = 0;

		while (fp < arr.size() && arr[fp] == srt[fp])
			fp++;

		vector<int> add(fp, 1);

		if (fp < arr.size())
		{
			int ps = min_element(arr.begin() + fp, arr.end()) - arr.begin();

			add.push_back(ps + 1 - fp);
			add.push_back(arr.size() - ps - 1);
		}

		erase_0(add);

		if (rev)
		{
			reverse(add.begin(), add.end());
			reverse(arr.begin(), arr.end());
		}

		if (add.size() > 1)
		{
			op.push_back(add);
			make_op(add);
		}

		rev = !rev;
	}

	assert(op.size() <= arr.size());

	cout << op.size() << endl;

	for (const auto &row : op)
	{
		cout << row.size();

		for (auto it : row)
			cout << ' ' << it;

		cout << '\n';
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