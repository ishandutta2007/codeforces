//#pragma GCC optimize("O3")
//#pragma GCC target("sse4.1")
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = ((int)(n) - 1); i >= 0; --i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

void solve (int n)
{
    int m, s;
    cin >> m >> s;
    --s;

    vii es;
    vvi orient(n), unor(n);

    forn (i, m)
    {
        int t, u, v;
        cin >> t >> u >> v;
        --u, --v;
        if (t == 1)
            orient[u].pb(v);
        else
        {
            unor[u].pb(sz(es));
            unor[v].pb(sz(es));
            es.pb(mp(u, v));
        }
    }

    forn (plan, 2)
    {
        vc used(n);
        string res(sz(es), '?');

        queue<int> q;
        q.push(s);
        used[s] = 1;

        int cnt = 0;
        while (!q.empty())
        {
            int cur = q.front(); q.pop(); cnt++;
            for (int dest : orient[cur]) if (!used[dest])
            {
                q.push(dest);
                used[dest] = 1;
            }
            for (int num : unor[cur])
            {
                int dest = (es[num].fst ^ es[num].snd ^ cur);
                if (used[dest])
                    continue;

                assert(res[num] == '?');
                if (plan == 0)
                    res[num] = (es[num].fst == cur ? '+' : '-');
                else
                    res[num] = (es[num].fst == cur ? '-' : '+');

                if (plan == 0)
                {
                    q.push(dest);
                    used[dest] = 1;
                }
            }
        }

        for (char &ch : res) if (ch == '?')
            ch = '+';

        cout << cnt << endl;
        cout << res << endl;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
        solve(n);
}