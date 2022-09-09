#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 3005;

int n, m;
vector <int> graph[MAXN];
int s1, t1, l1, s2, t2, l2;
bool used[MAXN];
vector <int> vs1, vs2, vt1, vt2;

vector <int> bfs(int start) {
    queue <pii > q;
    memset(used, 0, sizeof used);
    q.push(mapa(start, 0));
    used[start] = true;
    vector <int> ret;
    ret.resize(n);
    while (szof(q)) {
        pii p = q.front();
        q.pop();
        //cerr << p.ff << " " << p.ss << endl;
        ret[p.ff] = p.ss;
        for (int i = 0; i < szof(graph[p.ff]); ++i) {
            if (!used[graph[p.ff][i]]) {
                used[graph[p.ff][i]] = true;
                q.push(mapa(graph[p.ff][i], p.ss + 1));
            }
        }
    }
    return ret;
}

vector <int> now;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;--b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    cin >> s1 >> t1 >> l1;
    --s1;--t1;
    cin >> s2 >> t2 >> l2;
    --s2;--t2;

    vs1 = bfs(s1);
    vs2 = bfs(s2);
    vt1 = bfs(t1);
    vt2 = bfs(t2);
                    
    //cerr << vs2[t2] << endl;

    if (l1 < vs1[t1] || l2 < vs2[t2]) {
        cout << -1 << endl;
        return 0;
    }
    int ans = vs1[t1] + vs2[t2];
    //cout << ans << endl;

    for (int i = 0; i < n; ++i) {
        now = bfs(i);
        for (int j = 0; j < n; ++j) {
            int tmp1 = min(vs1[i] + now[j] + vt1[j], vs1[j] + now[j] + vt1[i]);
            int tmp2 = min(vs2[i] + now[j] + vt2[j], vs2[j] + now[j] + vt2[i]);
            if (tmp1 <= l1 && tmp2 <= l2) {
                ans = min(ans, tmp1 + tmp2 - now[j]);
            }
        }
    }

    cout << m - ans << endl;

    return 0;
}