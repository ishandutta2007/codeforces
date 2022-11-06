#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int a[MAXN];
int b[MAXN];

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum += (long long) a[i] * b[i];
    }
    long long ans = sum;
    for (int i = 0; i < n; i++)
    {
        long long temp = sum;
        for (int j = 1; i - j >= 0 && i + j < n; j++)
        {
            temp -= (long long) a[i - j] * b[i - j];
            temp -= (long long) a[i + j] * b[i + j];
            temp += (long long) a[i - j] * b[i + j];
            temp += (long long) a[i + j] * b[i - j];
            ans = max(ans, temp);
        }
    }
    for (int i = 0; i < n; i++)
    {
        long long temp = sum;
        for (int j = 1; i + j < n && i - j + 1 >= 0; j++)
        {
            temp -= (long long) a[i - j + 1] * b[i - j + 1];
            temp -= (long long) a[i + j] * b[i + j];
            temp += (long long) a[i - j + 1] * b[i + j];
            temp += (long long) a[i + j] * b[i - j + 1];
            ans = max(ans, temp);
        }
    }
    cout << ans << "\n";
    return 0;
}