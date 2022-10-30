#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e3+30;
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll a,b,x,y,n;
        cin >> n >> x >> y;
        if (n >= y-x+1){
            while (x>0 && x+(n-1) >= y) x--;
            x++;

            while (n--){
                cout << x << " ";
                x++;
            }
            cout << endl;
            continue;
        }
        ll ans=y-x;
        rep(i,1,y-x-1){
            if ((y-x)%i == 0 && x+(n-1)*i >= y){
                ans = i;
                break;
            }
        }
        while (x > 0 && x+(n-1)*ans >= y){
            x-=ans;
        }
        debug(ans);
        x+=ans;
        while(n--){
            cout << x << " ";
            x+=ans;
        }
        cout << endl;



    }
    return 0;
}