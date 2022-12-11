#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void solve(){
    int n, m;
    cin >> n >> m;
    vector<pii> sha(m + 1);
    for(int i = 1 ; i <= m ; i ++ ){
        cin >> sha[i].fi >> sha[i].se;
    }
    sort(sha.begin(), sha.end());
    vector<ll> pf(m + 1);
    int kk;
    int can;
    ll sol = 0ll;
    ll cur;
    for(int i = 1; i <= m ; i ++ ){
        pf[i] = pf[i - 1] + sha[i].fi;
    }
    int ele;
    for(int i = 1 ; i <= m; i ++ ){
        kk = lower_bound(sha.begin(), sha.end(), mp(sha[i].se,-1ll)) - sha.begin();
        kk--;
        kk = max(kk, m-n);
        ele = m - kk;
        if(kk < i){
            sol = max(sol, (pf[m]-pf[kk]) + (n - ele) * 1ll * sha[i].se);
        }
        else{
            if(ele == n){
                kk ++ ;
                ele -- ;
            }
            sol = max(sol, (pf[m] - pf[kk]) + sha[i].fi + (n - ele - 1) * 1ll * sha[i].se);
        }
    }
    cout << sol << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}