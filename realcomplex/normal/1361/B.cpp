#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
const int MOD = (int)1e9 + 7;
const int MOD2 = (int)1637608477;

int powr(int n, int k, int mod){
    if(k == 0) return 1;
    int p = powr(n,k/2,mod);
    p = (p * 1ll * p) % mod;
    if(k % 2 == 1)
        p = (p * 1ll * n) % mod;
    return p;
}

void solve(){
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    for(int i =0  ; i < n; i ++ ){
        cin >> k[i];
    }
    sort(k.begin(), k.end());
    int cur0 = 0, cur1 = 0;
    for(int i = k.size() - 1; i >= 0 ; i -- ){
        if(cur0 == 0 && cur1 == 0){
            cur0 += powr(p, k[i], MOD);
            cur1 += powr(p, k[i], MOD2);
        }
        else{
            cur0 -= powr(p, k[i], MOD);
            cur1 -= powr(p, k[i], MOD2);
            if(cur0 <0) cur0 += MOD;
            if(cur1 <0) cur1 += MOD2;
        }
    }
    cout << cur0 << "\n";
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