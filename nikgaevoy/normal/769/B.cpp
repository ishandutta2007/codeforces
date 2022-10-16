#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <complex>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

#pragma comment(linker,"/STACK:200000000")

using namespace std;

const bool interactive = false;
const string filename = "records";
const double pi = 3.14159265358979323846;
const int inf = int (1e9) + 7;
const long long linf = (long long) 1e18 + 9;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<int> arr (n);

    for (int i = 0; i < arr.size (); i++)
        cin >> arr[i];

    int s = 0;

    for (int i = 0; i < arr.size (); i++)
        s += arr[i];

    if (arr[0] == 0 || s < n - 1)
    {
        cout << -1 << endl;

        return 0;
    }

    vector<int> nz, zer;

    nz.reserve (n);
    zer.reserve (n);

    for (int i = 0; i < n; i++)
        (arr[i] == 0 ? zer : nz).push_back (i);

    cout << n - 1 << endl;

    for (int i = 0; i < nz.size (); i++)
    {
        if (i != nz.size () - 1)
        {
            cout << nz[i] + 1 << ' ' << nz[i + 1] + 1 << endl;
            arr[nz[i]]--;
        }

        while (arr[nz[i]]-- > 0 && zer.size () > 0)
        {
            cout << nz[i] + 1 << ' ' << zer.back () + 1 << endl;
            zer.pop_back ();
        }
    }

    return 0;
}