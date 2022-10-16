#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb push_back
#define sz(c) ((int)(c).size())

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
    ll r;
    cin >> r;

    for (ll x = 1; x * x <= r; x++)
    {
        ll rest = r - x * x - x - 1;
        if (rest > 0 && rest % (2 * x) == 0)
        {
            cout << x << ' ' << rest / (2 * x) << endl;
            return;
        }
    }

    cout << "NO" << endl;
    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}