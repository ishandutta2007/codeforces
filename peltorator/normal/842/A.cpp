#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef double ld;
 
#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

int main()
{
    //**/freopen("in.txt", "r", stdin);
    fastRead;
    ll l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (int i = x; i <= y; i++)
        if (i * k >= l && i * k <= r)
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}