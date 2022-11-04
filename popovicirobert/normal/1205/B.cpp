#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



/*const int MOD = ;

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
}*/

/*int fact[], invfact[];

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
}*/

using namespace std;

const int INF = 1e9;

vector <ll> a;
vector <int> dst;
int n;

inline void bfs(int pos) {
    fill(dst.begin(), dst.end(), INF);
    queue <int> Q;
    Q.push(pos); dst[pos] = 0;
    while(Q.size()) {
        pos = Q.front();
        Q.pop();
        for(int i = 1; i <= n; i++) {
            if((a[i] & a[pos]) && dst[i] == INF) {
                Q.push(i);
                dst[i] = dst[pos] + 1;
            }
        }
    }
}

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    a.resize(n + 1);
    vector <int> fr(100);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 0; j < 60; j++) {
            if(a[i] & (1LL << j)) {
                fr[j]++;
            }
        }
    }
    for(i = 0; i < 60; i++) {
        if(fr[i] >= 3) {
            cout << 3;
            return 0;
        }
    }
    vector <ll> aux(1);
    for(i = 1; i <= n; i++) {
        if(a[i] != 0) aux.push_back(a[i]);
    }
    a = aux;
    n = (int) a.size() - 1;
    dst.resize(n + 1);
    int ans = INF;
    for(i = 1; i <= n; i++) {
        bfs(i);
        vector <int> only(n + 1, -1);
        for(j = 1; j <= n; j++) {
            int nod, cnt = 0;
            for(int k = 1; k <= n; k++) {
                if((a[j] & a[k]) && dst[j] == dst[k] + 1) {
                    cnt++;
                    nod = k;
                }
            }
            if(cnt == 1) {
                only[j] = nod;
            }
        }
        for(j = 1; j <= n; j++) {
            if(dst[j] > 1 && (a[i] & a[j]))
                ans = min(ans, dst[j] + 1);
        }
        for(j = 1; j <= n; j++) {
            if(j == i) continue;
            for(int k = 1; k <= n; k++) {
                if(k == i || j == k) continue;
                if((a[j] & a[k])) {
                    if(only[j] != k && only[k] != j) {
                        ans = min(ans, dst[j] + dst[k] + 1);
                    }
                }
            }
        }
    }
    if(ans == INF) {
        ans = -1;
    }
    cout << ans;

    return 0;
}