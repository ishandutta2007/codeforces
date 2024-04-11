#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = (int) ;

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

const int INF = (int) 2e9;
const int MAXN = (int) 1e5;

struct Node {
    int mn, mx;
    Node() {
        mn = INF, mx = -INF;
    }
    Node(int _mn, int _mx) {
        mn = _mn, mx = _mx;
    }
};

Node rmql[MAXN + 1][18], rmqr[MAXN + 1][18];

inline Node combine(Node a, Node b) {
    return Node(min(a.mn, b.mn), max(a.mx, b.mx));
}

int lg[MAXN + 1];

inline Node get(int l, int r, Node rmq[MAXN + 1][18]) {
    if(l > r) return Node();

    int bit = lg[r - l + 1];
    return combine(rmq[l][bit], rmq[r - (1 << bit) + 1][bit]);
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector < pair <int, int> > s1(n), s2(n);
    for(i = 0; i < n; i++) {
        cin >> s1[i].first >> s1[i].second >> s2[i].first >> s2[i].second;
    }

    for(i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }

    auto solve = [&](vector < pair <int, int> > &s1, vector < pair <int, int> > &s2) {
        vector <int> ordl(n), ordr(n);
        iota(ordl.begin(), ordl.end(), 0);
        ordr = ordl;

        sort(ordl.begin(), ordl.end(), [&](const int &a, const int &b) {
                return s1[a] < s1[b];
            });
        sort(ordr.begin(), ordr.end(), [&](const int &a, const int &b) {
                return s1[a].second < s1[b].second;
            });

        for(i = 0; i < n; i++) {
            rmql[i][0] = Node(s2[ordl[i]].second, s2[ordl[i]].first);
            rmqr[i][0] = Node(s2[ordr[i]].second, s2[ordr[i]].first);
        }
        for(int bit = 1; (1 << bit) <= n; bit++) {
            for(i = 0; i + (1 << bit) <= n; i++) {
                rmql[i][bit] = combine(rmql[i][bit - 1], rmql[i + (1 << (bit - 1))][bit - 1]);
                rmqr[i][bit] = combine(rmqr[i][bit - 1], rmqr[i + (1 << (bit - 1))][bit - 1]);
            }
        }

        for(i = 0; i < n; i++) {
            int r1 = -1, r2 = -1;
            int l1 = -1, l2 = -1;

            for(int step = 1 << 18; step; step >>= 1) {
                if(l1 + step < n && s1[ordl[l1 + step]].first < s1[i].first) {
                    l1 += step;
                }
                if(l2 + step < n && s1[ordl[l2 + step]].first <= s1[i].second) {
                    l2 += step;
                }
                if(r1 + step < n && s1[ordr[r1 + step]].second < s1[i].first) {
                    r1 += step;
                }
                if(r2 + step < n && s1[ordr[r2 + step]].second <= s1[i].second) {
                    r2 += step;
                }
            }

            Node curl = get(l1 + 1, l2, rmql), curr = get(r1 + 1, r2, rmqr);

            if(curl.mn < s2[i].first || curl.mx > s2[i].second || curr.mn < s2[i].first || curr.mx > s2[i].second) {
                cout << "NO";
                exit(0);
            }
        }

    };

    solve(s1, s2);
    swap(s1, s2);
    solve(s1, s2);

    cout << "YES";

    return 0;
}