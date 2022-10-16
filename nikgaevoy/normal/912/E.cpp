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

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

bool safemult (long long a, long long b)
{
    return numeric_limits<long long>::max () / a >= b;
}

vector<long long> foo (const vector<unsigned> &p)
{
    vector<long long> ans;

    minheap<long long> pq;
    pq.emplace (1);

    while (!pq.empty ())
    {
        auto t = pq.top ();

        while (!pq.empty () && pq.top () == t)
            pq.pop ();

        for (auto it : p)
            if (safemult (t, it))
                pq.push (t * it);
            else
                break;

        ans.push_back (t);
    }

    return ans;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<unsigned> p (n);

    for (auto &it : p)
        cin >> it;

    int k;

    cin >> k;

    vector<unsigned> a, b;

    for (size_t i = 0; i < p.size (); i++)
        (i & 1 ? a : b).push_back (p[i]);

    auto x = foo (a);
    auto y = foo (b);

    auto l = 0ll, r = (long long)1e18 + 1;

    while (l + 1 < r)
    {
        auto t = (l + r) / 2;

        int q = y.size () - 1;
        auto s = 0ll;

        for (size_t i = 0; i < x.size (); i++)
        {
            while (q >= 0 && (!safemult (x[i], y[q]) || x[i] * y[q] > t))
                   q--;

            s += q + 1;
        }

        (k <= s ? r : l) = t;
    }

    cout << r << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

    return 0;
}