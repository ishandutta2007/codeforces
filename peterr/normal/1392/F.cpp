#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
long long h[MAXN];
long long ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        sum += h[i];
    }
    long long base = sum - (long long) (n - 1) * n / 2;
    long long start = base / n;
    base %= n;
    for (int i = 0; i < n; i++)
    {
        ans[i] = start + i;
        if (base)
        {
            base--;
            ans[i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}