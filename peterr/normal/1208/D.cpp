#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2E5;
long long arr[MAXN + 1];
long long sum[MAXN + 1];
long long bit[MAXN + 1];
int ans[MAXN + 1];

long long query(int x)
{
    long long ans = 0;
    while (x > 0)
    {
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

void increment(int x, int amt, int n)
{
    while (x <= n)
    {
        bit[x] += amt;
        x += x & -x;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n; i >= 1; i--)
    {
        int temp = 1;
        for (int jump = n / 2 + 1; jump > 0; jump /= 2)
        {
            while (temp + jump <= n && sum[temp + jump - 1] - query(temp + jump - 1) <= arr[i])
                temp += jump;
        }
        ans[i] = temp;
        increment(temp, temp, n);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}