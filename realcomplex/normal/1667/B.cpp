#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
ll A[N];
ll pf[N];
ll dp[N];

set<pii> opt;

void add(ll pre, ll val){
    if(opt.count(mp(pre, val))) return;
    auto it = opt.lower_bound(mp(pre, (ll)1e18));
    if(it != opt.begin()){
        it -- ;
        if(it->se >= val){
            return;
        }
    }
    opt.insert(mp(pre, val));
    it = opt.lower_bound(mp(pre, val));
    it ++ ;
    while(it != opt.end()){
        if(it->se <= val){
            it = opt.erase(it);
        }
        else{
            break;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    opt.clear();
    opt.insert(mp(0ll, 0ll));
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        pf[i] = A[i] + pf[i - 1];
        if(A[i] > 0) dp[i] = dp[i - 1] + 1;
        else if(A[i] == 0) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] - 1;
        auto it = opt.lower_bound(mp(pf[i], -(ll)1e18));
        if(it != opt.begin()){
            it -- ;
            dp[i] = max(dp[i], it->se + i);
        }
        add(pf[i], dp[i]-i);
    }
    cout << dp[n] << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}