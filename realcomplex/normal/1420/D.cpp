#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)6e5 + 100;
const int MOD = 998244353;
int in[N];
int st[N];

int powr(int a, int k){
    if(k == 0) return 1;
    int p = powr(a,k/2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * a) % MOD;
    return p;
}

int fac[N];

ll C(int n, int k){
    if(n < k) return 0ll;
    ll res = fac[n];
    res = (res * 1ll * powr(fac[k], MOD - 2)) % MOD;
    res = (res * 1ll * powr(fac[n - k], MOD - 2)) % MOD;
    return res;
}

int main(){
    fastIO;
    fac[0]=1;
    for(int i = 1 ; i < N; i ++ ){
        fac[i]=(fac[i-1]*1ll*i)%MOD;
    }
    int n, k;
    cin >> n >> k;
    int l, r;
    vector<pii> segs;
    vector<int> cc;
    for(int i = 1; i <= n; i ++ ){
        cin >> l >> r;
        segs.push_back(mp(l, r));
        cc.push_back(l);
        cc.push_back(r);
    }
    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
    int m = cc.size();
    for(auto &x : segs){
        x.fi = lower_bound(cc.begin(), cc.end(), x.fi) - cc.begin();
        x.se = lower_bound(cc.begin(), cc.end(), x.se) - cc.begin();
        in[x.fi] ++ ;
        st[x.fi] ++ ;
        in[x.se + 1] -- ;
    }
    int total = 0;
    ll answ = 0;
    ll cur = 0;
    ll s1, s2;
    for(int i = 0 ; i < m ; i ++ ){
        total += in[i];
        s1 = C(total, k);
        s2 = C(total - st[i], k);
        cur = (s1 - s2 + MOD) % MOD;
        answ = (answ + cur) % MOD;
    }
    cout << answ << "\n";
    return 0;
}