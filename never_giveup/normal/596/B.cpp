#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long now = 0, ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] - now), now = a[i];
    cout << ans;
}