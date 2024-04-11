#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

int main()
{
    fastRead;
    ll a, b;
    cin >> a >> b;
    int x = 0;
    while (b >= a)
        x++, b *= 2, a *= 3;
    cout << x;
    return 0;
}