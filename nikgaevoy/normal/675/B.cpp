#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <random>
#include <cstdint>

#pragma comment(linker,"/STACK:200000000")

using namespace std;

const int inf = int (1e9) + 7;
const double pi = 3.1415926535897932384626433;
const double eps = 1e-9;

const string filename = "breaking-hashing";
const bool interactive = true;

int sign (int n)
{
    return n < 0 ? -1 : n ? 1 : 0;
}

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, a, b, c, d;

    cin >> n >> a >> b >> c >> d;

    vector<int> sums = {a + b, b + d, d + c, a + c};

    sort (sums.begin (), sums.end ());

    int big = sums.back (), small = sums.front ();

    long long ans = small + n - big;

    ans *= n;

    cout << (ans < 0 ? 0 : ans) << endl;

    return 0;
}