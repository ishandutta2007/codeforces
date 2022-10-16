#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb push_back
#define sz(c) ((int)(c).size())

struct ship
{
    int id, atk;

    bool operator < (const ship &o) const
    {
        return atk < o.atk;
    }
};

struct base
{
    int gold, def;

    bool operator < (const base &o) const
    {
        return def < o.def;
    }
};

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;
    cin >> n;

    const int m = 4 * n + 1;
    vector<int> ox(m), oy(m);

    for (int i = 0; i < m; i++)
        cin >> ox[i] >> oy[i];

    for (int i = 0; i < m; i++)
    {
        auto x = ox, y = oy;
        x.erase(x.begin() + i);
        y.erase(y.begin() + i);

        const int minx = *min_element(x.begin(), x.end());
        const int maxx = *max_element(x.begin(), x.end());
        const int miny = *min_element(y.begin(), y.end());
        const int maxy = *max_element(y.begin(), y.end());

        bool ok = ((maxy - miny) == (maxx - minx));
        for (int j = 0; j < sz(x); j++)
        {
            bool hor = (x[j] == maxx || x[j] == minx);
            bool ver = (y[j] == maxy || y[j] == miny);
            ok &= (hor || ver);
        }

        if (ok)
        {
            cout << ox[i] << ' ' << oy[i] << endl;
            return;
        }
    }

    assert(false);
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