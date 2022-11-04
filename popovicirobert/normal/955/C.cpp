#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const ll INF = 1e18;

vector <ll> vals;

inline int check(ll val) {
    int res = 0;
    for(int step = 1 << 29; step; step >>= 1) {
        if(1LL * (res + step) * (res + step) <= val)
            res += step;
    }
    return res;
}

inline ll solve(ll val) {
    if(val == 0)
        return 0;
    return upper_bound(vals.begin(), vals.end(), val) - vals.begin() + sqrt(val);
}

vector <ll> all;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q;
    ios::sync_with_stdio(false);
    for(int i = 2; i <= 1e6; i++) {
        int val = sqrt(i);
        if(val * val == i)
            continue;
        ll a = 1LL * i * i;
        int cnt = 0;
        while(a <= INF / i) {
            a *= i;
            cnt++;
            if(cnt & 1)
                vals.push_back(a);
        }
    }
    int sz = vals.size();
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    cin >> q;
    while(q > 0) {
        q--;
        ll l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}