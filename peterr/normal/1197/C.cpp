#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int arr[MAXN];
int gaps[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
            gaps[i] = arr[i] - arr[i - 1];
    }
    sort(gaps + 1, gaps + n);
    /*
    for (int i = 1; i < n ;i++)
        cout << gaps[i] << endl;
    */
    int ans = arr[n - 1] - arr[0];
    for (int i = 1; i <= k - 1; i++)
    {
        ans -= gaps[n - i];
    }
    cout << ans << endl;
    return 0;
}