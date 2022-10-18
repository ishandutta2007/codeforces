#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <memory.h>
#include <map>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define deb(a) cerr << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;

int main()
{
 //   freopen("in.txt", "r", stdin);
    int x, y;
    cin >> x >> y;
    if (x < y-1)
    cout << "No";
    else if (y== 0)
        cout << "No";
    else if (y == 1 && x != 0)
        cout << "No";
    else if (y== 2 && x <1)
    cout << "No";
    else
        cout << (x % 2 == y % 2 ? "No" : "Yes");
    return 0;
}