#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
long long ones[MAXN + 1];
long long eye[MAXN + 1];
int loc[MAXN + 1];
int p[MAXN + 1];

void inc(int pos, int amt, long long bit[MAXN + 1])
{
    while (pos <= MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

long long query(int pos, long long bit[MAXN + 1])
{
    long long ans = 0;
    while (pos > 0)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

int findPos(int x, long long bit[MAXN + 1])
{
    long long sum = 0;
    int ans = 0;
    for (int e = 20; e >= 0; e--)
    {
        if (ans + (1 << e) <= MAXN && bit[ans + (1 << e)] + sum < x)
        {
            ans += (1 << e);
            sum += bit[ans];
        }
    }
    return ans + 1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        loc[p[i]] = i;
    }
    long long inversions = 0;
    for (int i = 1; i <= n; i++)
    {
        inversions += (i - 1) - query(loc[i], ones);
        inc(loc[i], 1, ones);
        inc(loc[i], loc[i], eye);
        int mid = (i + 1) / 2;
        int med = findPos(mid, ones);
        long long ans = inversions;
        int m = (i - 1) / 2;
        ans += (long long) m * med - query(med - 1, eye) - (long long) m * (m + 1) / 2;
        m = i / 2;
        ans += query(n, eye) - query(med, eye) - (long long) m * med - (long long) m * (m + 1) / 2;
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}