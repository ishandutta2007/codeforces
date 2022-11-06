#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
const int INF = 1E9 + 2 * MAXN;
int a[MAXN + 1];
bool fx[MAXN + 1];
int d[MAXN + 1];

int lis(int l, int r, int lb, int ub)
{
    int len = r - l + 1;
    fill(d, d + len + 1, INF + 1);
    d[0] = lb;
    for (int i = l; i <= r; i++)
    {
        int ind = -1;
        for (int jump = len / 2 + 1; jump; jump >>= 1)
        {
            while (ind + jump <= len && d[ind + jump] <= a[i])
                ind += jump;
        }
        if (ind != -1)
        {
            d[ind + 1] = min(d[ind + 1], a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= len; i++)
    {
        if (d[i] <= ub)
            ans = i;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] -= i;
        //cout << "ind " << i << " " << a[i] << endl;
    }
    for (int i = 0; i < k; i++)
    {
        int b;
        cin >> b;
        fx[b] = true;
    }
    bool poss = true;
    int prev = -n - 1;
    for (int i = 1; i <= n; i++)
    {
        if (!fx[i])
            continue;
        if (a[i] < prev)
        {
            poss = false;
            break;
        }
        prev = a[i];
    }
    if (!poss)
    {
        cout << "-1\n";
        return 0;
    }
    int ptr = 1;
    int ans = n - k;
    while (ptr <= n)
    {
        if (fx[ptr])
            ptr++;
        else
        {
            int l = ptr;
            while (ptr <= n && !fx[ptr])
                ptr++;
            int r = ptr - 1;
            int lb = -INF;
            if (l > 1)
                lb = a[l - 1];
            int ub = INF;
            if (r < n)
                ub = a[r + 1];
            ans -= lis(l, r, lb, ub);
        }
    }
    cout << ans << "\n";
    return 0;
}