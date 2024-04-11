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
const double pi = 3.14159265358979323846;
const int inf = int (1e9) + 7;
const long long linf = (long long) 1e18 + 9;

void import ()
{
    if (!interactive)
    {
        FILE *f = fopen ("input.txt", "r");

        if (f != NULL)
        {
            fclose (f);

            freopen ("input.txt", "r", stdin);
            freopen ("output.txt", "w", stdout);
        }
    }
}

int main ()
{
    import ();

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<bool> was (n);

    int pos = was.size ();

    for (int i = 0; i < n; i++)
    {
        int t;

        cin >> t;

        was[--t] = true;

        while (pos > 0 && was[pos - 1])
            cout << pos-- << ' ';
        cout << endl;
    }

    return 0;
}