#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>

#include <cassert>
#include <cmath>

using namespace std;

struct comp
{
    bool operator ()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return make_pair (a.first * (long long)a.second, a) >
            make_pair (b.first * (long long)b.second, b);
    }
};

vector<int> gen (int n, int k)
{
    vector<int> arr (n);

    for (int i = 0; i < (int)arr.size (); i++)
        arr[i] = min ((int)arr.size () - k, i) + 1 - max (i - k + 1, 0);

    for (auto &it : arr)
        it = max (it, 0);

    vector<int> ans (*max_element (arr.begin (), arr.end ()) + 1);

    for (auto it : arr)
        ans[it]++;

    return ans;
}

long long howmuch (int k, int x, int y)
{
    static vector<int> n = gen (x, k), m = gen (y, k);

    return x < (int)n.size () && y < (int)m.size () ? n[x] * (long long)m[y] : 0;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, m, r, k;

    cin >> n >> m >> r >> k;

    howmuch (r, n, m);

    double E = 0;

    set<pair<int, int>, comp> pq;

    pq.emplace (min (n - r + 1, r), min (m - r + 1, r));

    while (k > 0)
    {
        auto t = *pq.begin ();
        pq.erase (pq.begin ());

        if (min (t.first, t.second) > 0)
        {
            pq.emplace (t.first - 1, t.second);
            pq.emplace (t.first, t.second - 1);
        }

        auto q = int (min (howmuch (r, t.first, t.second), (long long)k));

        E += q * double (t.first * (long long)t.second);

        k -= q;
    }

    cout.precision (20);
    cout << fixed << E / ((n - r + 1ll) * (m - r + 1)) << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

    return 0;
}