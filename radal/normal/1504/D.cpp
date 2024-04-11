#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e2+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int g[N][N];
int main(){
    ios :: sync_with_stdio(0);
    int b=-1,w=-1,n;
    bool f = 0;
    cin >> n;
    rep(k,0,n*n){
        int a;
        cin >> a;
        f = 0;
        if (b == -1 || a != b){
            if (b == -1){
                if (a != 1) b = 1;
                else b = 2;
            }
            f = 0;
            rep(i,0,n){
                rep(j,0,n){
                    if ((i+j)%2) continue;
                    if (g[i][j]) continue;
                    g[i][j] = b;
                    cout << b << ' ' << i+1 << ' ' << j+1 << endl;
                    f = 1;
                    break;
                }
                if (f) break;
            }
            if (f) continue;
        }
        if (min(b,a) > 1) w = 1;
        else{
            if (max(b,a) == 2) w = 3;
              else w = 2;
        }
        f = 0;
        rep(i,0,n){
            rep(j,0,n){
                if ((i+j)%2 && !g[i][j]){
                    cout << w << ' ' << i+1 << ' ' << j+1 << endl;
                    g[i][j] = w;
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
        if (f) continue;
        rep(i,0,n){
            rep(j,0,n){
                if((i+j)&1) continue;
                if (g[i][j]) continue;
                int q;
                if (min(w,a) != 1) q = 1;
                else{
                    if (max(w,a) == 2) q = 3;
                    else q = 2;
                }
                g[i][j] = q;
                cout << q << ' ' << i+1 << ' ' << j+1 << endl;
                f = 1;
                break;
            }
            if (f) break;
        }
    }
    return 0;
}