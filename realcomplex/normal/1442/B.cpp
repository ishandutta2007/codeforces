#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = 998244353;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k), pos(n);
    vector<bool> weak(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        a[i] -- ;
        pos[a[i]] = i;
    }
    for(int i = 0 ; i < k ; i ++ ){
        cin >> b[i];
        b[i] -- ;
        b[i]=pos[b[i]];
        weak[b[i]]=true;
    }
    set<int> act;
    for(int i = 0 ; i < n; i ++ ){
        act.insert(i);
    }
    int sol = 1;
    int var;
    int b0, b1;
    for(int i = 0 ; i < k ; i ++ ){
        auto nx = act.upper_bound(b[i]);
        b0 = b1 = 0;
        if(nx != act.end() && !weak[*nx]){
            b0 = 1;
        }
        auto pv = act.lower_bound(b[i]);
        if(pv != act.begin()){
            pv -- ;
            if(!weak[*pv]){
                b1 = 1;
            }
        }
        if(b0 == 0 && b1 == 0){
            sol = 0;
            break;
        }
        if(b0){
            act.erase(nx);
        }
        else{
            act.erase(pv);
        }
        sol = (sol * 1ll * (b0 + b1)) % MOD;
        weak[b[i]]=false;
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