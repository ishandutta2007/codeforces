#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    ll l, k, r, t;
    cin >> k >> l >>r >> t;
    k -= l;
    r -= l;
    l = 0;
    ll x, y;
    cin >> x >> y;
    ll p = max(0ll,r-y+1); // anything >= p dont jump foward
    set<ll> cyc; // at most x relevent values can be stored
    ll rem;
    ll delta;
    while(t>0){
        if(k >= p){
            rem = (k-p)/x;
            if(rem > 0){
                k -= rem * 1ll * x;
                t -= rem;
            }
            else{

                if(cyc.count(k)){
                    cout << "Yes\n";
                    return 0;
                }
                cyc.insert(k);

                k -= x;
                t -- ;
            }
        }
        else{
            if(x==y){
                cout << "Yes\n";
                return 0;
            }
            if(x > y){
                ll mx = k/(x-y)+1;
                if(mx <= t){
                    cout << "No\n";
                }
                else{
                    cout << "Yes\n";
                }
                return 0;
            }
            delta = (y-x);
            rem = (p-k+delta-1)/delta;
            k += rem * delta;
            t -= rem;
        }
        if(k < 0){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}