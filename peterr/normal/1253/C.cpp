#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int candy[MAXN];
long long groups[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> candy[i];
    }
    sort(candy, candy + n);
    long long ans = 0;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        groups[g] += candy[i];
        ans += groups[g];
        g = (g + 1) % m;
        cout << ans << " ";
    }
    return 0;
}