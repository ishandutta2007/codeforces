#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;

long long sumTwoPowers(int start, int end)
{
    long long sum = 0;
    for (int i = start; i <= end; i += 2)
    {
        sum = (sum + ((long long) 1 << i));
    }
    return sum;
}

long long seriesSum(long long s, long long e)
{
    if (s == e)
        return s;
    if (s > e)
        return 0;

    long long res = 0;
    if (e % 2 == 0)
        res = ((e / 2 % MOD) * ((e + 1) % MOD)) % MOD;
    else
        res = ((e % MOD) * (((e + 1) / 2) % MOD)) % MOD;
    if (s % 2 == 0)
        res = (res - ((s / 2 % MOD) * ((s - 1) % MOD)) % MOD + MOD) % MOD;
    else
        res = (res - ((s % MOD) * (((s - 1) / 2) % MOD)) % MOD + MOD) % MOD;
    return res;
    // return ((e % MOD * ((e + 1) % MOD)) % MOD - (s % MOD * ((s - 1) % MOD)) % MOD + MOD) % MOD / 2;
}

int main()
{
    long long l, r;
    cin >> l >> r;
    int lk = 0, rk = 0;
    while (((long long) 1 << (lk+1) <= l))
        lk++;
    while (((long long) 1 << (rk+1) <= r))
        rk++;
    long long firstStart, secStart, firstEnd, secEnd;
    if (lk % 2 == 0)
    {
        secStart = sumTwoPowers(1, lk - 1) + 1;
        firstStart = sumTwoPowers(0, lk - 2) + 1 + (l - ((long long) 1 << lk));
    }
    else
    {
        firstStart = sumTwoPowers(0, lk - 1) + 1;
        secStart = sumTwoPowers(1, lk - 2) + 1 + (l - ((long long) 1 << lk));
    }
    if (rk % 2 == 0)
    {
        secEnd = sumTwoPowers(1, rk - 1);
        firstEnd = sumTwoPowers(0, rk - 2) + 1 + (r - ((long long) 1 << rk));
    }
    else
    {
        firstEnd = sumTwoPowers(0, rk - 1);
        secEnd = sumTwoPowers(1, rk - 2) + 1 + (r - ((long long) 1 << rk));
    }

    long long ans = 0;
    if (lk != rk || rk % 2 == 0)
    {
        ans = (ans + seriesSum(2 * firstStart - 1, 2 * firstEnd - 1)) % MOD;
        ans = (ans - 2 * seriesSum(firstStart, firstEnd - 1) % MOD + MOD) % MOD;
    }
        //ans = (ans + (seriesSum(2 * firstStart - 1, 2 * firstEnd - 1) - (2 * seriesSum(firstStart, firstEnd - 1)) % MOD + MOD) % MOD) % MOD;
    if (lk != rk || rk % 2 == 1)
        ans = (ans + 2 * seriesSum(secStart, secEnd) % MOD) % MOD;

    cout << ans;

    return 0;
}