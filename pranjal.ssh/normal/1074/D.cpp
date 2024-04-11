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
    map<int, int> p, r, h;
    map<int, vi> val;
    DSU(){}

    int get(int i) {
        if (!p.count(i)) p[i] = i;
        if (p[i] != i) {
            int x = get(p[i]);
            p[i] = x;
        }
        return p[i];
    }
    void connect(int i, int j, int X) {
        int x = get(i), y = get(j);
        assert(x != y);
        if (r[x] > r[y]) swap(x, y);
        p[x] = y;
        if (r[y] == r[x]) ++r[y];
        if (!val.count(x)) val[x] = {x};
        if (!val.count(y)) val[y] = {y};
        int bc = h[i] ^ X;
        bc ^= h[j];
        for (int it: val[x]) {
            h[it] ^= bc;
            val[y].push_back(it);
        }
        val.erase(x);
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    DSU ds;
    int last = 0;
    int q; cin >> q; while (q--) {
        int t, l, r, x; cin >> t >> l >> r;
        l ^= last, r ^= last;
        if (l > r) swap(l, r);
        --l;
        if (t == 1) {
            cin >> x; x ^= last;
            if (ds.get(l) == ds.get(r)) continue;
            ds.connect(l, r, x);
        } else {
            if (ds.get(l) == ds.get(r)) {
                cout << (last = (ds.h[l] ^ ds.h[r])) << "\n";
            } else {
                cout << "-1\n";
                last = 1;
            }
        }
    }
    
    return 0;
}