#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif // LOCAL
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb push_back
#define sz(c) ((int)(c).size())

struct ship
{
    int id, pos, atk, fuel, price;

    bool operator < (const ship &o) const
    {
        return atk < o.atk;
    }
};

struct base
{
    int pos, def, gold;

    bool operator < (const base &o) const
    {
        return def < o.def;
    }
};

const ll inf_ll = ll(1e13);

struct edge
{
    int to;
    ll cap;
};

struct flow
{
    int n, s, t;
    vector<vector<int>> g;
    vector<edge> e;

    flow (int n_) : n(n_), s(n_ - 2), t(n_ - 1), g(n), e() {}

    void add_edge (int from, int to, ll cap)
    {
        g[from].pb(sz(e));
        e.pb(edge{to, cap});
        g[to].pb(sz(e));
        e.pb(edge{from, 0LL});
    }

    vector<int> dist, ptr;

    ll add_flow ()
    {
        dist.assign(n, -1);
        ptr.assign(n, 0);

        dist[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            for (int num : g[cur])
            {
                ll cap = e[num].cap;
                int to = e[num].to;
                if (cap > 0 && dist[to] == -1)
                {
                    dist[to] = dist[cur] + 1;
                    q.push(to);
                }
            }
        }

        return dfs(s, inf_ll);
    }

    ll dfs (int v, ll to_push)
    {
        if (v == t || to_push == 0)
            return to_push;

        ll pushed = 0;
        for (int &i = ptr[v]; i < sz(g[v]); i++)
        {
            const int num = g[v][i];
            const int to = e[num].to;
            const ll cap = e[num].cap;

            if (dist[to] == dist[v] + 1)
            {
                ll cur_push = dfs(to, min(to_push, cap));
                e[num].cap -= cur_push;
                e[num ^ 1].cap += cur_push;
                to_push -= cur_push;
                pushed += cur_push;
            }

            if (to_push == 0)
                break;
        }

        return pushed;
    }

    ll max_flow ()
    {
        ll ans = 0;
        while (ll add = add_flow())
            ans += add;
        return ans;
    }
};

ll solve_work_instr (const vector<vector<int>> &req, const vector<int> &reward, const vector<int> &cost)
{
    const int right = sz(reward), left = sz(cost);
    const ll sum_rew = accumulate(reward.begin(), reward.end(), 0LL);

    flow flow (2 + left + right);
    for (int i = 0; i < left; i++)
        flow.add_edge(flow.s, i, cost[i]);
    for (int i = 0; i < right; i++)
        flow.add_edge(left + i, flow.t, reward[i]);
    for (int i = 0; i < right; i++)
    {
        for (int instr : req[i])
            flow.add_edge(instr, left + i, inf_ll);
    }

    return sum_rew - flow.max_flow();
}

void dfs (int x, const vector<vector<int>> &g, vector<char> &used, vector<int> &reach)
{
    reach.pb(x);
    used[x] = 1;
    for (int dest : g[x]) if (!used[dest])
        dfs(dest, g, used, reach);
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, m;
    cin >> n >> m;

    const int inf = int(1e9) + 1;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        dist[u][v] = dist[v][u] = 1;
    }

    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


    int s, b, k;
    cin >> s >> b >> k;

    vector<ship> ship(s);
    vector<base> base(b);
    int cur_id = 0;
    for (auto &x : ship)
    {
        cin >> x.pos >> x.atk >> x.fuel >> x.price;
        --x.pos;
        x.id = cur_id++;
    }
    for (auto &x : base)
    {
        cin >> x.pos >> x.def >> x.gold;
        --x.pos;
    }

    sort(ship.begin(), ship.end());
    sort(base.begin(), base.end());

    vector<int> best_atk(s, -inf);
    vector<int> weak_base(n, -inf);
    int ptr = 0;

    for (auto x : ship)
    {
        while (ptr < sz(base) && base[ptr].def <= x.atk)
        {
            const int where = base[ptr].pos;
            const int gold = base[ptr].gold;
            weak_base[where] = max(weak_base[where], gold);
            ptr++;
        }

        for (int i = 0; i < n; i++)
        if (dist[i][x.pos] <= x.fuel)
            best_atk[x.id] = max(best_atk[x.id], weak_base[i] - x.price);
    }

    vector<vector<int>> g(s), grev(s);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].pb(y);
        grev[y].pb(x);
    }

    vector<int> instr;
    vector<vector<int>> req;
    vector<int> reward, cost;

    ll ans = 0;

    for (int i = 0; i < s; i++)
    {
        if (g[i].empty() && grev[i].empty())
            ans += max(0, best_atk[i]);
        else if (best_atk[i] < 0 && best_atk[i] > -inf)
            instr.pb(i);
    }

    sort(instr.begin(), instr.end());
    for (int i = 0; i < sz(instr); i++)
        cost.pb(-best_atk[instr[i]]);

    vector<char> used(s);

    for (int x : best_atk)
        cerr << x << ' ';
    cerr << endl;

    for (int i = 0; i < s; i++)
    if (!g[i].empty() || !grev[i].empty())
    {
        if (best_atk[i] >= 0)
        {
            vector<int> reach;
            dfs(i, g, used, reach);

            for (int x : reach)
                used[x] = 0;

            bool bad = false;
            for (int x : reach)
            if (best_atk[x] == -inf)
                bad = true;

            if (bad)
                continue;

            req.pb(vector<int>());
            reward.pb(best_atk[i]);

            for (int x : reach)
            if (best_atk[x] < 0)
            {
                int pos = lower_bound(instr.begin(), instr.end(), x) - instr.begin();
                assert(pos < sz(instr) && instr[pos] == x);
                req.back().pb(pos);
            }
        }
    }

    ans += solve_work_instr (req, reward, cost);
    cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}