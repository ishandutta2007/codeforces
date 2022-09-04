#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 100, inf = 1e9 + 100;

int in[maxn], fup[maxn], tnow;

bool vis[maxn];

int n;

ll m;

ll s[maxn], ec[maxn];

ll br;

ll pt;

vector<int> e[maxn];

void dfs(int v, int par){
    in[v] = tnow;
    tnow++;
    vis[v] = 1;
    fup[v] = in[v];
    for (int i = 0; i < e[v].size(); i++)
    if (e[v][i] != par){
        if (vis[e[v][i]])
            fup[v] = min(fup[v], in[e[v][i]]);
        else{
            dfs(e[v][i], v), fup[v] = min(fup[v], fup[e[v][i]]);
            if (fup[e[v][i]] > in[v])
                s[e[v][i]]++, s[v]++, br++;
        }
    }
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gift.in");
    //ofstream cout("gift.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        if (v == u)
            pt++;
        else
        e[v].push_back(u),
        e[u].push_back(v);
        ec[v]++;
        ec[u]++;
    }
    m -= pt;
    for (int i = 0; i < n; i++)
    if (ec[i] > 0){
        dfs(i, -1);
        break;
    }
    for (int i = 0; i < n; i++)
    if (ec[i] > 0 && !vis[i]){
        cout << 0;
        return 0;
    }
    ll answer = 0;
    for (int i = 0; i < n; i++){
        ll x = e[i].size();
        answer += x * (x - 1) / 2;
    }
    cout << answer + pt * (pt - 1) / 2 + pt * m;
}
/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

ll md(ll x){
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}

struct treap{
    int x, y, sz;
    ll val, ro, w;
    treap *l, *r;
};

typedef treap * ptr;

ptr create(int x, ll w){
    ptr t = new treap;
    t->x = x;
    t->w = w;
    t->sz = 1;
    t->val = w;
    t->ro = 0;
    t->y = rand();
    t->l = nullptr;
    t->r = nullptr;
    return t;
}

ll val(ptr t){
    return t == nullptr ? 0 : t->val;
}

ll ro(ptr t){
    return t == nullptr ? 0 : t->ro;
}

ll sz(ptr t){
    return t == nullptr ? 0 : t->sz;
}

void upd(ptr &t){
    if (t != nullptr){
        t->val = md(t->w + val(t->l) + val(t->r));
        t->sz = 1 + sz(t->l) + sz(t->r);
        t->ro = md(ro(t->l) + md(t->w * (sz(t->l) + 1)) + ro(t->r) + md(val(t->r) * (sz(t->l) + 1)));
    }
}

void split(ptr t, ptr &l, ptr &r, int key){
    if (t == nullptr){
        l = nullptr;
        r = nullptr;
        return;
    }
    if (t->x <= key)
        split(t->r, t->r, r, key), l = t;
    else
        split(t->l, l, t->l, key), r = t;
    upd(l);
    upd(r);
}

void merge(ptr &t, ptr l, ptr r){
    if (l == nullptr){
        t = r;
        return;
    }
    if (r == nullptr){
        t = l;
        return;
    }
    if (l->y <= r->y)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
}

ptr last(ptr t){
    if (t == nullptr || t->r == nullptr)
        return t;
    return last(t->r);
}

ptr frst(ptr t){
    if (t == nullptr || t->l == nullptr)
        return t;
    return frst(t->l);
}

int n;

int a[maxn];

map<int, int> mp;

int srt[maxn];

int fen[maxn];

ll lf[maxn], rg[maxn];

void inc(int i, int val){
    for (; i <= n; i = (i | (i + 1)))
        fen[i] += val;
}

int sum(int i){
    int ret = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        ret += fen[i];
    return ret;
}

ll answer;

ptr q[maxn], p[maxn];

void add(int id){
    ptr t1, t2, t3, t4, t5, t6;
    split(q[a[id]], t2, t1, -id);
    split(p[a[id]], t3, t4, id);
    if (t4 != nullptr){
        split(t4, t5, t4, frst(t4)->x);
        answer = md(answer + lf[id] * ro(t4));
        merge(t4, t5, t4);
    }
    if (t1 != nullptr){
        split(t1, t5, t1, frst(t1)->x);
        answer = md(answer + rg[id] * ro(t1));
        merge(t1, t5, t1);
    }
    answer = md(answer + val(t1) * val(t4));
    merge(t1, create(-id, lf[id]), t1);
    merge(q[a[id]], t2, t1);
    merge(t4, create(id, rg[id]), t4);
    merge(p[a[id]], t3, t4);
}

void rem(int id){
    ptr t1, t2, t3, t4, t5, t6;
    split(q[a[id]], t1, t2, -id - 1);
    split(t2, t2, t3, -id);
    merge(q[a[id]], t1, t3);
    split(p[a[id]], t1, t2, id - 1);
    split(t2, t2, t3, id);
    merge(p[a[id]], t1, t3);
    split(q[a[id]], t2, t1, -id);
    split(p[a[id]], t3, t4, id);
    if (t4 != nullptr){
        split(t4, t5, t4, frst(t4)->x);
        answer = md(answer - lf[id] * ro(t4));
        merge(t4, t5, t4);
    }
    if (t1 != nullptr){
        split(t1, t5, t1, frst(t1)->x);
        answer = md(answer - rg[id] * ro(t1));
        merge(t1, t5, t1);
    }
    answer = md(answer - val(t1) * val(t4));
    merge(q[a[id]], t2, t1);
    merge(p[a[id]], t3, t4);
}

void prec(){
    q[n] = nullptr;
    p[n] = nullptr;
    sort(srt, srt + n);
    for (int i = 0; i < n; i++)
        if (i == 0 || srt[i] > srt[i - 1])
            mp[srt[i]] = mp.size();
    for (int i = 0; i < n; i++)
        a[i] = mp[a[i]];
    for (int i = 0; i < n; i++){
        lf[i] = sum(a[i]);
        inc(a[i], 1);
    }
    for (int i = 0; i <= n; i++)
        fen[i] = 0;
    for (int i = n - 1; i >= 0; i--){
        rg[i] = sum(a[i]);
        inc(a[i], 1);
    }
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gift.in");
    //ofstream cout("gift.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], srt[i] = a[i], q[i] = nullptr, p[i] = nullptr;
    prec();
    for (int i = 0; i < n; i++)
        add(i);
    int zap;
    cin >> zap;
    for (int i = 0; i < zap; i++){
        int tp, id;
        cin >> tp >> id;
        id--;
        if (tp == 1)
            rem(id);
        else
            add(id);
        cout << answer << '\n';
    }
}
*/