#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
const int N = 7e5;
typedef pair <int, int> pii;
typedef pair <pii, int> piii;
typedef long long ll;

ll t_cnt[4 * N], t_sum[4 * N], cnt, sum;
vector <int> x;
int print[N], sz, it, n, w;

int find(int need)
{
    int l = 0, r = sz + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (x[m] <= need) l = m; else r = m;
    }
    return l;
}

void modify(int i, int l, int r, int need, int value)
{
    if (l == r)
    {
        t_cnt[i] += value;
        t_sum[i] = t_cnt[i] * x[l];
        return;
    }
    int m = (l + r) / 2;
    if (need <= m) modify(i * 2, l, m, need, value); else modify(i * 2 + 1, m + 1, r, need, value);
    t_cnt[i] = t_cnt[i * 2] + t_cnt[i * 2 + 1];
    t_sum[i] = t_sum[i * 2] + t_sum[i * 2 + 1];
}

void find_in_tree(int i, int l, int r, int ost)
{
    if (l == r)
    {
        cnt += t_cnt[i];
        sum += t_sum[i];
        it = l;
        return;
    }
    int m = (l + r) / 2;
    if (t_cnt[i * 2] >= ost) find_in_tree(i * 2, l, m, ost); else
    {
        cnt += t_cnt[i * 2];
        sum += t_sum[i * 2];
        find_in_tree(i * 2 + 1, m + 1, r, ost - t_cnt[i * 2]);
    }
}

int main()
{
    scanf("%d %d", &n, &w);
    vector <piii> a(n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].first.second, &a[i].first.first), a[i].second = i;
    sort(a.begin(), a.end());
    x.push_back(0);
    for (int i = 0; i < n; i++)
    {
        x.push_back(a[i].first.second);
        x.push_back(a[i].first.first - a[i].first.second);
    }
    sort(x.begin(), x.end());
    x.resize(distance(x.begin(), unique(x.begin(), x.end())));
    sz = x.size() - 1;
    memset(t_cnt, 0, sizeof(t_cnt));
    memset(t_sum, 0, sizeof(t_sum));
    for (int i = 0; i < n; i++) modify(1, 1, sz, find(a[i].first.second), +1);
    ll ans = 1e18;
    if (w <= n)
    {
        cnt = sum = 0;
        find_in_tree(1, 1, sz, w);
        sum -= (cnt - w) * x[it];
        ans = min(ans, sum);
    }
    ll already = 0;
    for (int i = 0; i < n; i++)
    {
        modify(1, 1, sz, find(a[i].first.second), -1);
        modify(1, 1, sz, find(a[i].first.first - a[i].first.second), +1);
        already += a[i].first.second;
        int ost = w - i - 1;
        if (ost < 0 || ost > n) continue;
        cnt = sum = 0;
        find_in_tree(1, 1, sz, ost);
        sum -= (cnt - ost) * x[it] - already;
        ans = min(ans, sum);
    }
    memset(t_cnt, 0, sizeof(t_cnt));
    memset(t_sum, 0, sizeof(t_sum));
    for (int i = 0; i < n; i++) modify(1, 1, sz, find(a[i].first.second), +1);
    vector <pii> res;
    if (w <= n)
    {
        cnt = sum = 0;
        find_in_tree(1, 1, sz, w);
        sum -= (cnt - w) * x[it];
        if (sum == ans)
        {
            for (int i = 0; i < n; i++) res.push_back(make_pair(a[i].first.second, a[i].second));
            sort(res.begin(), res.end());
            for (int i = 0; i < w; i++) print[res[i].second]++;
            printf("%I64d\n", ans);
            for (int i = 0; i < n; i++) printf("%d", print[i]);
            return 0;
        }
    }
    already = 0;
    for (int i = 0; i < n; i++)
    {
        modify(1, 1, sz, find(a[i].first.second), -1);
        modify(1, 1, sz, find(a[i].first.first - a[i].first.second), +1);
        already += a[i].first.second;
        int ost = w - i - 1;
        if (ost < 0 || ost > n) continue;
        cnt = sum = 0;
        find_in_tree(1, 1, sz, ost);
        sum -= (cnt - ost) * x[it] - already;
        if (sum == ans)
        {
            for (int j = 0; j <= i; j++) print[a[j].second]++;
            for (int j = 0; j <= i; j++) res.push_back(make_pair(a[j].first.first - a[j].first.second, a[j].second));
            for (int j = i + 1; j < n; j++) res.push_back(make_pair(a[j].first.second, a[j].second));
            sort(res.begin(), res.end());
            for (int j = 0; j < ost; j++) print[res[j].second]++;
            printf("%I64d\n", ans);
            for (int j = 0; j < n; j++) printf("%d", print[j]);
            return 0;
        }
    }
    return 0;
}