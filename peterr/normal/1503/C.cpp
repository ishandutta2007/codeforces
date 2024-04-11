#include <bits/stdc++.h>

using namespace std;

const int INF = (int) ((1LL << 31) - 1);
const int MAXN = 1 << 17;
pair<int, int> seg1[2 * MAXN];
pair<int, int> seg2[2 * MAXN];
tuple<int, int, int> a[MAXN];

pair<int, int> query(int l, int r, pair<int, int> seg[2 * MAXN])
{
    l += MAXN;
    r += MAXN;
    pair<int, int> ans = {INF, -1};
    while (l <= r)
    {
        if (l & 1)
            ans = min(ans, seg[l++]);
        if (!(r & 1))
            ans = min(ans, seg[r--]);
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void upd(int pos, int x, pair<int, int> seg[2 * MAXN])
{
    pos += MAXN;
    seg[pos] = {x, pos - MAXN};
    pos >>= 1;
    while (pos)
    {
        seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
        pos >>= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> get<0>(a[i]) >> get<1>(a[i]);
        get<2>(a[i]) = i;
        ans += get<1>(a[i]);
    }
    sort(a, a + n);
    /*
    for (int i = 0; i < n; i++)
    {
        cout << "sorted " << i << " " << get<0>(a[i]) << " " << get<1>(a[i]) << endl;
    }
    */
    upd(n - 1, get<0>(a[n - 1]), seg2);
    for (int i = n - 2; i >= 0; i--)
    {
        int val = INF;
        int j = i;
        for (int jump = n; jump; jump >>= 1)
        {
            while (j + jump < n && get<0>(a[j + jump]) <= get<1>(a[i]) + get<0>(a[i]))
                j += jump;
        }
        if (j > i)
        {
            val = min(val, query(i + 1, j, seg1).first);
        }
        if (j < n - 1)
        {
            pair<int, int> pr = query(j + 1, n - 1, seg2);
            val = min(val, pr.first - get<0>(a[i]) - get<1>(a[i]));
        }
        upd(i, val, seg1);
        upd(i, val + get<0>(a[i]), seg2);
        //cout << i << " " << val << endl;
    }
    ans += query(0, 0, seg1).first;
    /*
    for (int i = 0; i < n; i++)
    {
        if (get<2>(a[i]) == 0)
        {
            ans += query(i, i, seg1).first;
        }
    }
    */
    cout << ans << "\n";
    return 0;
}