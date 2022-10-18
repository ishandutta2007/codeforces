#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
typedef long long ll;
typedef double ld;

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        ll ans = n * (n + 1) / 2;
        ll x = 1;
        while (2LL * x <= n)
            x *= 2LL;
        x *= 2LL;
        x--;
        x *= 2;
        ans -= x;
        cout << ans << " ";
    }
    return 0;
}