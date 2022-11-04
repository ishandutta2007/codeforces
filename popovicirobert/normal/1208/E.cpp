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

struct Data {
    int pos, val;
    int type;
    bool operator <(const Data &other) const {
        return pos < other.pos;
    }
};

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector <ll> sp(m + 2);

    while(n--) {
        int len;
        cin >> len;

        vector <Data> evs;
        for(i = 1; i <= len; i++) {
            int x;
            cin >> x;
            evs.push_back({i, x, 0});
            evs.push_back({m - (len - i) + 1, x, 1});
        }

        if(len < m) {
            evs.push_back({1, 0, 0});
            evs.push_back({m - len + 1, 0, 1});
        }
        if(len < m) {
            evs.push_back({len + 1, 0, 0});
            evs.push_back({m + 1, 0, 1});
        }
        sort(evs.begin(), evs.end());

        int last = 0, sz = evs.size();
        multiset <int> mst;

        i = 0;
        while(i < sz) {
            int j = i;
            while(j < sz && evs[i].pos == evs[j].pos) {
                if(evs[j].type == 0) {
                    mst.insert(evs[j].val);
                }
                else {
                    mst.erase(mst.find(evs[j].val));
                }
                j++;
            }

            if(evs[i].pos <= m) {
                sp[evs[i].pos] -= last;
                last = *prev(mst.end());
                sp[evs[i].pos] += last;
            }

            i = j;
        }
    }

    for(i = 1; i <= m; i++) {
        sp[i] += sp[i - 1];
        cout << sp[i] << " ";
    }

    return 0;
}