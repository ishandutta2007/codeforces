#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



#if 0
const int MOD = ;

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

inline int inv(int x) {
    return lgput(x, MOD - 2);
}
#endif

#if 0
int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}
#endif

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e6;

vector < pair <int, char> > g[MAXN + 1];

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    int N = n;

    auto addEdge = [&](int x, int y, int id) -> void {
        vector <int> dig;
        if(id == 0) dig.push_back(0);
        while(id > 0) {
            dig.push_back(id % 10);
            id /= 10;
        }
        reverse(dig.begin(), dig.end());
        for(int i = 0; i + 1 < dig.size(); i++) {
            g[x].push_back({++n, dig[i]});
            x = n;
        }
        g[x].push_back({y, dig.back()});
    };

    for(i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(x, y, i);
        addEdge(y, x, i);
    }

    vector <int> len(n + 1, n + 1);
    len[1] = 0;
    queue <int> Q;
    Q.push(1);

    while(Q.size()) {
        int nod = Q.front();
        Q.pop();
        for(auto it : g[nod]) {
            if(len[it.first] == n + 1) {
                len[it.first] = len[nod] + 1;
                Q.push(it.first);
            }
        }
    }

    vector <int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](const int &x, const int &y) {
                return len[x] < len[y];
         });

    vector <int> sol(n + 1), vals(n + 1, 1e9);
    vals[1] = 0;
    int cur = 0;
    i = 0;

    while(i < n) {
        int j = i;
        while(j < n && len[ord[i]] == len[ord[j]]) {
            for(auto itr : g[ord[j]]) {
                if(len[itr.first] == len[ord[j]] + 1) {
                    if(vals[itr.first] > vals[ord[j]] * 10 + itr.second) {
                        vals[itr.first] = vals[ord[j]] * 10 + itr.second;
                        sol[itr.first] = (10LL * sol[ord[j]] + itr.second) % MOD;
                    }
                }
            }
            j++;
        }

        vector < pair <int, int> > aux;
        int k = j;
        while(k < n && len[ord[j]] == len[ord[k]]) {
            aux.push_back({vals[ord[k]], ord[k]});
            k++;
        }

        sort(aux.begin(), aux.end());

        i = 0;
        while(i < aux.size()) {
            k = i;
            cur++;
            while(k < aux.size() && aux[i].first == aux[k].first) {
                vals[aux[k].second] = cur;
                k++;
            }
            i = k;
        }

        i = j;
    }

    for(i = 2; i <= N; i++) {
        cout << sol[i] << "\n";
    }

    return 0;
}