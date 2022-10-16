#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb push_back
#define sz(c) ((int)(c).size())

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;
    string s;

    cin >> n >> s;

    vector<int> cnt_d(n + 1);
    for (int i = 0; i < n; i++)
        cnt_d[__gcd(n, i)]++;

    int ans = 0;

    for (int d = 1; d <= n; d++)
    if (n % d == 0)
    {
        bool ok = true;
        for (int i = 0; i < d; i++)
        {
            int cnt = 0;
            for (int j = i; j < n; j += d)
                cnt ^= (s[j] - '0');
            ok &= (cnt == 0);
        }

        if (ok)
            ans += cnt_d[d];
    }

    cout << ans << endl;
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