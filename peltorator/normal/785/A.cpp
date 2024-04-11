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
    int sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < 5; j++)
            if (t == s[j])
                sum += a[j];
    }
    cout << sum;
    return 0;
}