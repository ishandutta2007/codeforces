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

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, m;

    cin >> n >> m;

    vector<int> a (n), b (m);

    for (auto &i : a)
        cin >> i;

    for (auto &i : b)
        cin >> i;

    if (b.size () > 1)
        cout << "Yes" << endl;
    else
    {
        if (!b.empty ())
        {
            int t = find (a.begin (), a.end (), 0) - a.begin ();

            a[t] = b[0];
        }

        for (int i = 1; i < a.size (); i++)
            if (a[i - 1] >= a[i])
            {
                cout << "Yes" << endl;

                return 0;
            }

        cout << "No" << endl;
    }

    return 0;
}