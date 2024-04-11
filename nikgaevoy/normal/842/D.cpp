#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <complex>
#include <functional>
#include <bitset>
#include <map>
#include <random>
#include <memory>

#include <cassert>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int mex (const vector<int> &arr, int x)
{
    int pos = 1 << 30, ans = 0;

    while (pos)
    {
        if (lower_bound (arr.begin (), arr.end (), (ans ^ x & ~(2 * pos - 1)) + pos + (x & pos)) -
            lower_bound (arr.begin (), arr.end (), (ans ^ x & ~(2 * pos - 1)) + (x & pos)) >= pos)
            ans += pos;

        pos >>= 1;
    }

    return ans;
}

int main ()
{
    int n, m;

    cin >> n >> m;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    sort (arr.begin (), arr.end ());
    arr.resize (unique (arr.begin (), arr.end ()) - arr.begin ());
    arr.shrink_to_fit ();

    int x = 0;

    for (int i = 0; i < m; i++)
    {
        int tmp;

        cin >> tmp;

        x ^= tmp;

        cout << mex (arr, x) << endl;
    }

    return 0;
}