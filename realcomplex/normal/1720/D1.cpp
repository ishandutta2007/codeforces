#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int LOG = 19;
map<int, int> dp[LOG][2][2];
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int vv;
    int res = 1;
    int cur;
    int pi, qi;
    for(int i = 0 ; i < LOG; i ++ ){
        for(int p = 0 ; p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ ){
                dp[i][p][q].clear();
            }
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        vv = 0;
        cur = 1;
        for(int lg = LOG - 1; lg >= 0 ; lg -- ){
            pi = 0;
            qi = 0;
            if((a[i] & (1 << lg))) pi = 1;
            if((i & (1 << lg))) qi = 1;
            for(int p = 0; p < 2; p ++ ){
                for(int q = 0; q < 2; q ++ ){
                    if((p ^ qi) < (pi ^ q) && dp[lg][p][q].count(vv)){
                        cur = max(cur, dp[lg][p][q][vv] + 1);
                    }
                }
            }
            if((a[i] & (1 << lg))){
                vv ^= (1 << lg);
            }
            if((i & (1 << lg))){
                vv ^= (1 << lg);
            }
        }
        vv = 0;
        for(int lg = LOG - 1; lg >= 0 ; lg -- ){
            pi = 0;
            qi = 0;
            if((a[i] & (1 << lg))) pi = 1;
            if((i & (1 << lg))) qi = 1;
            dp[lg][pi][qi][vv] = max(dp[lg][pi][qi][vv], cur);
            if((a[i] & (1 << lg))){
                vv ^= (1 << lg);
            }
            if((i & (1 << lg))){
                vv ^= (1 << lg);
            }
        }
        res = max(res, cur);
    }
    cout << res << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}