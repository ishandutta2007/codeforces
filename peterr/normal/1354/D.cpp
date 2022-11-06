#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
const int LOGN = 19;
int bit[MAXN + 1];

void inc(int pos, int amt)
{
    while (pos <= MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

void query(int pos)
{
    int cur = 0;
    for (int i = LOGN; i >= 0; i--)
    {
        if (cur + (1 << i) <= MAXN && bit[cur + (1 << i)] < pos)
        {
            cur += 1 << i;
            pos -= bit[cur];
        }
    }
    cur++;
    inc(cur, -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        inc(a, 1);
    }
    while (q--)
    {
        int k;
        cin >> k;
        if (k > 0)
        {
            inc(k, 1);
        }
        else
        {
            query(-k);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (bit[i])
        {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}