#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int c[MAXN];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c, c + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (long long) x * c[i];
        x = max(1, x - 1);
    }
    cout << ans << endl;
    return 0;
}