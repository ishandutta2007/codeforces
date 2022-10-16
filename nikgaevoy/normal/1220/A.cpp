#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string str;

	cin >> str;

	n = count(str.begin(), str.end(), 'n');
	int z = count(str.begin(), str.end(), 'z');

	for (int i = 0; i < n; i++)
		cout << "1 ";
	for (int i = 0; i < z; i++)
		cout << "0 ";
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4);
	cout << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}