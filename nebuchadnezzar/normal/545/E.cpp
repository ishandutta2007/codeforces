#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 3e5 + 5;

int n, m;
vector <pair <int, ll> > graph[MAXN];
int start;
ll dist[MAXN];
bool used[MAXN];
map <pii, int> inp;
vector <int> arrw;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        graph[a].puba(mapa(b, c));
        graph[b].puba(mapa(a, c));
        inp[mapa(a, b)] = i;
        inp[mapa(b, a)] = i;
        arrw.puba(c);
    }

    cin >> start;
    --start;
    priority_queue <pair <ll, int> > pq;
    pq.push(mapa(0, start));
    memset(dist, -1, sizeof dist);
    
    while (szof(pq)) {
        pair <ll, int> p = pq.top();
        pq.pop();
        while (szof(pq) && dist[p.ss] != -1) {
            p = pq.top();
            pq.pop();
        }
        if (dist[p.ss] != -1) {
            break;
        }
        p.ff *= -1;
        dist[p.ss] = p.ff;

        for (int i = 0; i < szof(graph[p.ss]); ++i) {
            if (dist[graph[p.ss][i].ff] == -1) {
                pq.push(mapa(-p.ff - graph[p.ss][i].ss, graph[p.ss][i].ff));
            }
        }
    }
    
    priority_queue <pair <pair <ll, ll>, pii > > pq2;
    pq2.push(mapa(mapa(0, 0), mapa(start, start)));    
    
    vector <int> arrans;
    ll ans = 0;

    while (szof(pq2)) {
        pair <pair <ll, ll>, pii > p = pq2.top();
        pq2.pop();
        while (szof(pq2) && used[p.ss.ss]) {
            p = pq2.top();
            pq2.pop();
        }
        if (used[p.ss.ss]) {
            break;
        }
        
        
        swap(p.ff.ff, p.ff.ss);
        p.ff.ss *= -1;

        used[p.ss.ss] = true;        
        if (p.ss.ff != p.ss.ss) {
            int tmp = inp[mapa(p.ss.ss, p.ss.ff)];
            arrans.puba(tmp);
            ans += arrw[tmp];
        }

        for (int i = 0; i < szof(graph[p.ss.ss]); ++i) {
            if (!used[graph[p.ss.ss][i].ff] && p.ff.ss + graph[p.ss.ss][i].ss == dist[graph[p.ss.ss][i].ff]) {
                pq2.push(mapa(mapa(-(p.ff.ss + graph[p.ss.ss][i].ss), -graph[p.ss.ss][i].ss), mapa(p.ss.ss, graph[p.ss.ss][i].ff)));
            }
        }
    }

    cout << ans << endl;
    for (int i = 0; i < szof(arrans); ++i) {
        cout << arrans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}