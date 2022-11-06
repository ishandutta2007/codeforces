#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (arr[n - 1] >= arr[n - 2] + arr[n - 3])
    {
        cout << "NO";
    }
    else
    {
        swap(arr[n-1], arr[n-2]);
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}