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
    int qq;
    cin >> qq;
    for(int tt = 1;tt <= qq; tt ++ ){
        int n;
        cin >> n;
        ll xl = -(ll)1e5;
        ll xr = (ll)1e5;
        ll yl = -(ll)1e5;
        ll yr = (ll)1e5;
        ll cx, cy;
        int f0, f1, f2, f3;
        for(int i = 0 ;i < n; i ++ ){
            cin >> cx >> cy >> f0 >> f1 >> f2 >> f3;
            if(f0 == 0) xl = max(xl, cx);
            if(f1 == 0) yr = min(yr, cy);
            if(f2 == 0) xr = min(xr, cx);
            if(f3 == 0) yl = max(yl, cy);
        }
        if(xl <= xr && yl <= yr)
            cout << "1 "<< xl << " " << yl << "\n";
        else
            cout << "0\n";
    }
    return 0;
}