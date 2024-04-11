#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <complex>

#include <cassert>

using namespace std;

const int inf = (int)1e9 + 7;
const double pi = 3.14159265358979323846;

template<class T>
T sqr (T x)
{
    return x * x;
}

double len (const pair<int, int> &p1, const pair<int, int> &p2)
{
    return sqrt (sqr ((long long)p1.first - p2.first) + sqr ((long long)p1.second - p2.second));
}

double foo (const vector<pair<int, int>> &pol, int l, int r, bool side)
{
    static vector<vector<vector<double>>> dp (2, vector<vector<double>> (2500, vector<double> (2501, -1)));

    if (r <= l + 1)
        return 0;

    if (l > (int)pol.size () / 2)
        return foo (pol, l - (pol.size () + 1) / 2, r - (pol.size () + 1) / 2, side);

    if (dp[side][l][r - l] == -1)
        if (side)
            dp[side][l][r - l] = max (len (pol[r - 1], pol[l]) + foo (pol, l, r - 1, 0),
                                      len (pol[r - 1], pol[r - 2]) + foo (pol, l, r - 1, 1));
        else
            dp[side][l][r - l] = max (len (pol[l], pol[l + 1]) + foo (pol, l + 1, r, 0),
                                      len (pol[l], pol[r - 1]) + foo (pol, l + 1, r, 1));

    return dp[side][l][r - l];
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<pair<int, int>> pol (n);

    for (auto &it : pol)
        cin >> it.first >> it.second;

    for (int i = 0; i < n - 1; i++)
        pol.push_back (pol[i]);

    double best = numeric_limits<double>::lowest ();

    for (int i = 0; i < n - 1; i++)
        best = max (best, max (foo (pol, i, i + n, 0), foo (pol, i, i + n, 1)));

    cout.precision (20);
    cout << fixed << best << endl;

    return 0;
}