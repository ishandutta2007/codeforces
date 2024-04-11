#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pl
{
    ll psum, sum, M;
    pl() : pl(0, 0, 0) {}
    pl(ll a, ll b, ll c) : psum(a), sum(b), M(c) {}
};

ll a[100002], b[100002], c[100002];

pl tree[400002];

pl add(pl x, pl y)
{
    pl ret;
    ret.psum = min(x.psum, x.sum + y.psum);
    ret.sum = x.sum + y.sum;
    ret.M = max(x.sum + y.M, x.M);
    return ret;
}
pl init(int i, int l, int r)
{
    if(l == r) return tree[i] = pl(c[l], c[l], c[l]);
    int m = (l + r)/2;
    return tree[i] = add(init(i*2, l, m), init(i*2+1, m+1, r));
}

pl query(int i, int l, int r, int s, int e)
{
    if(e < l || r < s) return pl(0, 0, 0);
    if(s <= l && r <= e) return tree[i];
    int m = (l + r)/2;
    return add(query(i*2, l, m, s, e), query(i*2+1, m+1, r, s, e));
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) c[i] = b[i] - a[i];

    init(1, 1, n);

    for(int i=1;i<=q;i++)
    {
        int l, r; cin >> l >> r;
        pl ret = query(1, 1, n, l, r);
        if(ret.psum < 0 || ret.sum != 0)
        {
            cout << "-1\n";
            continue;
        }
        cout << ret.M << "\n";
    }
}