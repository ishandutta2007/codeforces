#pragma comment(linker,"/STACK:200000000")

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <random>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

const string filename = "tree40";
bool interactive = true;
const int inf = int (1e9) + 7;

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, q;

    cin >> n >> q;

    vector<int> ser (n);

    while (q-- > 0)
    {
        int t, k, d;

        cin >> t >> k >> d;

        vector<int> mark;

        mark.reserve (k);

        for (int i = 0; i < ser.size () && mark.size () < k; i++)
            if (ser[i] <= t)
                mark.push_back (i);

        if (mark.size () == k)
        {
            int sum = 0;

            for (auto it : mark)
            {
                sum += it + 1;
                ser[it] = t + d;
            }

            cout << sum << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}