#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


map<vi, int> mp;
int sub[111];
void dfs(const vector<vi>& g, int u, int p) {
    sub[u] = 1;
    for (int v : g[u]) if (v != p) {
            dfs(g, v, u);
            sub[u] += sub[v];
        }
}
ii centroid(const vector<vi>& g, int u, int p, int no) {
    for (int v : g[u]) if (v != p) {
            if (sub[v] > no / 2) return centroid(g, v, u, no);
        }
    int c2 = u;
    for (int v : g[u]) if (v != p) {
            if (no - sub[v] <= no / 2) c2 = v;
        }
    return {u, c2};
}
int get(const vector<vi> &g, int u, int p) {
    vector<int> yo;
    for (int v : g[u]) if (v != p) {
            yo.emplace_back(get(g, v, u));
        }
    sort(all(yo));
    if (mp.count(yo)) return mp[yo];
    int no = sz(mp);
    return mp[yo] = no + 1;
}
// ii hsh(vector<ii> a) {
//     int h1 = X[110], h2 = X[110];
//     sort(all(a));
//     FOR (i, 0, sz(a) - 1) {
//         h1 ^= ((a[i].F * 1LL * X[i]) % inf);
//         h2 ^= ((a[i].S * 1LL * X[i]) % inf);
//     }
//     return {h1, h2};
// }
vector<ii> hsh(const vector<vi>& g) {
    int n = sz(g);
    vi vis(n);
    vector<ii> H;
    // pr(g);
    FOR (i, 0, n - 1) if (!vis[i]) {
        stack<int> st; st.push(i);
        int x = 0, no = 0; vis[i] = 1;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            x += sz(g[u]), no++;
            for (int v : g[u]) if (!vis[v]) {
                    vis[v] = 1;
                    st.push(v);
                }
        }
        if (x != 2 * (no - 1)) {
            return {{-1, -1}};
        }

        dfs(g, i, -1);
        ii c = centroid(g, i, -1, sub[i]);
        // pr(c);
        int h1 = get(g, c.F, c.S);
        int h2 = c.S != c.F ? get(g, c.S, c.F) : -2;
        if (h1 > h2) swap(h1, h2);
        H.emplace_back(h1, h2);
    }
    sort(all(H));
    return H;
}
int conn(const vector<vi> &g) {
    int n = sz(g);
    vi vis(n);
    int r = -1;
    FOR (i, 0, n - 1) if (!g[i].empty()) r = i;
    if (r == -1) return n == 2 ? 0 : -1;
    vis[r] = 1;
    stack<int> st; st.push(r);
    int x = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        ++x;
        for (int v : g[u]) if (!vis[v]) {
                vis[v] = 1;
                st.push(v);
            }
    }
    if (x != n - 1) return -1;
    FOR (i, 0, n - 1) if (!vis[i]) return i;
    while (1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    // FOR (i, 0, 110) X[i] = abs(rand() * 1LL * rand() * 1LL * rand() * 1LL * rand()) % inf;
    // vector<vi> g1 = {{}};
    // pr(hsh(g1));
    // return 0;
    // dfs(g1,1,-1);
    // pr(centroid(g1,1,-1));
    // vector<vi> g2 = {{1, 4}, {0, 2}, {1, 3}, {2}, {0}};
    // pr(hsh(g1), hsh(g2));
    // return 0;

    int t; cin >> t; while (t--) {
        mp.clear();
        int n, k;
        cin >> n >> k;

        vector<vector<vi>> g(k, vector<vi>(n));
        vector<vector<ii>> org;
        bool cant = 0;
        FOR (i, 0, k - 1) {
            int x; cin >> x;
            FOR (j, 1, x) {
                int a, b; cin >> a >> b; --a, --b;
                g[i][a].push_back(b), g[i][b].push_back(a);
            }
            org.emplace_back(hsh(g[i]));
            if (org.back()[0].F == -1) {
                cant = 1;
            }
            // if (i == 1) return 0;
        }
        sort(all(org));
        

        bool done = 0;
        if (!cant) {
            // ii yo = hsh(org);

            FOR (i, 0, k - 1) {
                int l = conn(g[i]);
                if (l == -1) continue;
                FOR (j, 0, n - 1) if (j != l) {
                    g[i][l].push_back(j), g[i][j].push_back(l);
                    {
                        vector<vector<ii>> now;
                        FOR (u, 0, n - 1) {
                            vi tmp = g[i][u];
                            for (int v : tmp) {
                                g[i][u].erase(find(all(g[i][u]), v));
                                g[i][v].erase(find(all(g[i][v]), u));
                            }
                            now.emplace_back(hsh(g[i]));
                            for (int v : tmp) {
                                g[i][u].push_back(v), g[i][v].push_back(u);
                            }
                        }
                        sort(all(now));
                        if (now == org) {
                            cout << "YES\n";
                            FOR (u, 0, n - 1) for (int v : g[i][u]) if (u < v) cout << u + 1 << " " << v + 1 << "\n";
                            done = 1; break;
                        }
                    }
                    g[i][l].erase(find(all(g[i][l]), j));
                    g[i][j].erase(find(all(g[i][j]), l));
                }
                break;
            }
        }
        if (!done) cout << "NO\n";
    }

    return 0;
}