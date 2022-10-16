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

    int l = inf, r = 0;

    for (int i = 0; i < n; i++)
    {
        int t;

        cin >> t;

        l = min (l, t);
        r = max (r, t);
    }

    cout << (l + r) / 2 << endl;

    return 0;
}