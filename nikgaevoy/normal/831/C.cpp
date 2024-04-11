#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);

    int n, k;

    cin >> n >> k;

    vector<int> a (n), b (k);

    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;

    for (int i = 1; i < a.size (); i++)
        a[i] += a[i - 1];

    unordered_set<int> as (a.begin (), a.end ());

    if (as.size () < b.size ())
    {
        cout << 0 << endl;

        return 0;
    }

    int cnt = 0;

    for (auto it : as)
    {
        bool good = true;

        for (int i = 1; good && i < b.size (); i++)
            good &= as.count (it - b[0] + b[i]);

        cnt += good;
    }

    cout << cnt << endl;

    return 0;
}