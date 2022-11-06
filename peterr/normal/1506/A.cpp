#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        long long x;
        cin >> n >> m >> x;
        x--;
        long long col = x / n;
        long long row = x % n;
        cout << (long long) row * m + col + 1 << "\n";
    }
    return 0;
}