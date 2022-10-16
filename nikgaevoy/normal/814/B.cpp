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

    int n;

    cin >> n;

    vector<int> a (n), b (n);

    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;

    vector<int> diff;

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            diff.push_back (i);

    if (diff.size () == 2)
        if (count (a.begin (), a.end (), b[diff[0]]) == 0 &&
            count (a.begin (), a.end (), a[diff[0]]) == 2)
            a[diff[0]] = b[diff[0]];
        else
            a[diff[1]] = b[diff[1]];
    else if (diff.size () == 1)
    {
        for (int i = 1; i <= n; i++)
            if (count (a.begin (), a.end (), i) == 0)
            {
                a[diff[0]] = i;

                break;
            }
    }
    else
    {
        int zer = -1, two = -1;

        for (int i = 1; i <= n; i++)
        {
            int t = (int)count (a.begin (), a.end (), i);

            if (t == 0)
                zer = i;
            else if (t == 2)
                two = i;
        }

        if (zer != -1)
            a[find (a.begin (), a.end (), two) - a.begin ()] = zer;
        else
            swap (a[0], a[1]);
    }

    for (auto i : a)
        cout << i << ' ';
    cout << endl;

    return 0;
}