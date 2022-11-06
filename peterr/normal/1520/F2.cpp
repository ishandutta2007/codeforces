#include <bits/stdc++.h>

using namespace std;

const int BLOCK = 16;
const int MAXN = 2E5;
int queries[MAXN];
int len[MAXN];

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int q;
    cin >> q;
    return q;
}

int main()
{
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int m = (n + BLOCK - 1) / BLOCK;
    for (int i = 0; i < m; i++)
    {
        queries[i] = query(1, min(n, (i + 1) * BLOCK));
        if (queries[i] == -1)
            return 0;
        len[i] = min((i + 1) * BLOCK, n);
    }
    while (t--)
    {
        if (k == -1)
            cin >> k;
        int lo = -1;
        int hi = m - 1;
        while (hi > lo)
        {
            int mid = (lo + hi + 1) / 2;
            int zeros = len[mid] - queries[mid];
            if (zeros < k)
                lo = mid;
            else
                hi = mid - 1;
        }
        lo++;
        int l = lo * BLOCK + 1 - 1;
        int r = min(n, l + BLOCK - 1);
        while (r > l)
        {
            int mid = (l + r + 1) / 2;
            int q = query(1, mid);
            if (q == -1)
                return 0;
            int zeros = mid - q;
            if (zeros < k)
                l = mid;
            else
                r = mid - 1;
        }
        cout << "! " << l + 1 << endl;
        for (int i = lo; i < m; i++)
        {
            queries[i]++;
        }
        k = -1;
    }
    return 0;
}