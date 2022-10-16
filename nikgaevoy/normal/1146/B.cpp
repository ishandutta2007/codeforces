#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	string s;

	cin >> s;

	int a = count(s.begin(), s.end(), 'a');

	auto t = s.substr(0, (s.size() + a) / 2);

	string tp = "";

	for (auto it : t)
		if (it != 'a')
			tp += it;

	cout << (t + tp == s ? t : ":(") << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}