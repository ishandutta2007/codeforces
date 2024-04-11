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

const double pi = 3.14159265358979323846;
const int inf = int (1e9) + 7;

int main ()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    long long n;
    int k;

    cin >> n >> k;

    long long i;

    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            k--;

        if (k == 0)
        {
            cout << i << endl;

            return 0;
        }
    }

    for (i = n / i; i > 0; i--)
    {
        if (n % i == 0)
            k--;

        if (k == 0)
        {
            cout << n / i << endl;

            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}