#ifdef LOCAL
#include "stdafx.h"
#else
#include <bits/stdc++.h>
#endif // LOCAL

#define remin(x,y) x = std::min (x, y);
#define remax(x,y) x = std::max (x, y);


using namespace std;


mt19937 mt (736);

using ll = long long;



template<class T>
T sqr (T x)
{
    return x * x;
}


double pow09 (int y)
{
    static vector<double> dp = {1};

    if (y >= dp.size ())
    {
        pow09 (y - 1);
        dp.push_back (pow09 (y - 1) * 0.9);
    }

    return dp[y];
}


void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int tc;

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int n;

        cin >> n;

        pow09 (n);

        double c, t;

        cin >> c >> t;

        vector<pair<int, int>> prob (n);

        for (auto &it : prob)
            cin >> it.first >> it.second;

        sort (prob.begin (), prob.end (), greater<pair<int, int>> ());

        vector<vector<double>> dp (n + 1, vector<double> (10 * n + 1, numeric_limits<double>::max ()));

        dp[0][0] = 0;

        for (int j = 0; j < prob.size (); j++)
            for (int k = j; k >= 0; k--)
                for (int l = 0; l < dp[k].size (); l++)
                    if (dp[k][l] != numeric_limits<double>::max ())
                        remin (dp[k + 1][l + prob[j].second], dp[k][l] + prob[j].first / pow09 (k + 1));

        int ans = 0;

        for (int k = 0; k < dp.size (); k++)
            for (int l = ans + 1; l < dp[k].size (); l++)
                if (dp[k][l] != numeric_limits<double>::max ())
                {
                    auto q = t - k * 10;
                    double d = dp[k][l];

                    double w;

                    if (c * d < 1)
                        w = 0;
                    else
                        w = (sqrt (c * d) - 1) / c;

                    if (w + d / (c * w + 1) <= q)
                        remax (ans, l);
                }

        cout << ans << endl;
    }
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    ifstream fin ("input.txt");

    solve (fin);

    cout << setprecision (4) << "clock: " << clock () / (double)CLOCKS_PER_SEC << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}