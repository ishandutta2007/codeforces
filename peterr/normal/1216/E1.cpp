#include <bits/stdc++.h>

using namespace std;

int sze[10];
const int MAX = 1E9;

long long sum(int l, int r)
{
    if (l == 0)
        return (long long) r * (r + 1) / 2;
    else
        return (long long) l * (r - l + 1) + sum(0, r - l);
}

int getLenOnce(int x)
{
    int digits = 1;
    int ans = 0;
    while (x > 0)
    {
        ans += x;
        x -= sze[digits++];
    }
    return ans;
}

long long getLen(int x)
{
    int digits = 1;
    int temp = x / 10;
    int ten = 1;
    while (temp)
    {
        digits++;
        temp /= 10;
        ten *= 10;
    }
    int cur = 1;
    int nxt = x - ten + 1;
    long long ans = digits * sum(cur, nxt);
    cur = nxt + 1;
    for (int i = digits - 1; i >= 1; i--)
    {
        nxt = cur + sze[i] - 1;
        ans += i * sum(cur, nxt);
        cur = nxt + 1;
    }
    return ans;
}

int solve(int k)
{
    int x = 0;
    for (int jump = MAX / 2; jump > 0; jump /= 2)
    {
        while (x + jump < MAX && getLenOnce(x + jump) < k)
            x += jump;
    }
    k -= getLenOnce(x);
    x++;
    return to_string(x)[k - 1] - '0';
}

int main()
{
    sze[1] = 9;
    for (int i = 2; i <= 9; i++)
        sze[i] = sze[i - 1] * 10;
    int q;
    cin >> q;
    while (q--)
    {
        long long k;
        cin >> k;
        int complete = 0;
        for (int jump = MAX / 2; jump > 0; jump /= 2)
        {
            while (complete + jump < MAX && getLen(complete + jump) < k)
                complete += jump;
        }
        k -= getLen(complete);
        cout << solve(k) << endl;
    }
    return 0;
}