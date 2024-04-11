#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    auto l = s.find('1');
    if(l == string::npos) cout << -1, exit(0);
    s = s.substr(l);
    ll mask = 0;
    For(i, 1, s.size()) mask |= ll(s[i] - 48) << i - 1;
    if(!mask) cout << l + 1 << ' ' << l + 2, exit(0);
    __gnu_pbds::gp_hash_table<ll, ll> p;
    int step = 1 << (s.size() >> 1);
    ll ls[34], rs = 1;
    rep(i, 0, 33) ls[i] = 1LL << i;
    For(i, 0, step) {
        p[ls[0]] = i;
        rep(j, 0, 33) ls[j] = ls[j] >> 1 ^ (ls[j] & 1 ? mask : 0);
    }
    for(ll i = step;; i += step) {
        ll t = 0;
        rep(j, 0, 33) if(rs >> j & 1) t ^= ls[j];
        if(p.find(rs = t) != p.end()) {
            ll ans = i - p[t];
            cout << l + 1 << ' ' << l + 1 + ans, exit(0);
        }
    }
}