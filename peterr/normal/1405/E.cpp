#include <bits/stdc++.h>

using namespace std;

const int INF = 1E8;
const int MAXN = 1 << 19;
pair<int, int> seg[2 * MAXN];
int lz[2 * MAXN];
int a[MAXN];
tuple<int, int, int> queries[MAXN];
int ans[MAXN];
int bit[MAXN];

int queryBit(int pos)
{
    int ans = 0;
    while (pos)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

void incBit(int pos, int amt)
{
    while (pos < MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

void buildTree(int ind = 1)
{
    if (ind >= MAXN)
    {
        seg[ind] = make_pair((a[ind - MAXN] <= ind - MAXN + 1 ? ind - MAXN + 1 - a[ind - MAXN] : INF), -(ind - MAXN));
    }
    else
    {
        buildTree(ind * 2);
        buildTree(ind * 2 + 1);
        seg[ind] = min(seg[ind * 2], seg[ind * 2 + 1]);
    }
}

void prop(int ind)
{
    seg[ind].first += lz[ind];
    if (ind < MAXN)
    {
        lz[ind * 2] += lz[ind];
        lz[ind * 2 + 1] += lz[ind];
    }
    lz[ind] = 0;
}

pair<int, int> query(int l, int r, int ind = 1, int lb = 0, int ub = MAXN - 1)
{
    prop(ind);
    if (ub < l || lb > r)
        return make_pair(INF, 1);
    if (lb >= l && ub <= r)
        return seg[ind];
    int mid = (ub + lb) / 2;
    return min(query(l, r, ind * 2, lb, mid), query(l, r, ind * 2 + 1, mid + 1, ub));
}

void upd(int l, int r, int amt, int ind = 1, int lb = 0, int ub = MAXN - 1)
{
    prop(ind);
    if (ub < l || lb > r)
        return;
    if (lb >= l && ub <= r)
        lz[ind] += amt;
    else
    {
        int mid = (lb + ub) / 2;
        upd(l, r, amt, ind * 2, lb, mid);
        upd(l, r, amt, ind * 2 + 1, mid + 1, ub);
        prop(ind * 2);
        prop(ind * 2 + 1);
        seg[ind] = min(seg[ind * 2], seg[ind * 2 + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < MAXN; i++)
    {
        seg[i + MAXN] = make_pair(INF, -i);
    }
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i < MAXN; i++)
    {
        a[i] = MAXN + 1;
    }
    buildTree();
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        queries[i] = make_tuple(x, y, i);
    }
    sort(queries, queries + q);
    reverse(queries, queries + q);
    int p = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (1)
        {
            pair<int, int> pr = query(i, n - 1);
            //cout << "iter " << i << " " << pr.first << " " << pr.second << endl;
            if (pr.first != 0)
                break;
            int ind = -pr.second;
            incBit(ind + 1, 1);
            upd(ind, n - 1, -1);
            upd(ind, ind, MAXN);
        }
        while (p < q && get<0>(queries[p]) == i)
        {
            ans[get<2>(queries[p])] = queryBit(n - get<1>(queries[p]));
            p++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}