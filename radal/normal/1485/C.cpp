#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=4e18,maxk = 1e5+20;
const long double eps = 0.0001;
int main(){
    ll T = 1;
    cin >> T;
    while (T--){
        ll x,y;
        cin >> x >> y;
        int b = 1;
        ll ans = 0;
        while (b-1 <= x/(b+1) && b <= y){
            ans += b-1;
            b++;
        }
        int c = x/(b+1);
        while (c && b <= y){
            int low,high;
            int l,m,r;
            l = b;
            r = y;
            while (r-l > 0){
                m = (l+r+1)/2;
                if (x/(m+1) >= c) l = m;
                else r = m-1;
            }
            high = l;
            l = b; r = y;
            while (r-l > 0){
                m = (l+r)/2;
                if (x/(m+1) > c) l = m+1;
                else r = m;
            }
            low =l;
            if (x/(low+1) == c && x/(high+1) == c) ans += c*(high-low+1);
            c--;
        }
        cout << ans << endl;
    }
    return 0;
}