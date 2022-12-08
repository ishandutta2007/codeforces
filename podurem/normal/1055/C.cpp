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

const int dd = (int)1e5 + 7;

ll get(ll la, ll ra, ll ta, ll lb, ll rb, ll tb) {
    ll G = __gcd(ta, tb);
    ll ans = 0;
    {
        ll L = (la - lb % G + G - 1) / G * G + lb % G;
        ll R = L + rb - lb;
        ans = max(ans, min(R, ra) - max(la, L) + 1);
    }
    {
        ll R = (ra - rb % G) / G * G + rb % G;
        ll L = R - rb + lb;
        ans = max(ans, min(R, ra) - max(la, L) + 1);
    }
    return ans;
}

int solve() {
    ll la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    cout << max(get(la, ra, ta, lb, rb, tb), get(lb, rb, tb, la, ra, ta)) << "\n";
    return 0;
}