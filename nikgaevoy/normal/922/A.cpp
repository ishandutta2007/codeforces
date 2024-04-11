#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int x, y;
	
	cin >> x >> y;
	y--;
	
	if (y < 0 || y == 0 && x != 0)
	{
		cout << "No" << endl;
		
		return;
	}
	else if (y == 0 && x == 0)
	{
		cout << "Yes" << endl;
		
		return;
	}
	
	x--;
	y--;
	
	if (x < 0)
	{
		cout << "No" << endl;
		
		return;
	}
	
	cout << (y > x || (x + y) % 2 == 1 ? "No" : "Yes") << endl;
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