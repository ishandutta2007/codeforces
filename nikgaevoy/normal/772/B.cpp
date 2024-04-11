#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <cstdio>
#include <ctime>
#include <cassert>

using namespace std;

const int inf = int (1e9) + 7;

pair<int, int> operator- (const pair<int, int> &a, const pair<int, int> &b)
{
    return {a.first - b.first, a.second - b.second};
}

long long len2 (const pair<int, int> &a)
{
    return a.first * (long long)a.first + a.second * (long long)a.second;
}

double triang (pair<int, int> a, pair<int, int> b)
{
    long long S2 = abs (a.first * (long long)b.second - a.second * (long long)b.first);

    auto h = max (max (len2 (a), len2 (b)), len2 (a - b));

    return S2 / sqrt (h);
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<pair<int, int>> polygon (n);

    for (auto &it : polygon)
        cin >> it.first >> it.second;

    polygon.insert (polygon.end (), polygon.begin (), polygon.begin () + 2);

    double ans = numeric_limits<double>::infinity ();

    for (int i = 2; i < polygon.size (); i++)
        ans = min (ans, triang (polygon[i - 2] - polygon[i], polygon[i - 1] - polygon[i]));

    cout.precision (10);
    cout << fixed << ans / 2 << endl;

    return 0;
}