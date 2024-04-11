#include <bits/stdc++.h>
using namespace std;

int sum[5008][2];

int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        sum[i + 1][0] = sum[i][0] + (a[i] == 'a');
        sum[i + 1][1] = sum[i][1] + (a[i] == 'b');
    }
    int res = 0;
    int n = a.length();
    for (int i = 0; i <= n; i++) for (int j = i; j <= n; j++)
    {
        res = max(res, sum[i][0] + sum[j][1] - sum[i][1] + sum[n][0] - sum[j][0]);
    }
    cout << res;
}