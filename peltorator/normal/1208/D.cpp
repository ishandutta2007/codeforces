#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(239);

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define ob pop_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int T = (1 << 21) + 239;
const ll INF = 3e18 + 239;

ll t[T];
ll psh[T];

void push(int v)
{
    t[2 * v] += psh[v];
    t[2 * v + 1] += psh[v];
    psh[2 * v] += psh[v];
    psh[2 * v + 1] += psh[v];
    psh[v] = 0;
}

void build(int v, int l, int r)
{
    if (l + 1 == r)
    {
        t[v] = (ll)l * (ll)(l + 1) / 2LL;
        psh[v] = 0;
        return;
    }
    int mid = (r + l) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid, r);
    psh[v] = 0;
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

void upd(int v, int l, int r, int ql, int qr, ll val)
{
    if (ql >= r || l >= qr)
        return;
    if (ql <= l && r <= qr)
    {
        t[v] += val;
        psh[v] += val;
        return;
    }
    push(v);
    int mid = (r + l) / 2;
    upd(2 * v, l, mid, ql, qr, val);
    upd(2 * v + 1, mid, r, ql, qr, val);
    t[v] = min(t[2 * v], t[2 * v + 1]);

}

ll find(int v, int l, int r, ll val)
{
    if (l + 1 == r)
        return l;
    push(v);
    int mid = (r + l) / 2;
    if (t[2 * v + 1] <= val)
        return find(2 * v + 1, mid, r, val);
    else
        return find(2 * v, l, mid, val);
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<ll> s(n);
    for (ll &i : s)
        cin >> i;
    build(1, 0, n);
    vector<ll> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int pos = find(1, 0, n, s[i]);
        ans[i] = pos + 1;
        upd(1, 0, n, pos + 1, n, -(pos + 1));
        upd(1, 0, n, pos, pos + 1, INF);
    }
    for (ll i : ans)
        cout << i << ' ';
    cout << "\n";
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}