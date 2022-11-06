#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool diverse = false;
    for (int i = 1; i < n; i++)
    {
        if ((arr[0] + arr[i]) % 2 == 1)
            diverse = true;
    }
    if (diverse)
    {
        sort(arr, arr + n);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}