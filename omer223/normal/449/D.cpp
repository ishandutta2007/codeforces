#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int mod = 1e9 + 7;

void imult(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
    lhs = (lhs + rhs) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll & x) {
    return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) + (rhs % mod)) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
    return mult(lhs, inv(rhs));
}
const int LOG = 20, sz = (1 << LOG);
int inc[sz][LOG];
int cnt[sz], msk[LOG];
int n;

int main() {
    fast;
    int zeros = 0;
    cin >> n;
    foru(i, 0, n) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
        if (tmp == 0) {
            zeros++;
            continue;
        }
        foru(j, 0, LOG)inc[tmp][j]++;
    }
    foru(i,0,LOG)msk[i]=(1<<i);
    ford(i, sz - 1, 1) {
        foru(j, 0, LOG) {
            foru(k, j, LOG - 1) {
                if (msk[k] & i)continue;
                inc[i][j] += inc[i | msk[k]][k + 1];
                inc[i][j] %= mod;
            }
            if (cnt[i | msk[LOG-1]] && !(i&(msk[LOG-1]))) {
                inc[i][j] += cnt[i | msk[LOG-1]];
                inc[i][j] %= mod;
            }
        }
    }
    ll tot = 0;
    foru(i, 1, sz) {
        if (__builtin_popcount(i) & 1)
            iadd(tot, subt(bpw(2, inc[i][0]), 1));
        else
            isubt(tot, subt(bpw(2, inc[i][0]), 1));
    }
    ll ret = subt(bpw(2, (n-zeros)), tot + 1);
    iadd(ret, subt(bpw(2, n), bpw(2, (n - zeros))));
    cout << ret;
    return 0;
}