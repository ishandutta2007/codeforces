#include <bits/stdc++.h>

using namespace std;

typedef double ld;

vector<ld> x, v;

int main()
{
    cout.precision(100);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    x.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ld l = 0, r = 1e10;
    for (int ui = 0; ui < 100; ui++)
    {
        ld med = (r + l) / (ld)(2);
        ld left = -1e10, right = 1e10;
        for (int i = 0; i < n; i++)
        {
            left = max(left, x[i] - v[i] * med);
            right = min(right, x[i] + v[i] * med);
        }
        if (right > left - 1e-8)
            r = med;
        else
            l = med;
    }
    cout << l;
    return 0;
}