#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;

set<pii> vals;

ll total;

void add(ll x, int y){
    auto it = vals.lower_bound(mp(x, 0));
    total = (total + y) % MOD;
    if(it == vals.end() || it->fi != x){
        vals.insert(mp(x, y));
    }
    else{
        int cur = it->se;
        vals.erase(it);
        vals.insert(mp(x, (cur + y) % MOD));
    }
}

void solve(){
    int n;
    cin >> n;
    vals.clear();
    vals.insert(mp(0, 1));
    ll cul = 0;
    total = 1;
    ll del;
    ll x;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        auto it = vals.lower_bound(mp(-cul, 0));
        del = 0;
        if(it != vals.end() && it->fi == -cul){
            del = it->se;
        }
        cul += x;
        add(x - cul, ((total - del) % MOD + MOD) % MOD);
    }
    cout << total << "\n";
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