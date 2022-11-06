#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 18;
int oneSeg[2 * MAXN];
int zeroSeg[2 * MAXN];
int oneLz[2 * MAXN];
int zeroLz[2 * MAXN];

void prop(int ind, int lz[2 * MAXN], int seg[2 * MAXN], int len)
{
    if (!lz[ind])
        return;
    if (ind >= MAXN)
    {
        seg[ind] = lz[ind] == 1 ? 1 : 0;
        lz[ind] = 0;
    }
    else
    {
        seg[ind] = lz[ind] == 1 ? len : 0;
        lz[ind * 2] = lz[ind];
        lz[ind * 2 + 1] = lz[ind];
        lz[ind] = 0;
    }
}

int query(int l, int r, int seg[2 * MAXN], int lz[2 * MAXN], int ind=1, int lb=0, int ub=MAXN-1)
{
    int len = ub - lb + 1;
    prop(ind, lz, seg, len);
    if (lb >= l && ub <= r)
        return seg[ind];
    if (lb > r || ub < l)
        return 0;
    int mid = (ub + lb) / 2;
    return query(l, r, seg, lz, ind * 2, lb, mid) + query(l, r, seg, lz, ind * 2 + 1, mid + 1, ub);
}

void upd(int l, int r, int amt, int seg[2 * MAXN], int lz[2 * MAXN], int ind=1, int lb=0, int ub=MAXN - 1)
{
    if (!amt)
        amt = -1;
    int len = ub - lb + 1;
    prop(ind, lz, seg, len);
    if (lb >= l && ub <= r)
        lz[ind] = amt;
    else if (lb > r || ub < l)
        return;
    else
    {
        int mid = (lb + ub) / 2;
        upd(l, r, amt, seg, lz, ind * 2, lb, mid);
        upd(l, r, amt, seg, lz, ind * 2 + 1, mid + 1, ub);
        prop(ind * 2, lz, seg, len >> 1);
        prop(ind * 2 + 1, lz, seg, len >> 1);
        seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
    }
}

int main()
{
    /*
    for (int i = 1; i < 8; i++)
    {
        cout << "SEG " << i << " " << oneSeg[i] << endl;
        cout << "LZ " << i << " " << oneLz[i] << endl;
    }
    upd(0, 3, 1, oneSeg, oneLz);
    for (int i = 1; i < 8; i++)
    {
        cout << "SEG " << i << " " << oneSeg[i] << endl;
        cout << "LZ " << i << " " << oneLz[i] << endl;
    }
    cout << "test " << query(0, 3, oneSeg, oneLz) << endl;
    cout << "test " << query(0, 2, oneSeg, oneLz) << endl;
    cout << "test " << query(1, 2, oneSeg, oneLz) << endl;
    */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        int n, q;
        string s, t;
        cin >> n >> q >> s >> t;
        upd(0, n - 1, 0, oneSeg, oneLz);
        upd(0, n - 1, 0, zeroSeg, zeroLz);
        for (int i = 0; i < n; i++)
        {
            if (t[i] == '1')
                upd(i, i, 1, oneSeg, oneLz);
            else
                upd(i, i, 1, zeroSeg, zeroLz);
        }
        vector<pair<int, int>> queries;
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            queries.push_back({l, r});
        }
        bool valid = true;
        while (!queries.empty())
        {
            pair<int, int> pr = queries.back();
            queries.pop_back();
            int l = pr.first - 1;
            int r = pr.second - 1;
            int len = r - l + 1;
            if (query(l, r, oneSeg, oneLz) * 2 > len)
            {
                upd(l, r, 1, oneSeg, oneLz);
                upd(l, r, 0, zeroSeg, zeroLz);
            }
            else if (query(l, r, zeroSeg, zeroLz) * 2 > len)
            {
                upd(l, r, 1, zeroSeg, zeroLz);
                upd(l, r, 0, oneSeg, oneLz);
            }
            else
                valid = false;
        }
        for (int i = 0; i < n; i++)
        {
            //cout << "is zero " << i << " " << query(i, i, zeroSeg, zeroLz) << endl;
            //cout << "is one  " << i << " " << query(i, i, oneSeg, oneLz) << endl;
            if (s[i] == '0' && !query(i, i, zeroSeg, zeroLz))
                valid = false;
            if (s[i] == '1' && !query(i, i, oneSeg, oneLz))
                valid = false;
        }
        if (!valid)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}