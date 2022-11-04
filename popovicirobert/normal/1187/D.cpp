#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


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
}*/


using namespace std;

const int INF = 1e9;

struct SegTree {
    vector <int> aint;
    int n;

    inline void init(int _n) {
        n = _n;
        aint.resize(2 * n, INF);
    }

    void update(int pos, int val) {
        pos += n - 1;
        aint[pos] = val;
        while(pos > 1) {
            pos >>= 1;
            aint[pos] = min(aint[2 * pos], aint[2 * pos + 1]);
        }
    }

    int query(int l, int r) {
        if(l > r) return INF;

        l += n - 1, r += n - 1;
        int ans = INF;

        while(l != r) {
            if(l & 1) {
                ans = min(ans, aint[l]);
                l++;
            }
            if(r & 1) {
                r--;
                ans = min(ans, aint[r]);
            }
            l >>= 1, r >>= 1;
        }
        return ans;
    }
};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector <int> a(n + 1), b(n + 1);
        for(i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(i = 1; i <= n; i++) {
            cin >> b[i];
        }

        vector < vector <int> > pos(n + 1);
        for(i = n; i >= 1; i--) {
            pos[a[i]].push_back(i);
        }

        SegTree st; st.init(n);
        for(i = 1; i <= n; i++) {
            st.update(i, a[i]);
        }

        bool ans = 1;
        for(i = 1; i <= n; i++) {
            if(pos[b[i]].empty()) {
                ans = 0;
                break;
            }

            int p = pos[b[i]].back();
            pos[b[i]].pop_back();

            if(st.query(1, p) < b[i]) {
                ans = 0;
                break;
            }
            st.update(p, INF);
        }

        if(ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    //cin.close();
    //cout.close();
    return 0;
}