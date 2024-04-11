#include <bits/stdc++.h>

const int N = 2e5 + 50;
typedef long long ll;

int n, q, a[N];

struct tag_t
{
    int l, r, len, lenl, lenr;
    ll ans;
    tag_t() : l(0), r(0), len(0), lenl(0), lenr(0), ans(0ll) {}
} t[N << 2];

tag_t operator+(const tag_t &l, const tag_t &r)
{
    tag_t res;
    res.ans = l.ans + r.ans;
    res.l = l.l, res.r = r.r;
    res.lenl = l.lenl, res.lenr = r.lenr;
    res.len = l.len + r.len;
    if (l.r <= r.l)
    {
        res.ans += 1ll * l.lenr * r.lenl;
        if (l.lenl == l.len) res.lenl = l.lenl + r.lenl;
        if (r.lenr == r.len) res.lenr = r.lenr + l.lenr;
    }
    return res;
}

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

void maintain(int o, int v) 
{
    t[o].l = t[o].r = v;
    t[o].lenl = t[o].lenr = t[o].ans = t[o].len = 1;
}

void push_up(int o)
{
    t[o] = t[lc(o)] + t[rc(o)];
}

void build(int o, int l, int r) 
{
    if (l == r) 
    {
        maintain(o, a[l]);
    }
    else 
    {
        const int mid = l + r >> 1;
        build(lc(o), l, mid);
        build(rc(o), mid + 1, r);
        push_up(o);
    }
}

void modify(int o, int l, int r, int p, int v)
{
    if (l == r) maintain(o, v);
    else
    {
        const int mid = l + r >> 1;
        if (p <= mid) modify(lc(o), l, mid, p, v);
        else modify(rc(o), mid + 1, r, p, v);
        push_up(o);
    }
}

tag_t query(int o, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) return t[o];
    const int mid = l + r >> 1;
    if (qr <= mid) return query(lc(o), l, mid, ql, qr);
    if (ql > mid) return query(rc(o), mid + 1, r, ql, qr);
    return query(lc(o), l, mid, ql, qr) + query(rc(o), mid + 1, r, ql, qr);
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) 
    {
        std::cin >> a[i];
    }
    build(1, 1, n);
    while (q--)
    {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 1)
        {
            modify(1, 1, n, l, r);
        }
        else
        {
            std::cout << query(1, 1, n, l, r).ans << '\n';
        }
    }
    return 0;
}