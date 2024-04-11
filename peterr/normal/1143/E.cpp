#include <bits/stdc++.h>

using namespace std;

const int INF = 1E7;
const int MAXN = 2E5;
const int LOGN = 32 - __builtin_clz(MAXN);
int p[MAXN];
int a[MAXN];
int nxtPerm[MAXN + 1];
int nxt[MAXN];
int last[MAXN];
int len[MAXN];
int nxtChain[LOGN][MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (i > 0)
        {
            nxtPerm[p[i - 1]] = p[i];
        }
    }
    nxtPerm[p[n - 1]] = p[0];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = m - 1; i >= 0; i--)
    {
        nxt[i] = -1;
        int toIndex = last[nxtPerm[a[i]]];
        if (toIndex != 0)
        {
            nxt[i] = toIndex;
        }
        last[a[i]] = i;
    }
    for (int i = 0; i < m; i++)
    {
        nxtChain[0][i] = nxt[i] == -1 ? m : nxt[i];
    }
    nxtChain[0][m] = m;
    for (int i = 1; i < LOGN; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            nxtChain[i][j] = nxtChain[i - 1][nxtChain[i - 1][j]];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int cur = i;
        int dist = n - 1;
        while (dist > 0)
        {
            cur = nxtChain[__builtin_ctz(dist)][cur];
            dist ^= (-dist & dist);
        }
        if (cur == m)
            len[i] = INF;
        else
            len[i] = cur - i;
    }
    for (int i = m - 2; i >= 0; i--)
    {
        if (len[i + 1] != INF)
        {
            len[i] = min(len[i], len[i + 1] + 1);
        }
    }
    stringstream ss;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int dist = r - l;
        if (dist >= len[l])
            ss << 1;
        else
            ss << 0;
    }
    cout << ss.str();
    return 0;
}