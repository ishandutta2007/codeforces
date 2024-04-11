#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int ptr = n - 1;
        long long sum = 0;
        int cnt = 1;
        while (ptr >= 0)
        {
            if (sum + a[ptr] >= (long long) cnt * x)
            {
                sum += a[ptr];
                cnt++;
                ptr--;
            }
            else
            {
                break;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}