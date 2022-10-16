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

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    if (arr.size () % 7 == 0)
    {
        for (int i = 6; i < arr.size (); i += 7)
            arr[i] = inf;

        cout << (min_element (arr.begin (), arr.end ()) - arr.begin () + 1) << endl;

        return 0;
    }

    int t = (*min_element (arr.begin (), arr.end ()) - 1) / 6;

    for (auto &it : arr)
        it -= 6 * t;

    int cnt = 0, pos = 0;

    while (cnt == 6 || arr[pos] > 1)
    {
        if (cnt++ != 6)
            arr[pos]--;
        else
            cnt = 0;

        pos = (pos + 1) % arr.size ();
    }

    cout << pos + 1 << endl;

    return 0;
}