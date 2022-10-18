#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 300001;

vector<int> q;

int a[] = { 1, 1, 1, 2, 9 };

int main()
{
   //freopen("in.txt", "r", stdin);
 //   cout.precision(100);
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 2; i <= k; i++)
    {
        ll t = 1;
        for (int j = n - i + 1; j <= n; j++)
            t *= j;
        for (int j = 1; j <= i; j++)
            t /= j;
        t *= a[i];
        ans += t;
    }
    cout << ans + 1;
    return 0;
}