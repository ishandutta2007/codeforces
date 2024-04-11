#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXVAL = (int) 1e5;

struct Trie {
    Trie *son[2];
    int mn;
    Trie() {
        memset(son, 0, sizeof(son));
        mn = MAXVAL;
    }
};

Trie *root[MAXVAL + 1];

vector <int> divi[MAXVAL + 1];

inline void prec() {
    for(int i = 1; i <= MAXVAL; i++) {
        root[i] = new Trie;
        for(int j = i; j <= MAXVAL; j += i)
            divi[j].push_back(i);
    }
}

void add(Trie *nod, char bit, int x) {
    nod -> mn = min(nod -> mn, x);
    if(bit >= 0) {
        bool b = ((x & (1 << bit)) > 0);
        if(nod -> son[b] == NULL)
            nod -> son[b] = new Trie;
        add(nod -> son[b], bit - 1, x);
    }
}

int solve(Trie *nod, char bit, int x, int s) {
    if(bit == -1) {
        return nod -> mn;
    }
    else {
        bool b = ((x & (1 << bit)) > 0);
        if(nod -> son[1 - b] != NULL && nod -> son[1 - b] -> mn <= s) {
            return solve(nod -> son[1 - b], bit - 1, x, s);
        }
        else if(nod -> son[b] != NULL && nod -> son[b] -> mn <= s) {
            return solve(nod -> son[b], bit - 1, x, s);
        }
        else {
            return -1;
        }
    }
}

bool vis[MAXVAL + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q, x, k, s, t;
    ios::sync_with_stdio(false);
    prec();
    cin >> q;
    while(q > 0) {
        q--;
        cin >> t;
        if(t == 1) {
            cin >> x;
            if(vis[x] == 1)
                continue;
            vis[x] = 1;
            for(auto it : divi[x]) {
                add(root[it], 16, x);
            }
        }
        else {
            cin >> x >> k >> s;
            if(x % k == 0) {
                int ans = solve(root[k], 16, x, s - x);
                cout << ans << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}