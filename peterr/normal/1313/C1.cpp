#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3;
int a[MAXN];
int arr[MAXN];
int best[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int pivot = 0; pivot < n; pivot++)
    {
        long long sum = a[pivot];
        int temp = a[pivot];
        arr[pivot] = a[pivot];
        for (int i = pivot - 1; i >= 0; i--)
        {
            temp = min(temp, a[i]);
            sum += temp;
            arr[i] = temp;
        }
        temp = a[pivot];
        for (int i = pivot + 1; i < n; i++)
        {
            temp = min(temp, a[i]);
            sum += temp;
            arr[i] = temp;
        }
        if (sum > ans)
        {
            ans = sum;
            for (int i = 0; i < n; i++)
                best[i] = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << best[i];
    }
    cout << endl;
    return 0;
}