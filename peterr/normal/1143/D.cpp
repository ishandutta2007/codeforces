#include <bits/stdc++.h>

using namespace std;

int startt[2];
int endd[4];

int main()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    startt[0] = a + 1;
    startt[1] = k + 1 - a;
    endd[0] = b + 1;
    endd[1] = k + 1 - b;
    endd[2] = endd[0] + k;
    endd[3] = endd[1] + k;
    long long x = 1e18, y = -1;
    if (a == b)
        x = 1;
    for (int i = 0; i < 2; i++)
    {
        int truEnd = *upper_bound(endd, endd + 4, startt[i]);
        int L = truEnd - startt[i];
        for (int j = 0; j < n + 3; j++)
        {
            x = min(x, (long long) n * k / __gcd(L + (long long) j * k, (long long) n * k));
            y = max(y, (long long) n * k / __gcd(L + (long long) j * k, (long long) n * k));
        }
    }
    cout << x << " " << y;

    return 0;
}