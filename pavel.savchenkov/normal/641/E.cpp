#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

struct fenw
{
    vi ans;
    int n;

    fenw ()
    {
        n = 0;
    }

    fenw (int n_) : n(n_ + 1)
    {
        ans.resize(n);
    }

    void add (int pos, int what)
    {
        for (int i = pos; i < n; i += i & (-i))
            ans[i] += what;
    }

    int pref (int pos)
    {
        int res = 0;
        for (int i = pos; i > 0; i -= i & (-i))
            res += ans[i];
        return res;
    }
};

void solve (int n)
{
    map<int, vector<pair<int, int>>> ops;
    vvi q(n);

    for (int i = 0; i < n; i++)
    {
        int a, t, x;
        cin >> a >> t >> x;
        q[i] = {a, t, x};
        ops[x].pb(mp(t, a));
    }

    for (auto &t : ops)
        sort(ALL(t.second));

    map<int, fenw> res;
    for (const auto &t : ops)
        res[t.first] = fenw(sz(t.second));

    for (int i = 0; i < n; i++)
    {
        int a = q[i][0], t = q[i][1], x = q[i][2];
        const auto &where = ops[x];
        int pos = lower_bound(ALL(where), mp(t, a)) - where.begin();

        if (a != 3)
            res[x].add(pos + 1, (a == 1 ? +1 : -1));
        else
            cout << res[x].pref(pos + 1) << '\n';
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
        solve(n);
}