#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int a[N],b[N];
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        int n,mx=-1;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
            mx = max(mx,a[i]);
        }
        rep(i,1,n) b[i] = a[i]-a[i-1];
        int x = -2e9,y = -2e9;
        bool f = 1;
        rep(i,1,n){
            if (x == -2e9) x = b[i];
            else{
                if (b[i] != x && y == -2e9) y = b[i];
                else{
                    if (b[i] != x && b[i] != y){
                        f = 0;
                        break;
                    }
                }
            }
        }
        if (!f || (x == 0 && y != -2e9) || (x != 0 && y == 0) || (y != -2e9 && mx >= abs(x)+abs(y))) cout << -1 << endl;
        else{
            if (y == -2e9) cout << 0 << endl;
            else{
                if (y < 0) swap(x,y);
                cout << -x+y << ' ' << y << endl;
            }
        }
    }
    return 0;
}