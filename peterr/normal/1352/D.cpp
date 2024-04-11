#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int l = 0;
        int r = n - 1;
        int a = 0;
        int b = 0;
        int prev = 0;
        int moves = 0;
        while (l <= r)
        {
            int cur = 0;
            moves++;
            while (l <= r && cur <= prev)
            {
                cur += arr[l];
                a += arr[l];
                l++;
            }
            prev = cur;
            cur = 0;
            if (l <= r)
                moves++;
            while (l <= r && cur <= prev)
            {
                cur += arr[r];
                b += arr[r];
                r--;
            }
            prev = cur;
        }
        cout << moves << " " << a << " " << b << endl;
    }
    return 0;
}