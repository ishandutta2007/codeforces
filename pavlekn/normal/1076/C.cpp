#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long

#define double long double

const double eps = 1e-11;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        double D = n * n - 4 * n;
        if (D <= -eps)
        {
            cout << "N" << endl;
            continue;
        }
        double b1 = (-n + sqrt(D)) / -2;
        double b2 = (-n - sqrt(D)) / -2;
        if (b1 >= -eps && (n - b1) >= -eps)
        {
            cout << setprecision(20) << "Y " << b1 << " " << n - b1 << endl;
        }
        else if (b2 >= -eps && (n - b2) >= -eps)
        {
            cout << setprecision(20) << "Y " << b2 << " " << n - b2 << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}