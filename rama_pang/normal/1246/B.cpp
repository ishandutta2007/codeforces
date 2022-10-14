#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;
 
lint A[100005], N, K;
unordered_map<lint, lint> mp;
vector<lint> di;
set<pair<lint, lint>> done;
 
inline lint divis(lint n, lint k) {
    lint res = 0;
    di.clear();
    if (K == 2) {
        for (lint i = 1; i * i <= k; i++) {
            if (k % i == 0) di.push_back(i), di.push_back(k / i);
            if (k == i * i) di.pop_back();
        }
        sort(di.begin(), di.end());
        for (auto k = 0; k < di.size(); k++) {
            for (auto j = k; j < di.size(); j++) {
                lint i = di[j] * di[k];
                if (n % i == 0) {
                    lint d1 = i, d2 = n / i;
                    if (mp.find(d1) != mp.end() && mp.find(d2) != mp.end() && done.find({min(d1, d2), max(d1, d2)}) == done.end()) {
                        if (d1 != d2) res += mp[d1] * mp[d2];
                        if (d1 == d2) res += (mp[d1] * (mp[d1] - 1)) / 2;
                        done.insert({min(d1, d2), max(d1, d2)});
                    }
                }
            }
        }
 
    } else {
        for (lint i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    lint d1 = i, d2 = n / i;
                    if (mp.find(d1) != mp.end() && mp.find(d2) != mp.end()) {
                        if (d1 != d2) res += mp[d1] * mp[d2];
                        if (d1 == d2) res += (mp[d1] * (mp[d1] - 1)) / 2;
                        // done.insert({min(d1, d2), max(d1, d2)});
                    }
                
            }
        }
    }
 
    return res;
}
 
lint pw(lint n, lint x) {
    if (x == 0) return 1;
    lint res = pw(n, x / 2);
    if (res >= 1e11) return 1e11;
    res *= res;
    if (res >= 1e11) return 1e11;
    if (x & 1) res *= n;
    if (res >= 1e11) return 1e11;
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    cin >> N >> K;
    lint tmp = 1;
    mp.reserve(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) mp[A[i]]++;
    
    lint cnt = 0, mx = 1, ans = 0;
    while (mx <= 1e10) {
        lint t = pw(tmp, K);
        tmp++;
        mx = t;
        ans += divis(t, tmp - 1);
    }
 
    cout << ans << "\n";
    
 
}