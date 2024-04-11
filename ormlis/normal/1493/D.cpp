#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 1e9 + 7;

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}


int mp[maxN];
vector<int> primes;

void init() {
    for(int i = 2; i < maxN; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }
        for(auto &p : primes) {
            if (1ll * p * i >= maxN || p > mp[i]) break;
            mp[p * i] = p;
        }
    }
}

multiset<int> havep[maxN];
map<int, int> cntp[maxN];
int ans = 1;
int n;

void upd(int i, int p) {
    if (cntp[p][i]) {
        havep[p].erase(havep[p].find(cntp[p][i]));
    }
    cntp[p][i]++;
    havep[p].insert(cntp[p][i]);
    if (havep[p].size() == n && *havep[p].begin() == cntp[p][i]) {
        ans = mul(ans, p);
    }
}

void factorization(int i, int x) {
    while(x != 1) {
        upd(i, mp[x]);
        x /= mp[x];
    }
}

void solve() {
    init();
    int q; cin >> n >> q;
    range(i, n) {
        int x; cin >> x;
        factorization(i, x);
    }
    range(_, q) {
        int i, x; cin >> i >> x;
        factorization(i - 1, x);
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}