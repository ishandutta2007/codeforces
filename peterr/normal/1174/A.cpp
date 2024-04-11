#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int* arr = new int[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + 2 * n);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += arr[i];
    }
    for (int i = n; i < 2 * n; i++)
    {
        sum2 += arr[i];
    }
    if (arr[0] == arr[2 * n - 1])
        cout << -1;
    else
    {
        for (int i = 0; i < 2 * n; i++)
            cout << arr[i] << " ";
    }

    return 0;
}