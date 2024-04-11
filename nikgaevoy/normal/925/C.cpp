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
#include <sstream>
#include <functional>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

int bts (long long n)
{
    int r = -1;

    while (n > 0)
    {
        n >>= 1;
        r++;
    }

    return r;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<long long> arr (n);

    for (auto &it : arr)
        cin >> it;

    sort (arr.begin (), arr.end (), greater<long long> ());
    auto b = arr;

    for (auto &it : b)
        it = bts (it);

    list<long long> ans;

    for (int l = 0, r; l < arr.size (); l = r)
    {
        for (r = l + 1; r < arr.size () && b[r] == b[l]; r++);

        bool good = true;
        int i = l;

        for (auto it = ans.begin (); i < r && it != ans.end (); ++it)
        {
            if (good)
            {
                ans.insert (it, arr[i++]);
                good = false;
            }

            if (*it & (1ll << b[l]))
                good = true;
        }

        if (i < r)
        {
            if (good)
                ans.push_back (arr[i++]);

            if (i < r)
            {
                cout << "No" << endl;

                return;
            }
        }
    }

    assert (ans.size () == arr.size ());

    cout << "Yes" << endl;
    long long x = 0;

    for (auto it : ans)
    {
        x ^= it;
        cout << it << ' ';
    }
    cout << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}