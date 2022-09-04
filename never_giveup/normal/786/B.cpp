#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

const ll inf = 1e18;

int n, st, zap, sz;

vector<pair<ll, int> > e[8 * maxn];

ll d[8 * maxn];

int id[maxn];

void build1(int v, int l, int r){
    d[v] = inf;
    if (l == r){
        sz = max(sz, v);
        id[l] = v;
        return;
    }
    int m = (l + r) / 2;
    e[v].push_back(make_pair(0, 2 * v));
    e[v].push_back(make_pair(0, 2 * v + 1));
    build1(2 * v, l, m);
    build1(2 * v + 1, m + 1, r);
}

void build2(int v, int l, int r, int parent){
    if (l == r){
        if (parent != -1)
            e[id[l]].push_back(make_pair(0, parent));
        return;
    }
    d[v + sz] = inf;
    if (parent != -1)
        e[v + sz].push_back(make_pair(0, parent));
    int m = (l + r) / 2;
    build2(2 * v, l, m, v + sz);
    build2(2 * v + 1, m + 1, r, v + sz);
}

void update(int v, int tl, int tr, int l, int r, ll val, int ind, int tp){
    if (l > r)
        return;
    if (tl == l && tr == r){
        if (tp == 0)
            e[ind].push_back(make_pair(val, v));
        else
        if (tl == tr)
            e[v].push_back(make_pair(val, ind));
        else
            e[v + sz].push_back(make_pair(val, ind));
        return;
    }
    int m = (tl + tr) / 2;
    update(2 * v, tl, m, l, min(r, m), val, ind, tp);
    update(2 * v + 1, m + 1, tr, max(l, m + 1), r, val, ind, tp);
}

set<pair<ll, int> > g;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> zap >> st;
    st--;
    build1(1, 0, n - 1);
    build2(1, 0, n - 1, -1);
    for (int i = 0; i < zap; i++){
        int tp;
        cin >> tp;
        if (tp == 1){
            int v, u;
            ll w;
            cin >> v >> u >> w;
            e[id[v - 1]].push_back(make_pair(w, id[u - 1]));
        }
        else{
            int ind, l, r;
            ll w;
            cin >> ind >> l >> r >> w;
            ind = id[ind - 1];
            update(1, 0, n - 1, l - 1, r - 1, w, ind, tp - 2);
        }
    }
    d[id[st]] = 0;
    g.insert(make_pair(0, id[st]));
    while (!g.empty()){
        int v = g.begin()->second;
        g.erase(g.begin());
        for (int i = 0; i < e[v].size(); i++){
            int to = e[v][i].second;
            ll val = e[v][i].first + d[v];
            if (d[to] > val){
                g.erase(make_pair(d[to], to));
                d[to] = val;
                g.insert(make_pair(d[to], to));
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (d[id[i]] == inf)
            cout << "-1 ";
        else
            cout << d[id[i]] << ' ';
}

/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100, mod = 1e9 + 993;

const ll llinf = 1e18;

int k, b[maxn];

vector<int> q[10][5][10];

vector<int> all[10];

int get(int x1, int x2, int x3, int x4, int x5){
    return x1 * 10000 + x2 * 1000 + x3 * 100 + x4 * 10 + x5;
}

int prc[10][maxn][2];

ll answer = llinf;

int id[5], p[5];

void fun(int D, int it){
    if (it == 5){
        int val = 0;
        for (int i = 0; i < 5; i++)
            p[i] = 0;
        while (val < all[D].size()){
            bool ez = 0;
            for (int i = 0; i < 5; i++)
                if (q[D][i][id[i]].size() > p[i] && q[D][i][id[i]][p[i]] == all[D][val])
                    p[i]++, ez = 1;
            if (!ez){
                prc[D][get(id[0], id[1], id[2], id[3], id[4])][0] = all[D][val];
                break;
            }
            val++;
        }
        if (val == all[D].size())
            prc[D][get(id[0], id[1], id[2], id[3], id[4])][0] = -1;
        val = all[D].size() - 1;
        for (int i = 0; i < 5; i++)
            p[i] = q[D][i][id[i]].size() - 1;
        while (val >= 0){
            bool ez = 0;
            for (int i = 0; i < 5; i++)
                if (0 <= p[i] && q[D][i][id[i]][p[i]] == all[D][val])
                    p[i]--, ez = 1;
            if (!ez){
                prc[D][get(id[0], id[1], id[2], id[3], id[4])][1] = val;
                break;
            }
            val--;
        }
        if (val == -1)
            prc[D][get(id[0], id[1], id[2], id[3], id[4])][1] = val;
        return;
    }
    for (int i = 0; i < 10; i++)
        id[it] = i, fun(D, it + 1);
}

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    ifstream cin("sequence.in");
    ofstream cout("sequence.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    answer = llinf;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> b[i];
        int x = i;
        for (int j = 0; j < 5; j++)
            q[b[i]][j][x % 10].push_back(i), x /= 10;
        all[b[i]].push_back(i);
    }
    for (int i = 0; i < 10; i++)
        fun(i, 0);
    for (int start = 0; start < 1e3; start++){
        bool need[10][2];
        if (start == 47){
            int kek = 1;
        }
        for (int c = 0; c < 10; c++){
            need[c][0] = 0;
            need[c][1] = 0;
        }
        for (int c = 0; c < 10; c++){
            int vl = 0;
            int x = start;
            for (int k = 0; k < 5; k++){
                int r = c - x % 10;
                if (r < 0)
                    r += 10;
                vl = vl * 10 + r;
                x /= 10;
            }
            int w = prc[c][vl][0], h = prc[c][vl][1];
            if (w != -1 && w + start < 1e5)
                need[c][0] = 1;
            if (h != -1 && h + start >= 1e5)
                need[c][1] = 1;
        }
        bool ez = 1;
        ll ansnow = start;
        ll rlen = 1;
        ll cpy = start;
        while (cpy > 0)
            rlen *= 10, cpy /= 10;
        if (rlen == 1)
            rlen *= 10;
        int first = 0;
        for (int i = 1; i < 10; i++)
        if (need[i][0] || need[i][1]){
            first = i;
            break;
        }
        for (int i = 0; i < 10; i++)
        if (need[i][1]){
            ez = 0;
            break;
        }
        if (ez){
            if (first == 0)
                if (need[0][0])
                    answer = min(answer, rlen * 10 + start);
                else
                    answer = min(answer, (ll)start);
            else{
                ansnow = first * 10;
                for (int i = first + 1; i < 10; i++)
                    if (need[i][0])
                        ansnow = ansnow * 10 + i;
                answer = min(answer, rlen * ansnow + start);
            }
        }
        else{

        }
    }
    cout << answer;
}
*/