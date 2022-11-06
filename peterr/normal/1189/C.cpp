#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXLEVEL = 17;
int arr[MAXN];
int segSum[2 * (1 << MAXLEVEL)];
int candies[2 * (1 << MAXLEVEL)];

void build(int i)
{
    if (i >= MAXN)
    {
        segSum[i] = arr[i - MAXN];
        candies[i] = 0;
    }
    else
    {
        build(i * 2);
        build(i * 2 + 1);
        segSum[i] = (segSum[i * 2] + segSum[i * 2 + 1]);
        candies[i] = candies[i * 2] + candies[i * 2 + 1];
        if (segSum[i * 2] + segSum[i * 2 + 1] >= 10)
            candies[i]++;
    }
}

int query(int L, int R)
{
    L += MAXN;
    R += MAXN;
    int ans = 0;
    while (L <= R)
    {
        if (L % 2 == 1)
            ans += segSum[L++];
        if (R % 2 == 0)
            ans += segSum[R--];
        L /= 2;
        R /= 2;
    }
    return ans;
}

int solve(int L, int R)
{
    if (L == R)
        return 0;
    int ans = 0;
    int mid = (L + R) / 2;
    ans += solve(L, mid);
    ans += solve(mid + 1, R);
    int sum1 = query(L, mid);
    int sum2 = query(mid + 1, R);
    if (sum1 + sum2 >= 10)
        ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        cout << query(L, R) / 10 << endl;
    }

    return 0;
}