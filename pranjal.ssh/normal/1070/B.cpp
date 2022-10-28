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


ll IPToLL(string s) {
    if (s[sz(s)-2] == '/') s.resize(sz(s)-2);
    else if (s[sz(s)-3] == '/') s.resize(sz(s)-3);
    s.erase(s.begin());
    s += ".";
    int yo = 24;
    ll ans = 0;
    FOR (i, 0, sz(s) - 1) {
        int j = i;
        while (s[j] != '.') ++j;
        ans |= (stoll(s.substr(i, j-i)) << yo);
        yo -= 8;
        i = j;
    }
    // pr(bitset<32>(ans).to_string());
    return ans;
}
string LLToIP(ll x, int dep) {
    string ans;
    ans += to_string((x >> 24) & 255) + ".";
    ans += to_string((x >> 16) & 255) + ".";
    ans += to_string((x >> 8) & 255) + ".";
    ans += to_string((x >> 0) & 255);
    return ans + "/" + to_string(dep);
}

struct trie {
    int nope;
    struct node {
        int n[2];
        bool col[2];
        bool ncol[2];
        node(){n[0]=n[1]=0; ncol[0]=ncol[1]=col[0]=col[1]=0;}
    };
    vector<node> T;
    trie(): nope(0), T(2) {}
    int make_node() {
        T.emplace_back();
        return sz(T) - 1;
    }
    vector<string> ans;
    void insert(int no, ll x, int i, int dep, bool col) {
        T[no].ncol[col] = 1;

        if (T[no].col[!col]) {
            nope = 1;
        }
        if (dep == i) {
            if (T[no].ncol[!col]) nope = 1;
            T[no].col[col] = 1;
            return;
        }
        int k = !!(x & (1LL << (31 - i)));
        // if (dep == 30) pr(x, no, i, k);
        if (!T[no].n[k]) {
            int l = make_node();
            T[no].n[k] = l;
        }
        insert(T[no].n[k], x, i + 1, dep, col);
    }
    void dfs(int no, int i, ll x) {
        // pr(no, i, bitset<32>(x).to_string(), T[no].ncol[0], T[no].ncol[1]);
        if (!T[no].ncol[1]) {
            return;
        }
        if (!T[no].ncol[0]) {
            ans.emplace_back(LLToIP(x, i));
            return;
        }
        if (T[no].n[0]) dfs(T[no].n[0], i+1, x);
        if (T[no].n[1]) dfs(T[no].n[1], i+1, x|(1LL<<(32 - (i + 1))));
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    trie T;
    FOR (it, 1, n) {
        string s; cin >> s;
        bool p = (s[0] == '-');
        if (s[sz(s) - 3] != '/' and s[sz(s) - 2] != '/') s += "/32";
        ll x = 0;
        int dep = stoi(s.substr(sz(s) - (s[sz(s) - 3] == '/' ? 2 : 1)));
        T.insert(1, IPToLL(s), 0, dep, p);
    }
    if (T.nope) {
        cout << "-1\n";
    } else {
        T.dfs(1, 0, 0);
        cout << T.ans.size() << "\n";
        for (auto it: T.ans) cout << it << "\n";
    }
    
    return 0;
}