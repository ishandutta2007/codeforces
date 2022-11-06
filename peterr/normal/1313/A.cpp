#include <bits/stdc++.h>

using namespace std;

int arr[3];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        swap(arr[0], arr[2]);
        int ans = 0;
        for (int i = 0; i < 3; i++)
        {
            if (arr[i])
            {
                arr[i]--;
                ans++;
            }
        }
        if (arr[0] && arr[1])
        {
            arr[0]--;
            arr[1]--;
            ans++;
        }
        if (arr[0] && arr[2])
        {
            arr[0]--;
            arr[2]--;
            ans++;
        }
        if (arr[1] && arr[2])
        {
            arr[1]--;
            arr[2]--;
            ans++;
        }
        if (arr[0] && arr[1] && arr[2])
        {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}