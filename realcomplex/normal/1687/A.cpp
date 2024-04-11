#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
ll pre[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i <= n + 1; i ++ ) pre[i] = 0ll;
    for(int i = 1; i <= n; i ++ ){
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    pre[n + 1] = pre[n];
    k -- ;
    ll res = 0;
    if(k < n){
        for(int i = 1; i + k <= n; i ++ ){
            res = max(res, pre[i + k] - pre[i - 1] + k * 1ll * (k + 1) / 2ll);
        }
    }
    else{
        k ++ ;
        res += pre[n];
        res += n * 1ll * k;
        res -= n * 1ll * (n + 1) / 2;
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