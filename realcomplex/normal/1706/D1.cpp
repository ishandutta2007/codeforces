#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 1;
vector<pii> d[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < N; i ++ ){
        d[i].clear();
    }
    int x;
    int low = N;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        if(d[x].empty()) {
            d[x].push_back(mp(x, 1));
        }
        low = min(low, x);
    }
    int res = N;
    int kk;
    for(int i = N - 1; i >= 0; i -- ){
        if(!d[i].empty()){
            res = min(res, i - low);
            if(i == 0) break;
            for(auto y : d[i]){
                kk = (y.fi / i) + 1;
                if(kk <= k){
                    d[y.fi / kk].push_back(mp(y.fi, kk));
                    low = min(low, y.fi / kk);
                }
                else{
                    low = -(int)1e9;
                }
            }
            d[i].clear();
        }
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