#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b)
{
    return a % 10 > b % 10;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), comp);
    for (int i = 0 ; i < n && k > 0; i++)
        if (10 - a[i] % 10 <= k)
        {
            if (a[i] + 10 - a[i] % 10 <= 100)
            {
                k -= 10 - a[i] % 10;
                a[i] += 10 - a[i] % 10;
            }
        }
        else
            k = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] / 10;
    cout << min(ans + k / 10, 10 * n);
}