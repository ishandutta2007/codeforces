#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2E5;
const int BLOCK = 1900;
const int NUM_BLOCKS = MAXN / BLOCK + 1;
int a[MAXN + 1];
int b[MAXN + 1];
int aLoc[MAXN + 1];
int bLoc[MAXN + 1];
int bit[NUM_BLOCKS][MAXN + 1];

void inc(int bit[MAXN + 1], int pos, int amt)
{
    while (pos <= MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int query(int bit[MAXN + 1], int pos)
{
    int ans = 0;
    while (pos > 0)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

int solve(int rightA, int rightB)
{
    if (rightA == 0 || rightB == 0)
        return 0;
    int ans = 0;
    int block = rightA / BLOCK;
    if (block - 1 >= 0)
    {
        ans += query(bit[block - 1], rightB);
    }
    for (int i = max(1, block * BLOCK); i <= rightA; i++)
    {
        if (bLoc[a[i]] <= rightB)
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        aLoc[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        bLoc[b[i]] = i;
    }
    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        if (i > 0)
        {
            for (int j = 1; j <= MAXN; j++)
            {
                bit[i][j] = bit[i - 1][j];
            }
        }
        for (int j = max(1, i * BLOCK); j < min(n + 1, (i + 1) * BLOCK); j++)
        {
            inc(bit[i], bLoc[a[j]], 1);
        }
    }
    stringstream ss;
    for (int i = 0; i < m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            int t1 = solve(ra, rb);
            int t2 = solve(la - 1, rb);
            int t3 = solve(ra, lb - 1);
            int t4 = solve(la - 1, lb - 1);
            ss << t1 - t2 - t3 + t4 << endl;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            for (int j = aLoc[b[x]] / BLOCK; j < NUM_BLOCKS; j++)
            {
                inc(bit[j], y, 1);
                inc(bit[j], x, -1);
            }
            for (int j = aLoc[b[y]] / BLOCK; j < NUM_BLOCKS; j++)
            {
                inc(bit[j], x, 1);
                inc(bit[j], y, -1);
            }
            swap(b[x], b[y]);
            swap(bLoc[b[x]], bLoc[b[y]]);
        }
    }
    cout << ss.str();

    return 0;
}