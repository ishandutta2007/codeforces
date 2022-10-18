#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;

int aa[] = {0, 4, 7};

vector<int> a;

const int N = 5000001, M = 2000000, INF = 1e9 + 9;

int minn[N], push[N], tree[N], pt[N], num[M], arr[N], n;

void push1(int v)
{
    minn[2 * v] -= push[v];
    minn[2 * v + 1] -= push[v];
    push[2 * v] += push[v];
    push[2 * v + 1] += push[v];
    push[v] = 0;
}

void tu(int v, int l, int r, int ql, int qr, int val)
{
    if (r < l)
        return;
    push1(v);
    if (ql > r || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        minn[v] -= val;
        push[v] += val;
        return;
    }
    int mid = (r + l) / 2;
    tu(2 * v, l, mid, ql, qr, val);
    tu(2 * v + 1, mid + 1, r, ql, qr, val);
    minn[v] = min(minn[2 * v], minn[2 * v + 1]);
}

void pt1(int v, int l, int r)
{
    if (r < l || pt[v] == -1)
        return;
    int mid = (r + l) / 2;
    if (pt[v] == 0)
        tree[2 * v] = tree[2 * v + 1] = pt[2 * v] = pt[2 * v + 1] = 0;
    else
    {
        tree[2 * v] = mid - l + 1;
        tree[2 * v + 1] = r - mid;
        pt[2 * v] = 1;
        pt[2 * v + 1] = 1;
    }
    pt[v] = -1;
}

void upd(int v, int l, int r, int ql, int qr, int val)
{
    pt1(v, l, r);
    if (r < l || ql > r || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        if (val)
            tree[v] = r - l + 1;
        else
            tree[v] = 0;
        pt[v] = val;
        return;
    }
    int mid = (r + l) / 2;
    upd(2 * v, l, mid, ql, qr, val);
    upd(2 * v + 1, mid + 1, r, ql, qr, val);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

void pt2(int v, int l, int r, int mid)
{
    int ll = (v << 1), rr = (ll | 1);
    pt[ll] = pt[rr] = pt[v];
    if (pt[v] == 0)
        tree[ll] = tree[rr] = 0;
    else
    {
        tree[ll] = mid - l + 1;
        tree[rr] = r - mid;
    }
    pt[v] = -1;
}

void upd1(int v, int l, int r, int q)
{
    if (l == r)
    {
        tree[v]++;
        return;
    }
    int mid = ((r + l) >> 1);
    if (pt[v] != -1)
        pt2(v, l, r, mid);
    tree[v]++;
    if (q <= mid)
        upd1(2 * v, l, mid, q);
    else
        upd1(2 * v + 1, mid + 1, r, q);
}

void refr(int v, int l, int r, int ql, int qr)
{
    if (r < l)
        return;
    push1(v);
    if (ql > r || l > qr || minn[v] > 0)
        return;
    if (l == r)
    {
       // cout << l << " " << minn[v] << " " << num[l] 
        while (minn[v] < 0 && num[l] < 29)
        {
            minn[v] += a[num[l] + 1] - a[num[l]];
            num[l]++;
        }
        if (minn[v] < 0)
             minn[v] = INF;
        if (minn[v] == 0)
        {
            upd1(1, 0, n - 1, l);
          //  for (int u = v; u > 0; u >>= 1)
            //    tree[u]++;
            //upd(1, 0, n - 1, l, l, 1);
        }
        return;
    }
    int mid = (r + l) / 2;
    refr(2 * v, l, mid, ql, qr);
    refr(2 * v + 1, mid + 1, r, ql, qr);
    minn[v] = min(minn[2 * v], minn[2 * v + 1]);
}

int find(int v, int l, int r, int ql, int qr)
{
    pt1(v, l, r);
    if (r < l || ql > r || l > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[v];
    int mid = (r + l) / 2;
    return find(2 * v, l, mid, ql, qr) + find(2 * v + 1, mid + 1, r, ql, qr);
}

void buildtree(int v, int l, int r)
{
    if (r < l)
        return;
    if (l == r)
    {
        for (int i = 0; i < a.size(); i++)
            if (a[i] == arr[l])
               tree[v] = 1;
        minn[v] = INF;
        for (int i = 0; i < a.size(); i++)
            if (a[i] >= arr[l])
            {
                num[l] = i;
                minn[v] = a[i] - arr[l];
                break;
            }
        return;
    }
    int mid = (r + l) / 2;
    buildtree(2 * v, l, mid);
    buildtree(2 * v + 1, mid + 1, r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
    minn[v] = min(minn[2 * v], minn[2 * v + 1]);
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    for (int i = 0; i < 3; i++)
        for (int j = min(1, i); j < 3; j++)
            for (int k = min(1, j); k < 3; k++)
                for (int l = 1; l < 3; l++)
                    a.push_back(aa[l] + 10 * aa[k] + 100 * aa[j] + 1000 * aa[i]);
    for (int i = 0; i < N; i++)
        minn[i] = INF, pt[i] = -1;
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    buildtree(1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        string s;
        int l, r;
        cin >> s >> l >> r;
        l--;
        r--;
        if (s == "add")
        {
            int x;
            cin >> x;
            upd(1, 0, n - 1, l, r, 0);
            tu(1, 0, n - 1, l, r, x);
            refr(1, 0, n - 1, l, r);
        }
        else
            cout << find(1, 0, n - 1, l, r) << "\n";
    }
    return 0;
}