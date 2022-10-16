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
    int s, b;
    cin >> s >> b;

    vector<ship> ship(s);
    for (int i = 0; i < s; i++)
    {
        cin >> ship[i].atk;
        ship[i].id = i;
    }


    vector<base> base(b);
    for (int i = 0; i < b; i++)
    {
        cin >> base[i].def >> base[i].gold;
    }

    sort(ship.begin(), ship.end());
    sort(base.begin(), base.end());

    vector<int> ans(s);
    int ptr = 0, sum = 0;

    for (int i = 0; i < s; i++)
    {
        while (ptr < b && base[ptr].def <= ship[i].atk)
        {
            sum += base[ptr].gold;
            ptr++;
        }

        ans[ship[i].id] = sum;
    }

    for (int i = 0; i < s; i++)
        cout << ans[i] << " ";
    cout << endl;
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