#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

const int N = 3e6 + 123;
const int M = 2e5 + 123;
const int A = 'z' - 'a' + 2;

struct Node {
    int term;
    int nxt[A];
    int link;
    int p, ps;
    
    Node() {
        ps = -1;
        p = -1;
        term = -1;
        fill(nxt, nxt + A, -1);
        link = -1;
    }
};

int ptr = 1;
Node trie[N];

int get_id(const string &s) {
    int cur_v = 0;
    for (char cc : s) {
        int c = cc - 'a';
        if (trie[cur_v].nxt[c] == -1) {
            assert(false);
        }
        cur_v = trie[cur_v].nxt[c];
    }
    
    return trie[cur_v].term;
}

void add(const string &s, int id) {
    int cur_v = 0;
    for (char cc : s) {
        int c = cc - 'a';
        if (trie[cur_v].nxt[c] == -1) {
            trie[cur_v].nxt[c] = ptr++;
            trie[ptr - 1].p = cur_v;
            trie[ptr - 1].ps = c;
        }
        cur_v = trie[cur_v].nxt[c];
    }
    
    trie[cur_v].term = id;
}

int link(int v);

int go(int v, int c) {
    if (trie[v].nxt[c] != -1) {
        return trie[v].nxt[c];
    }
    if (v == 0) {
        return 0;
    }
    
    return trie[v].nxt[c] = go(link(v), c);
}

int link(int v) {
    if (trie[v].link != -1) {
        return trie[v].link;
    }
    
    if (v == 0 || trie[v].p == 0) {
        return 0;
    }
    
    return trie[v].link = go(link(trie[v].p), trie[v].ps);
}

int n, k;
set<int> q[M];

int run() {
    cin >> n >> k;
    string s;
    cin >> s;
    int l = (int) s.size();
    s = s + s;
    
    int g;
    cin >> g;
    for (int i = 0; i < g; i++) {
        string t;
        cin >> t;
        add(t, i + 1);
    }
    
    int cur_v = 0;
    
    for (int i = 0; i < 2 * l; i++) {
        cur_v = go(cur_v, s[i] - 'a');
        
        if (trie[cur_v].term != -1) {
            int beg = i - k + 1;
            if (beg < l) {
                q[beg % k].insert(cur_v);
            }
        }
    }
    
    for (int i = 0; i < k; i++) {
        if ((int) q[i].size() == n) {
            cout << "YES\n";
            for (int j = 0; j < n; j++) {
                cout << get_id(s.substr(i + j * k, k)) << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    
    cout << "NO\n";
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}