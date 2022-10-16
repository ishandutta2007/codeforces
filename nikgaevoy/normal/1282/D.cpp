#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	cout << "a" << endl;

	int siz, a, b;

	cin >> siz;

	if (siz == 0)
		return;

	cout << string(siz, 'b') << endl;

	cin >> a;

	if (a == 0)
		return;

	siz++;
	b = siz - a;

	if (a == 0 || b == 0)
	{
		cout << string(a, 'a') + string(b, 'b') << endl;

		return;
	}

	string str(siz, 'b');
	int last = a;

	for (int i = 0; i < str.size(); i++)
	{
		str[i] = 'a';

		cout << str << endl;

		int cur;

		cin >> cur;

		if (cur == 0)
			return;

		if (cur < last)
			last = cur;
		else
			str[i] = 'b';
	}
}


int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve();

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}