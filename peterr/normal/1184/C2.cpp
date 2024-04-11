#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
const int MAXX = 1 << 23;
int seg[MAXX * 2];
int z[MAXX * 2];
tuple<int, int, int> pts[MAXN];

void prop(int pos)
{
    seg[pos] += z[pos];
    if (pos >= MAXX)
    {
        z[pos] = 0;
    }
    else
    {
        z[pos * 2] += z[pos];
        z[pos * 2 + 1] += z[pos];
        z[pos] = 0;
    }
}

int query(int l, int r, int ind = 1, int lb = 0, int rb = MAXX - 1)
{
    prop(ind);
    int mid = (lb + rb) / 2;
    if (l <= lb && r >= rb)
        return seg[ind];
    if (l > rb || r < lb)
        return 0;
    return max(query(l, r, ind * 2, lb, mid), query(l, r, ind * 2 + 1, mid + 1, rb));
}

void inc(int l, int r, int amt, int ind = 1, int lb = 0, int rb = MAXX - 1)
{
    prop(ind);
    int mid = (lb + rb) / 2;
    if (l <= lb && r >= rb)
        z[ind] += amt;
    else if (l > rb || r < lb)
        return;
    else
    {
        inc(l, r, amt, 2 * ind, lb, mid);
        inc(l, r, amt, 2 * ind + 1, mid + 1, rb);
        seg[ind] = max(seg[2 * ind] + z[2 * ind], seg[2 * ind + 1] + z[2 * ind + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x += 1000000;
        y += 1000000;
        pts[i] = make_tuple(x - y, x, y);
        //cout << "hi " << i << " " << x - y << endl;
    }
    sort(pts, pts + n);
    int ans = 0;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = get<1>(pts[i]) + get<2>(pts[i]);
        inc(sum, sum + 2 * r, 1);
        while (p <= i && get<0>(pts[p]) < get<0>(pts[i]) - 2 * r)
        {
            sum = get<1>(pts[p]) + get<2>(pts[p]);
            inc(sum, sum + 2 * r, -1);
            p++;
        }
        ans = max(ans, query(0, MAXX - 1));
    }
    cout << ans << "\n";
    return 0;
}