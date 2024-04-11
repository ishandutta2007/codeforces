#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
int b[MAXN];
pair<int, int> diff[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        diff[i] = {a[i] - b[i], i};
    }
    sort(diff, diff + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = a[diff[n - 1 - i].second];
        int y = b[diff[n - 1 - i].second];
        ans += (long long) x * i;
        ans += (long long) y * (n - i - 1);
    }
    cout << ans;

    return 0;
}