/*
    Author: Pranjal
    Idea: Exactly as editorial https://codeforces.com/blog/entry/60920
*/

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


struct DSU {
    vi p, r;
    vector<map<int, int>> nxt;
    int num;
    DSU(int n):p(n),r(n),nxt(n),num(0) {
        FOR(i, 0, n - 1)p[i] = i;
    }

    int get(int i) {
        if (p[i] != i)p[i] = get(p[i]);
        return p[i];
    }
    int connect(int i, int j) {
        int x = get(i), y = get(j);
        if (x == y) return 0;
        --num;
        if (r[x] > r[y]) swap(x, y);
        p[x] = y;
        for (auto it: nxt[x]) {
            nxt[y].insert(it);
        }
        assert(nxt[y].count(i) and nxt[y].count(j));
        swap(nxt[y][i], nxt[y][j]);
        r[y] += r[x];
        return 1;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); srand(8);

    int n, s; cin >> n >> s;
    vi a(n);
    FOR (i, 0, n - 1) {
        cin >> a[i];
    }

    vi b = a; sort(all(b));
    map<int, vector<int>> pos, gpos;
    FOR (i, 0, n - 1) if (a[i] != b[i]) {
        pos[b[i]].push_back(i);
        gpos[a[i]].push_back(i);
    }
    
    vi vis(n);
    DSU ds(n);
    int len = 0;
    FOR (i, 0, n - 1) if (!vis[i] and a[i] != b[i]) {
        int x = i; int cur = 0;
        do {
            vis[x] = 1;
            int y = pos[a[x]].back();
            pos[a[x]].pop_back();
            ds.p[x] = i;
            ds.nxt[i][x] = y;
            x = y;
            ++cur;
            ++len;
        } while (x != i);
        ds.num++;
        ds.r[i] = cur;
    }

   for (auto it: gpos) {
        const auto &A = it.S;
        FOR (i, 1, sz(A) - 1) {
            ds.connect(A[i], A[i-1]);
        }
    }
    vector<vi> cycles;

    FOR (i, 0, n - 1) if (a[i] != b[i] and ds.get(i) == i) {
        cycles.emplace_back();
        int x = i;
        do {
            cycles.back().emplace_back(x);
            x = ds.nxt[i][x];
        } while (x != i);
    }

    s -= len;
    if (s < 0) {
        cout << "-1\n";
        return 0;
    }
    int x = min(s, sz(cycles));
    vector<vi> ans;
    
    if (x > 1) {
        ans.emplace_back();
        ans.emplace_back();
        FOR (i, 0, x-1) {
            for (int j: cycles[i]) ans[0].emplace_back(j);
            ans[1].emplace_back(cycles[i][0]);
        }
        reverse(all(ans[1]));
        FOR (i, x, sz(cycles) - 1) ans.emplace_back(cycles[i]);
    }  else ans = cycles;

    cout << sz(ans) << "\n";
    for (auto it: ans) {
        cout << sz(it) << "\n";
        for (auto itt: it) cout << itt+1 << " ";
        cout << "\n";
    }
    
    return 0;
}