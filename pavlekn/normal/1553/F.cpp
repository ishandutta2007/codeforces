#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;

int t[MAXN];
int t2[MAXN];

void upd(int pos)
{
    for (int i = pos + 1; i < MAXN; i += i & -i)
    {
        t[i]++;
    }
}

int cnt[1007];

void upd2(int pos)
{
    if (pos < 1000)
    {
        cnt[pos] = true;
        return;
    }
    for (int i = pos + 1; i < MAXN; i += i & -i)
    {
        t2[i] += pos;
    }
}


int get(int r)
{
    int ans = 0;
    for (int i = r + 1; i > 0; i -= i & -i)
    {
        ans += t[i];
    }
    return ans;
}

int get2(int r)
{
    int ans = 0;
    for (int i = r + 1; i > 0; i -= i & -i)
    {
        ans += t2[i];
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> ans(n);
    int S = 0;
    upd(a[0]);
    upd2(a[0]);
    S += a[0];
    for (int i = 1; i < n; ++i)
    {
        int add = 0;
        add = S + i * a[i];
        int num = 0;
        for (int k = a[i]; k < MAXN; k += a[i])
        {
            ++num;
            int rr = min(k + a[i] - 1, MAXN - 2);
            add -= num * (get(rr) - get(k - 1)) * a[i];
        }
        for (int j = 0; j < 1000; ++j)
        {
            if (cnt[j])
            {
                add -= j * (a[i] / j);
            }
        }
        for (int j = 1; j <= 300; ++j)
        {
            if (a[i] / j < 1000)
            {
                break;
            }
            add -= (get2(a[i] / j) - get2(a[i] / (j + 1))) * j;
        }
        ans[i] = ans[i - 1] + add;
        upd(a[i]);
        upd2(a[i]);
        S += a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}