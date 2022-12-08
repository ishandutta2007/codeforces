#include <bits/stdc++.h>
    #ifdef PoDuReM
        #define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #else
        #define err(...) 42
    #endif

typedef long long ll;

using namespace std;

#define TASK ""
#define multiTest 0

void solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (!strcmp(TASK, "input")) {
            assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
        } else if (strcmp(TASK, "")) {
            assert(freopen(TASK".in", "r", stdin)); assert(freopen(TASK".out", "w", stdout));
        }
    #endif
    int t = 1;
    if (multiTest) {
        cin >> t;
    }
    while (t--) solve();
    return 0;
}

const int dd = (int)1e5 + 7;

bool prime(int p) {
    for (int i = 2; i * i <= p; ++i) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

int get(int p) {
    while (1) {
        int x = p + rand() % 100;
        if (prime(x)) {
            return x;
        }
    }
}

struct Hash {
    int p, mod;
    vector<int> H, pw;

    Hash() {}
    Hash(string s) {
        mod = ::get(803374256);
        p = ::get(3);
        H.resize(s.size() + 1);
        pw.resize(s.size() + 1);
        pw[0] = 1;
        for (int i = 1; i <= (int)s.size(); ++i) {
            pw[i] = 1ll * pw[i - 1] * p % mod;
            H[i] = (1ll * H[i - 1] * p + s[i - 1]) % mod;
        }
    }

    int get(int l, int r) {
        int res = H[r] - 1ll * H[l] * pw[r - l] % mod;
        if (res < 0) {
            res += mod;
        }
        return res;
    }
} h1, h2;

string s, t;

bool check(int x, int y) {
    int l = 0;
    int HASH01 = -1, HASH02 = -1, HASH11 = -1, HASH12 = -1;
    for (char c : s) {
        int r = l + (c == '0' ? x : y);

        int H1 = h1.get(l, r), H2 = h2.get(l, r);

        if (c == '0') {
            if (HASH01 != -1 && HASH01 != H1) {
                return false;
            }
            if (HASH02 != -1 && HASH02 != H2) {
                return false;
            }
            HASH01 = H1, HASH02 = H2;
        } else {
            if (HASH11 != -1 && HASH11 != H1) {
                return false;
            }
            if (HASH12 != -1 && HASH12 != H2) {
                return false;
            }
            HASH11 = H1, HASH12 = H2;
        }
        l = r;
    }
    return HASH01 != HASH11 && HASH02 != HASH12;
}

void solve() {
    srand('P' + 'o' + 'D' + 'u' + 'R' + 'e' + 'M');
    cin >> s >> t;
    int a = count(s.begin(), s.end(), '0');
    int b = count(s.begin(), s.end(), '1');
    h1 = Hash(t), h2 = Hash(t);

    ll n = t.size();
    int ans = 0;
    for (ll x = 1; x <= n; ++x) {
        ll y = (n - a * x) / b;
        if (y >= 1 && y <= n && a * x + b * y == n) {
            ans += check(x, y);
        }
    }
    cout << ans << "\n";
}