#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t =0 ; t < tc; t ++ ){
        int n;
        cin >> n;
        int a,  b;
        int la = (int)1e9 + 1;
        int lb = (int)1e9 + 1;
        vector<pii> cc(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> cc[i].fi;
            la = min(la, cc[i].fi);
        }
        for(int i = 0 ; i < n; i ++ ){
            cin >> cc[i].se;
            lb = min(lb, cc[i].se);
        }
        ll ans = 0;
        ll l1, l2;
        for(auto x : cc){
            l1 = x.fi - la;
            l2 = x.se - lb;
            ans += max(l1,l2);
        }
        cout << ans << "\n";
    }
    return 0;
}