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




int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> n >> k >> str;

    vector <int> pos[2];

    for(i = 0; i < n; i++) {
        str[i] -= '0';
        pos[str[i]].push_back(i);
    }

    if(pos[0].size() == 0 || pos[0].size() == n) {
        cout << "tokitsukaze";
        return 0;
    }

    for(i = 0; i < 2; i++) {
        if(pos[i].size() == 1) {
            cout << "tokitsukaze";
            return 0;
        }
        if(pos[i].back() - pos[i][0] + 1 <= k) {
            cout << "tokitsukaze";
            return 0;
        }
    }


    set <int> mst[2];
    for(i = 0; i < n; i++) {
        mst[str[i]].insert(i);
    }

    int ans = 0;
    for(int a = 0; a < 2; a++) {

        int pa = 0, pb = 0;
        for(i = 0; i + k <= n; i++) {
            while(pa < i) {
                mst[a].erase(pa);
                mst[str[pa]].insert(pa);
                pa++;
            }
            while(pb < i + k) {
                mst[str[pb]].erase(pb);
                mst[a].insert(pb);
                pb++;
            }

            int cur = 1;
            for(int j = 0; j < 2; j++) {
                if(mst[j].size() == 1) {
                    cur = 0;
                }
                if(mst[j].size() >= 2 && (*prev(mst[j].end()) - *mst[j].begin() + 1) <= k) {
                    cur = 0;
                }
            }
            ans = max(ans, cur);
        }

        mst[0].clear(), mst[1].clear();
        for(i = 0; i < n; i++) {
            mst[str[i]].insert(i);
        }
            //cerr << i << " " << cur << "\n";

    }

    if(ans == 0) {
        cout << "quailty";
    }
    else {
        cout << "once again";
    }

    return 0;
}