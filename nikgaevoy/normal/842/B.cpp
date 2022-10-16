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

template<class T>
T sqr (T x)
{
    return x * x;
}

int main ()
{
    int R, d, n;

    cin >> R >> d >> n;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int x, y, r;

        cin >> x >> y >> r;

        if (sqr (R - d + r) <= sqr (x) + sqr (y) && sqr (x) + sqr (y) <= sqr (R - r))
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}