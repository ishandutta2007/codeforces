#include <bits/stdc++.h>

using namespace std;

const int SQRT = 550;
const int MAXN = 3E5;
int a[MAXN + 1];
int freq[MAXN + 1];
int cnt[MAXN + 1];
tuple<int, int, int> ranges[MAXN];
int ans[MAXN];

int calc(int len, int num)
{
    int other = len - num;
    if (num <= other + 1)
        return 1;
    else
        return 1 + (num - other - 1);
}

void addNum(int x, int &mx)
{
    cnt[freq[x]]--;
    cnt[freq[x] + 1]++;
    freq[x]++;
    mx = max(mx, freq[x]);
}

void remNum(int x, int &mx)
{
    cnt[freq[x]]--;
    cnt[freq[x] - 1]++;
    freq[x]--;
    if (!cnt[mx])
        mx--;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[0]++;
    }
    int l = 1;
    int r = 1;
    int maxCnt = 0;
    addNum(a[1], maxCnt);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y, i};
    }
    sort(ranges, ranges + q, [] (auto x, auto y) {
        return make_tuple(get<0>(x) / SQRT, get<1>(x), get<2>(x)) < make_tuple(get<0>(y) / SQRT, get<1>(y), get<2>(y));
    });
    for (int i = 0; i < q; i++)
    {
        int ll = get<0>(ranges[i]);
        int rr = get<1>(ranges[i]);
        int ind = get<2>(ranges[i]);
        while (r < rr)
        {
            r++;
            addNum(a[r], maxCnt);
        }
        while (r > rr)
        {
            remNum(a[r], maxCnt);
            r--;
        }
        while (l < ll)
        {
            remNum(a[l], maxCnt);
            l++;
        }
        while (l > ll)
        {
            l--;
            addNum(a[l], maxCnt);
        }
        ans[ind] = calc(rr - ll + 1, maxCnt);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}