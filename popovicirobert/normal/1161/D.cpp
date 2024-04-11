#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


const int MOD = 998244353;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

using namespace std;

const int MAXN = 1005;

vector < pair <int, int> > g[2 * MAXN + 1];
char str[MAXN + 1];

inline void addEdge(int x, int y, int c) {
    g[x].push_back({y, c});
    g[y].push_back({x, c});
}

int col[2 * MAXN + 1];

void dfs(int nod, int c) {
    col[nod] = c;
    for(auto it : g[nod]) {
        if(col[it.first] == -1) {
            dfs(it.first, c ^ it.second);
        }
    }
}

inline int solve(int n) {
    int i;
    for(i = 1; i <= n; i++) {
        col[i] = -1;
    }

    int cnt = 0;
    for(i = 1; i <= n; i++) {
        if(col[i] == -1) {
            dfs(i, 0);
            cnt++;
        }
    }

    for(i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            if((col[i] ^ col[it.first]) != it.second) {
                return 0;
            }
        }
    }

    return lgput(2, cnt - 1);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> str + 1;
    int n = strlen(str + 1);

    int ans = 0;
    for(int lenb = 1; lenb < n; lenb++) {
        int nod0 = lenb + n + 1, nod1 = lenb + n + 2;
        for(i = 1; i <= nod1; i++) {
            g[i].clear();
        }

        for(i = 1; i <= lenb; i++) {
            if(str[n - i + 1] == '0') {
                addEdge(i, i + lenb, 0);
            }
            if(str[n - i + 1] == '1') {
                addEdge(i, i + lenb, 1);
            }
        }

        addEdge(nod0, nod1, 1);
        addEdge(nod1, lenb, 0);

        for(i = lenb + 1; i <= n; i++) {
            if(str[n - i + 1] == '0') {
                addEdge(i + lenb, nod0, 0);
            }
            if(str[n - i + 1] == '1') {
                addEdge(i + lenb, nod1, 0);
            }
        }

        for(i = 1; i < lenb - i + 1; i++) {
            addEdge(i, lenb - i + 1, 0);
        }
        for(i = 1 + lenb; i < n + lenb - i + lenb + 1; i++) {
            addEdge(i, n + lenb - i + lenb + 1, 0);
        }

        add(ans, solve(nod1));
    }

    cout << ans;

    return 0;
}