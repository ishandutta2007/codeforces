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

    int A = 0, n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int a;

        cin >> a;

        A += a;

        int d = min (8, A);
        k -= d;
        A -= d;

        if (k <= 0)
        {
            cout << i + 1 << endl;

            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}