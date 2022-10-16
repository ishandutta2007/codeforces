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

int main ()
{
    long long l, r, x, y, k;

    cin >> x >> y >> l >> r >> k;

    y -= y % k;
    x--;
    x -= x % k;
    x += k;

    cout << (y < x || r * k < x || y < l * k ? "NO" : "YES") << endl;

    return 0;
}