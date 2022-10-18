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
    int n;
    cin >> n;
    int maxl = -1e9, minr = 1e9;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        maxl = max(maxl, l);
        minr = min(minr, r);
    }
    cin >> n;
    int maxl1 = -1e9, minr1 = 1e9;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        maxl1 = max(maxl1, l);
        minr1 = min(minr1, r);
    }
    cout << max(max(maxl1 - minr, maxl - minr1), 0);
    return 0;
}