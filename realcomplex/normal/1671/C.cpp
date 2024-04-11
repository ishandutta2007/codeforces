#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
ll A[N];
ll pf[N];

ll can[N];
void solve(){
    int n;
    ll x;
    cin >> n >> x;
    for(int i = 1; i <= n; i ++) {
        cin >> A[i];
    }
    sort(A + 1, A + n + 1);
    ll res = 0;
    for(int i = 1; i <= n; i ++ ){
        can[i] = 0;
        pf[i] = A[i] + pf[i - 1];
        can[i] = max(0ll, (x - pf[i] + i) / i);
        //cout << can[i] << " ";
    }
    //cout << "\n";
    ll las = 0;
    for(int i = n; i >= 1; i -- ){
        res += (can[i] - las) * 1ll * i;
        las = can[i];
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