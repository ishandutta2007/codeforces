#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
typedef long long ll;
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 1e9;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1070100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
long long solve(vector<ll>cnt, int x, ll k) {
    ll res = 0;
    int n = cnt.size();
    ll small = 0;
    for (int i = 0; i <= x; ++i) {
        k -= cnt[i];
        //small += cnt[i] * ((1ll << i) - 1);
    }
    if (k <= 0)return 0;
    int bt = -1;
    for (int i = x + 1; i < n && k > 0; ++i) {
        int d = i - x;
        ll ml = 1 << d;
        ll cnt_need = (k) / ml;
        if (cnt_need <= cnt[i]) {
            k -= cnt_need * ml;
            cnt[x] += cnt_need * ml;
            res += (ml - 1) * cnt_need;
            cnt[i] -= cnt_need;
            if (cnt[i] == 0)continue;
            bt = i;
            break;
        }
        else {
            k -= cnt[i] * ml;
            cnt[x] += cnt[i] * ml;
            res += (ml - 1) * cnt[i];
            cnt[i] = 0;
        }
    }
    for (int i = 0; i <= x; ++i) {
       // k -= cnt[i];
        small += cnt[i] * ((1ll << i) - 1);
    }
    if (k <= 0)return res;
    if (bt == -1) {
        if (small >= k)return res + k;
        else return -1;
    }
    ll ans = 1e18;
    if (small >= k)ans = min(ans, res + k);
    while (bt > x) {
        if (small >= k)
            ans = min(ans, res + k);
        ++res;
        --bt;
        ll add = 1ll << (bt - x);
        if (k >= add) {
            res += add - 1;
            k -= add;
            small += add * ((1ll << x) - 1);
        }
    }

    return min(res, ans);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<ll>cnt(n);
    for (auto& x : cnt)cin >> x;
    while (q--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            cnt[b] = c;
        }
        else {
            ll res = solve(cnt, b, c);
            cout << res << "\n";
        }
    }
    return 0;
}