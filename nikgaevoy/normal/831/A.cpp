#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);

    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    auto pl = max_element (arr.begin (), arr.end ());
    auto pr = max_element (arr.rbegin (), arr.rend ());

    if (!is_sorted (arr.begin (), pl) || unique (arr.begin (), pl) != pl)
    {
        cout << "NO" << endl;

        return 0;
    }

    if (!is_sorted (arr.rbegin (), pr) || unique (arr.rbegin (), pr) != pr)
    {
        cout << "NO" << endl;

        return 0;
    }

    auto r = arr.begin () + (arr.rend () - pr - 1);

    cout << (min_element (pl, r) == pl ? "YES" : "NO") << endl;

    return 0;
}