#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 5E5;
int a[MAXN + 1];
int bitLeft[MAXN + 1];
int bitRight[MAXN + 1];
pair<int, int> el[MAXN + 1];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
}

void mult(int &a, int b)
{
    a = (int) ((long long) a * b % MOD);
}

void inc(int pos, int amt, int bit[MAXN + 1])
{
    while (pos <= MAXN)
    {
        add(bit[pos], amt);
        pos += pos & -pos;
    }
}

int query(int pos, int bit[MAXN + 1])
{
    int ans = 0;
    while (pos)
    {
        add(ans, bit[pos]);
        pos -= pos & -pos;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        el[i] = make_pair(a[i], i);
    }
    sort(el + 1, el + n + 1);
    int ans = 0;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> pr = el[i];
        int ind = pr.second;
        int l = ind;
        int r = n - ind + 1;
        int temp = (int) ((long long) l * r % MOD);
        add(temp, (int) ((long long) query(ind, bitLeft) * r % MOD));
        add(temp, (int) ((long long) (total - query(ind, bitRight) + MOD) * l % MOD));
        mult(temp, pr.first);
        add(ans, temp);
        inc(ind, l, bitLeft);
        inc(ind, r, bitRight);
        add(total, r);
    }
    cout << ans << "\n";
    return 0;
}