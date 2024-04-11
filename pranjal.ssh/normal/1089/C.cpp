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


vector<vi> g;
int G[500][500];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    FOR (i, 0, n - 1) FOR (j, 0, n - 1) G[i][j] = inf * (i != j);
    g.resize(n);
    while (m--) {
        int k; cin >> k; vi a(k);
        FOR (i, 0, k - 1) cin >> a[i], --a[i];
        FOR (i, 1, k - 1) g[a[i-1]].push_back(a[i]), g[a[i]].push_back(a[i-1]), G[a[i]][a[i-1]]=G[a[i-1]][a[i]]=1;
    }

    FOR (k, 0, n - 1) FOR (i, 0, n - 1) FOR (j, 0, n - 1) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    
    FOR (_, 1, n) {
        vi poss(n, 1); vi bc(n); iota(all(bc), 0);
        
        while (1) {
            ii mn(inf, -1);
            for (int i: bc) {
                vi yo(n);
                for (int j: g[i]) if (poss[j]) {
                    for (int k: bc) {
                        if (G[i][k] - G[j][k] == 1) {
                            yo[j]++;
                        }
                    }
                }
                mn = min(mn, ii(*max_element(all(yo)), i));
            }
            cout << mn.S + 1 << endl;
            string s; cin >> s;
            if (s == "FOUND") {
                break;
            }
            int w; cin >> w; --w;
            fill(all(poss), 0);
            for (int i: bc) if (G[mn.S][i] - G[w][i] == 1) {
                poss[i] = 1;
            }
            bc.clear();
            FOR (i, 0, n - 1) if (poss[i]) bc.push_back(i);
        }
    }
    
    return 0;
}