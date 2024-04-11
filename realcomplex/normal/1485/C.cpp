#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll get(ll x, ll ri){
    if(ri == 0) return 0ll;
    int lim = sqrt(x);
    ll ret = 0;
    for(int i = 1; i <= ri ;i ++ ){
        if(x / i > lim){
            ret += x / i;
        }
        else{
            break;
        }
    }
    ll lf, rf;
    for(ll can = 1; can <= lim ; can ++ ){
        lf = x/(can+1) + 1;
        rf = x/can;
        rf = min(ri, rf);
        if(lf <= rf){
            ret += (rf - lf + 1) * 1ll * can;
        }
    }
    ll should = 0;
    for(ll i = 1; i <= ri; i ++ ){
        should += x / i;
    }
    return ret;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        ll x, y;
        cin >> x >> y;
        ll sol = 0;
        ll dv;
        ll li, ri;
        for(ll b = 1; b <= y; b ++ ){
            dv = (x / (b + 1));
            if(dv < b - 1 && b > 1){
                li = b + 1;
                ri = y + 1;
                sol += get(x, ri) - get(x, li - 1);
                break;
            }
            else{
                sol += b - 1;
            }
            //sol += min(b - 1, (x/(b + 1)));
        }
        cout << sol << "\n";
    }
    return 0;
}