#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MAXK = 1E9;
int arr[MAXN];

bool check(long long med, int n, long long k)
{
    for (int i = n / 2; i < n; i++)
    {
        k -= max((long long) 0, med - arr[i]);
    }
    return k >= 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long ans = arr[n / 2];
    for (int jump = MAXK / 2; jump > 0; jump /= 2)
    {
        while (check(ans + jump, n, k))
            ans += (long long) jump;
    }
    cout << ans << endl;
    return 0;
}