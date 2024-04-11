#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

string s[5] = { "Tetrahedron", "Cube", "Octahedron", "Dodecahedron", "Icosahedron" };

int a[5] = { 4, 6, 8, 12, 20 };

int main()
{
    fastRead;
    ll n, m;
    cin >> n >> m;
    if (m >= n)
    {
        cout << n;
        return 0;
    }
    ll l = 0, r = 2e9;
    while (r - l > 1)
    {
        ll med = (r + l) / 2;
        if (med * (med + 1) / 2 >= n - m)
            r = med;
        else
            l = med;
    }
    cout << m + r;
    return 0;
}