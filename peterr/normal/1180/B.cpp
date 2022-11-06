#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
pair<int, int> arr[MAXN];
int ans[MAXN];

int main()
{
    int n;
    cin >> n;
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
        if (arr[i].first < 0)
            arr[i].first = -arr[i].first - 1;

        ans[i] = arr[i].first;
    }
    sort(arr, arr + n);
    for (int i = 1; i < n; i += 2)
    {
        int j = arr[i].second;
        int k = arr[i-1].second;
        ans[j] = -arr[i].first - 1;
        ans[k] = -arr[i-1].first - 1;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i]<< " ";

    return 0;
}