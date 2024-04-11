#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[3 * (int) 1e5];
long long suf[3 * (int) 1e5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    suf[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        suf[i] = suf[i+1] + arr[i];
    }
    sort(suf + 1, suf + n);
    long long sol = suf[0];
    for (int i = 1; i < k; i++)
    {
        sol += suf[n - i];
    }

    cout << sol;

    return 0;
}