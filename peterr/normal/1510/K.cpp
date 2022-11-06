#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int a[2 * MAXN];
int b[2 * MAXN];

void op1(int arr[2 * MAXN], int n)
{
    for (int i = 0; i < 2 * n; i += 2)
    {
        swap(arr[i] , arr[i + 1]);
    }
}

void op2(int arr[2 * MAXN], int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(arr[i], arr[n + i]);
    }
}

bool check(int arr[2 * MAXN], int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        if (arr[i] != i + 1)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    int ans = -1;
    for (int i = 0; i < 10000; i++)
    {
        if (check(a, n) || check(b, n))
        {
            ans = i;
            goto exit;
        }
        if (i & 1)
        {
            op1(a, n);
            op2(b, n);
        }
        else
        {
            op2(a, n);
            op1(b, n);
        }
    }
    exit:
    cout << ans << "\n";
    return 0;
}