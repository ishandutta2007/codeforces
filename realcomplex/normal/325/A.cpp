#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll mx = 0,my = 0;
    ll mix = 1e9,miy = 1e9;
    ll cx,cy,cx1,cy1;
    ll l = 0;
    for(int j = 0;j<n;j++){
        cin >> cx >> cy >> cx1 >> cy1;
        l += ((cx1-cx)) * ((cy1-cy));
        mx = max(mx,cx1);
        my = max(my,cy1);
        mix = min(mix,cx);
        miy = min(miy,cy);
    }
    ll lef = abs(mx-mix),rig = abs(my-miy);
    cout << ((lef==rig && lef*rig == l) ? "YES" : "NO");
    return 0;
}