#include <bits/stdc++.h>
#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
 
using namespace std;

#define TASK ""

int solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (TASK == "input") {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (TASK != "") {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    return solve();
}

const int dd = (int)3e5 + 3;

bool prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int get(int x) {
    while (true) {
        int y = x + rand() % 1000;
        if (prime(y)) {
            return y;
        }
    }
}

struct Hash {
    int p, mod;
    vector<int> M, pw;

    Hash() {}
    Hash(vector<int> &A, int pp, int mmod) {
        p = pp, mod = mmod;
        M.resize(A.size() + 1), pw.resize(A.size() + 1);
        pw[0] = 1, M[0] = 0;
        for (int i = 0; i < (int)A.size(); ++i) {
            M[i + 1] = (1ll * M[i] * p + A[i]) % mod;
            pw[i + 1] = 1ll * pw[i] * p % mod;
        }
    }
    int get(int l, int r) {
        if (r >= (int)M.size()) {
            return -(int)1e9;
        }
        int ans = M[r] - 1ll * M[l] * pw[r - l] % mod;
        if (ans < 0) ans += mod;
        return ans;
    }
};

vector<int> A[10], P[10];
Hash L[2][10];

int solve() {
    srand(time(0));
    int n, m;
    cin >> n >> m;
    int p1 = get(100000), p2 = get(200000), mod1 = get((int)1e9), mod2 = get((int)8e8);
    for (int i = 0; i < m; ++i) {
        A[i].resize(n);
        P[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
            --A[i][j];
            P[i][A[i][j]] = j;
        }
        L[0][i] = Hash(A[i], p1, mod1);
        L[1][i] = Hash(A[i], p2, mod2);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int M = (l + r) >> 1;
            int H0 = L[0][0].get(P[0][i], P[0][i] + M);
            int H1 = L[1][0].get(P[0][i], P[0][i] + M);
            if (H0 == -(int)1e9) {
                r = M;
                continue;
            }
            for (int j = 1; j < m; ++j) {
                if (H0 != L[0][j].get(P[j][i], P[j][i] + M) ||
                    H1 != L[1][j].get(P[j][i], P[j][i] + M)) {
                    r = M;
                    break;
                }
            }
            if (r != M) {
                l = M;
            }
        }
        ans += l;
    }
    cout << ans << "\n";
    return 0;
}