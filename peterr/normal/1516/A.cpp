#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ptr1 = 0;
        int ptr2 = n - 1;
        while (k && ptr1 < ptr2)
        {
            while (ptr1 < ptr2 && a[ptr1] == 0)
                ptr1++;
            while (a[ptr1] && k)
            {
                k--;
                a[ptr1]--;
                a[ptr2]++;
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}