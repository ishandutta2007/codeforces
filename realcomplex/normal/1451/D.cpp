#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int d, k;
    cin >> d >> k;
    ll xx = 0, yy = k;
    int xr = 1;
    while(xx * xx + yy * yy <= d * 1ll * d){
        if(xr){
            xx += k;
        }
        else{
            yy += k;
        }
        xr ^= 1;
    }
    if(xr){
        cout << "Utkarsh\n";
    }
    else{
        cout << "Ashish\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}