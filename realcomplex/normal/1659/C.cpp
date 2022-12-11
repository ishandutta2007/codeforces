#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
ll x[N];
ll suf[N];
void solve(){
    int n;
    ll a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++ ){
        cin >> x[i];
    }
    suf[n + 1] = 0;
    for(int i = n; i >= 1; i -- ){
        suf[i] = x[i] + suf[i + 1];
    }
    ll res = (ll)1e18;
    ll pref = 0;
    ll suff;
    for(int i = 0; i <= n; i ++ ){
        if(i) {
            pref += (a + b) * 1ll * (x[i] - x[i - 1]);
        }
        suff = b * 1ll * (suf[i + 1] - x[i] * 1ll * (n - i));
        res = min(res, pref + suff);
    }
    cout << res << "\n";

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