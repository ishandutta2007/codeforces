#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int it = 1; it <= tc; it ++ ){
        int n;
        cin >> n;
        vector<ll> c(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> c[i];
        }
        ll c0 = 0, c1 = 0;
        ll la = (ll)1e18;
        ll lb = (ll)1e18;
        int m0 = n, m1 = n;
        ll sol = (ll)1e18;
        for(int i = 0 ; i < n; i ++ ){
            if(i % 2 == 0){
                la = min(la, c[i]);
                c0 += c[i];
                m0 -- ;
            }
            else{
                lb = min(lb, c[i]);
                c1 += c[i];
                m1 -- ;
            }
            if(i > 0){
                sol = min(sol, la * 1ll * m0 + c0 + lb * 1ll * m1 + c1);
            }
        }
        cout << sol << "\n";
    }

    return 0;
}