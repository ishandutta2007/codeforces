#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 3e18, MOD = 998244353;

int binpow(int a, int n){
    if (n == 0) return 1;
    return binpow(a, n - 1) * a;
}

int is_2_binpow(int n){
    int l = 0, r = sqrt(N);
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (binpow(mid, 2) <= n){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if (binpow(l, 2) == n) return l;
    return -1;
}

int is_3_binpow(int n){
    int l = 0, r = 1500000;
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (binpow(mid, 3) <= n){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if (binpow(l, 3) == n) return l;
    return -1;
}

int is_4_binpow(int n){
    int l = 0, r = sqrt(sqrt(N));
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (binpow(mid, 4) <= n){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if (binpow(l, 4) == n) return l;
    return -1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b;
    vector<int> need;
    map<int,int> cnt;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (is_4_binpow(a[i]) != -1){
            need.pb(is_4_binpow(a[i]));
            cnt[is_4_binpow(a[i])] = max(cnt[is_4_binpow(a[i])], 1ll);
            cnt[is_4_binpow(a[i])] += 4;
        }
        else if (is_3_binpow(a[i]) != -1){
            need.pb(is_3_binpow(a[i]));
            cnt[is_3_binpow(a[i])] = max(cnt[is_3_binpow(a[i])], 1ll);
            cnt[is_3_binpow(a[i])] += 3;
        }
        else if (is_2_binpow(a[i]) != -1){
            need.pb(is_2_binpow(a[i]));
            cnt[is_2_binpow(a[i])] = max(cnt[is_2_binpow(a[i])], 1ll);
            cnt[is_2_binpow(a[i])] += 2;
        }
        else{
            b.pb(a[i]);
        }
    }
    for (int i = 0; i < b.size(); i++){
        for (int j = 0; j < b.size(); j++){
            if (__gcd(b[i], b[j]) != 1 && __gcd(b[i], b[j]) != b[i]){
                need.pb(__gcd(b[i], b[j]));
            }
        }
    }
    for (auto to : need){
        for (int i = 0; i < b.size(); i++){
            if (b[i] % to == 0){
                b[i] /= to;
                cnt[to] = max(cnt[to], 1ll);
                cnt[to]++;
                if (b[i] != 1){
                    cnt[b[i]] = max(cnt[b[i]], 1ll);
                    cnt[b[i]]++;
                    b[i] = 1;
                }
            }
        }
    }
    int ans = 1;
    for (auto to : cnt){
        ans = (ans * to.second) % MOD;
    }
    map<int,int> mp;
    for (auto to : b){
        if (to != 1){
            mp[to]++;
        }
    }
    for (auto to : mp){
        ans = (ans * (to.second + 1) % MOD) * (to.second + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}