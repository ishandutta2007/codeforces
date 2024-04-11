#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <complex>
#include <functional>
#include <queue>
#include <set>
#include <random>

#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>

#pragma warning (disable : 4018)
#pragma comment (linker, "/STACK:200000000")

using namespace std;

int main ()
{
    int n, start, x;

    cin >> n >> start >> x;

    vector<pair<int, int>> known;
    known.reserve (1000);
    unordered_set<int> q;
    q.reserve (1000);

    q.insert (start - 1);

    mt19937 mt (time (NULL));
    uniform_int_distribution<> dist (0, n - 1);

    if (n < 1900)
        for (int i = 0; i < n; i++)
            q.insert (i);
    else
        while (q.size () < 1000)
            q.insert (dist (mt));

    for (auto it : q)
    {
        cout << "? " << it + 1 << endl;
        cout.flush ();

        int val, nex;

        cin >> val >> nex;
        known.push_back ({val, nex});
    }

    sort (known.begin (), known.end ());

    int pos = lower_bound (known.begin (), known.end (), pair<int, int> { x, -2 }) - known.begin ();

    if (pos == 0)
        cout << "! " << known[0].first << endl;
    else
    {
        int val = known[--pos].first;
        int nex = known[pos].second;

        while (val < x)
        {
            if (nex == -1)
            {
                cout << "! -1" << endl;

                return 0;
            }

            cout << "? " << nex << endl;
            cout.flush ();

            cin >> val >> nex;

            assert (val != -1);
        }

        cout << "! " << val << endl;
    }

    return 0;
}