#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
const int MAXN = 1e5 + 5;

int n, m;
vector <pii> graph[MAXN];

bool used[MAXN];
int by0[MAXN];
int from_by0[MAXN];
int from[MAXN];
int cost_here[MAXN];
int cou[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //cin >> n >> m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        graph[a].puba(mapa(b, c));
        graph[b].puba(mapa(a, c));
    }

    queue <pii> qu;
    qu.push(mapa(n - 1, 0));
    used[n - 1] = true;
    memset(from_by0, -1, sizeof from_by0);
    memset(by0, -1, sizeof by0);

    while (szof(qu)) {
        pii p = qu.front();
        qu.pop();
        by0[p.ff] = p.ss;
        for (int i = 0; i < szof(graph[p.ff]); ++i) {
            if (!used[graph[p.ff][i].ff] && graph[p.ff][i].ss == 0) {
                used[graph[p.ff][i].ff] = true;
                qu.push(mapa(graph[p.ff][i].ff, p.ss + 1));
                from_by0[graph[p.ff][i].ff] = p.ff;
            }
        }
    }
    
    /*
    for (int i = 0; i < n; ++i) {
        cerr << by0[i] << endl;
    }*/

    set <pair <pair <pii, int>, pii>> st;
    memset(used, 0, sizeof used);
    st.insert(mapa(mapa(mapa(0, 0), 0), mapa(0, -1)));

    memset(from, -1, sizeof from);
    int end = -1;

    int co = 0;

    int prev = -1;

    pair <pii, int> ans = mapa(mapa(1e9, 1e9), 1e9);

    while (szof(st)) {
        pair <pair <pii, int>, pii> p;
        do {
            p = *st.begin();
            st.erase(st.begin());
        } while (szof(st) && used[p.ss.ff]);
        if (used[p.ss.ff]) {
            break;
        }

        used[p.ss.ff] = true;
        from[p.ss.ff] = p.ss.ss;
        cost_here[p.ss.ff] = p.ff.ff.ss;
        
        if (prev != -1) {
            if (from[prev] == -1) {
                ++co;
            } else {
                if (cou[from[prev]] == cou[from[p.ss.ff]] && cost_here[prev] == cost_here[p.ss.ff]) {
                    
                } else {
                    ++co;
                }
            }
        }

        cou[p.ss.ff] = co;
        //cerr << p.ss.ff << " " << co << endl;

        if (by0[p.ss.ff] != -1) {
            ans = min(ans, mapa(mapa(co, by0[p.ss.ff]), p.ss.ff));
        }

        for (int i = 0; i < szof(graph[p.ss.ff]); ++i) {
            if (!used[graph[p.ss.ff][i].ff]) {
                st.insert(mapa(mapa(mapa(p.ff.ff.ff + 1, graph[p.ss.ff][i].ss), co), mapa(graph[p.ss.ff][i].ff, p.ss.ff)));
            }
        }        
        prev = p.ss.ff;
    }   
    
    end = ans.ss;

    cerr << end << endl;

    vector <int> v;
    int pos = end;
    while (pos != -1) {
        v.puba(pos);
        //cerr << "pos: " << pos << endl;
        if (pos != 0) {
            printf("%d", cost_here[pos]);
        }
        pos = from[pos];
    }

    if (end == 0) {
        printf("0");
    }

    printf("\n");

    reverse(bend(v));

    pos = from_by0[end];

    while (pos != -1) {
        v.puba(pos);
        pos = from_by0[pos];
    }
    printf("%d\n", szof(v));

    for (int i = 0; i < szof(v); ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}