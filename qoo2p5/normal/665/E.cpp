#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = (int) 1e6 + 123;
const int L = 30;

struct Trie {
    int go[2];
    int c;
    
    Trie() {
        fill(go, go + 2, -1);
        c = 0;
    }
};

int ptr = 1;
Trie t[N * L];

int n, k;

void add(int x) {
    int v = 0;
    t[v].c++;
    for (int i = L - 1; i >= 0; i--) {
        int bit = bool(x & (1 << i));
        int u = t[v].go[bit];
        if (u == -1) {
            u = ptr++;
            t[v].go[bit] = u;
        }
        t[u].c++;
        v = u;
    }
}

int calc(int x) {
    int res = 0;
    int v = 0;
    
    for (int i = L - 1; i >= 0; i--) {
        int bit_x = bool(x & (1 << i));
        int bit_k = bool(k & (1 << i));
        
        if (!bit_k) {
            int need = !bit_x;
            res += (t[v].go[need] == -1 ? 0 : t[t[v].go[need]].c);
        }
        
        {
            int to = bit_x ^ bit_k;
            v = t[v].go[to];
            if (v == -1) {
                break;
            }
        }
    }
    
    return res + (v == -1 ? 0 : t[v].c);
}

void run() {
    cin >> n >> k;
    int pref = 0;
    ll ans = 0;
    add(0);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pref ^= x;
        ans += calc(pref);
        
        add(pref);
    }
    
    cout << ans << "\n";
}