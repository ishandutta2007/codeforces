#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	int l = 0, r = str.size() - 1;

	vector<int> pos;

	while (l <= r)
	{
		if (str[l] == str[r])
		{
			pos.push_back(l);
			pos.push_back(r);

			l++;
			r--;
		}
		else
		{
			if (str[l] == str[r - 1])
			{
				r--;
			}
			else if (str[l + 1] == str[r])
			{
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}

	sort(pos.begin(), pos.end());
	pos.resize(unique(pos.begin(), pos.end()) - pos.begin());

	for (auto it : pos)
		cout << str[it];
	cout << endl;
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

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}