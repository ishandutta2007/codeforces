#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    ll n, m;
    int k;
    cin >> n >> m >> k;
    vector<int> a(k);
    vector<int> p(k);
    for(int i = 0 ; i < k ; i ++ ) {
        cin >> a[i];
        p[k - a[i]] = i;
    }
    int mx = 0;
    ll res;
    int need;
    for(int i = 0 ; i < k ; i ++) {
        mx = max(mx, p[i]);
        if(mx - i > n * m - 4){
            cout << "TIDAK\n";
            return;
        }
    }
    cout << "YA\n";
}


int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}