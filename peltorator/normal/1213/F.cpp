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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<bool> vb;

vector<int> f(vector<int> a)
{
    int n = sz(a);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[a[i]] = i;
    return b;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int k;
    cin >> k;
    vector<int> p(n), q(n);
    for (int &i : p)
        cin >> i, i--;
    for (int &i : q)
        cin >> i, i--;
    p = f(p);
    q = f(q);
    vector<int> qq(n);
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++)
    {
        qq[i] = p[q[i]];
        int l = min(p[i], q[i]);
        int r = max(p[i], q[i]);
        v.push_back({l, -1});
        v.push_back({r, 1});
    }
    sort(v.begin(), v.end());
    int beg = v[0].first;
    int bal = 0;
    vector<int> eq(n, 0);
    for (auto it : v)
    {
        int pos = it.first;
        int t = it.second;
        bal -= t;
        if (bal == 0)
        {
            for (int i = beg + 1; i <= pos; i++)
                eq[i] = 1;
        }
        else if (t == -1 && bal == 1)
        {
            beg = pos;
        }
    }
    int x = 0;
    for (int i : eq)
        if (!i)
            x++;
    if (x < k)
    {
        cout << "NO" << endl;
        return 1;
    }
    string s = "";
    int cur = -1;
    for (int i = 0; i < n; i++)
    {
        if (!eq[i])
            cur = min(cur + 1, k - 1);
        s.push_back('a' + cur);
    }
    vector<int> revp = f(p);
    string t = "";
    for (int i = 0; i < n; i++)
        t.push_back('a');
    for (int i = 0; i < n; i++)
        t[revp[i]] = s[i];
    cout << "YES\n" << t << endl;
    return 1;
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