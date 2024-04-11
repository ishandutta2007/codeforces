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
    for(int t = 1; t <= tc; t ++ ){
        ll p, q;
        cin >> p >> q;
        vector<ll> pr;
        ll rr = q;
        for(ll x = 2; x * x <= q; x ++ ){
            if(q % x == 0)
                pr.push_back(x);
            while(q % x == 0){
                q /= x;
            }
        }
        if(q != 1) pr.push_back(q);
        int c0, c1;
        ll mn = p;
        for(auto d : pr){
            ll nw = p;
            c0 = 0, c1 = 0;
            ll div = 1ll;
            while(nw % d == 0){
                c0 ++ ;
                nw /= d;
            }
            while(rr % d == 0){
                c1 ++ ;
                rr /= d;
            }
            while(c0 >= c1){
                div *= d;
                c0 -- ;
            }
            mn = min(mn,div);
        }
        cout << p/mn << "\n";
    }
    return 0;
}