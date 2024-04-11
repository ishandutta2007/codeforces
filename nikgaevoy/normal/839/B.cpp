#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <complex>

#include <cassert>

using namespace std;

const int inf = (int)1e9 + 7;
const double pi = 3.14159265358979323846;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, k;

    cin >> n >> k;

    int fours = n, pairs = 2 * n;

    vector<int> arr (k);

    for (auto &it : arr)
        cin >> it;

    for (int i = 0; fours && i < arr.size (); i++)
    {
        int d = min (fours, (arr[i] + 1) / 4);

        fours -= d;
        arr[i] -= min (d * 4, arr[i]);
    }

    for (int i = 0; pairs && i < arr.size (); i++)
    {
        int d = min (pairs, arr[i] / 2);

        pairs -= d;
        arr[i] -= 2 * d;
    }

    if (*max_element (arr.begin (), arr.end ()) > 2)
    {
        cout << "NO" << endl;

        return 0;
    }

    int ones = count (arr.begin (), arr.end (), 1),
        twos = count (arr.begin (), arr.end (), 2);

    int d = min ({ones, twos, fours});

    ones -= d;
    twos -= d;
    fours -= d;

    if (fours == 0)
        cout << (ones + twos <= pairs ? "YES" : "NO") << endl;
    else if (twos == 0)
        cout << (ones <= 2 * fours + pairs ? "YES" : "NO") << endl;
    else
    {
        ones = twos / 3;
        twos -= ones;
        ones <<= 1;

        d = min ({ones, twos, fours});

        ones -= d;
        twos -= d;
        fours -= d;

        cout << (twos <= fours + pairs ? "YES" : "NO") << endl;
    }

    return 0;
}