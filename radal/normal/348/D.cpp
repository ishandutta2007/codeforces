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
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 3e3+30,inf = 1e10,mod=1e9+7;
char t[N][N];
ll a[N][N],b[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        rep(j,0,m){
            cin >> t[i][j];
            if (t[0][j] == '#') a[0][j] = 0;
            else{
                if (j) a[0][j] = a[0][j-1];
                else a[0][j] = 1;
            }
            if (t[1][j] == '#') b[1][j] = 0;
            else{
                if (j) b[1][j] = b[1][j-1];
                else b[1][j] = 1;
            }
        }
        if (t[i][0] == '#') b[i][0] = 0;
        else{
            if (!i) b[i][0] = 1;
            else b[i][0] = b[i-1][0];
        }
        if (t[i][1] == '#') a[i][1] = 0;
        else{
            if (i) a[i][1] = a[i-1][1];
            else a[i][1] = 1;
        }
    }
    rep(i,1,n){
        rep(j,2,m){
            if (t[i][j] == '.') a[i][j] = (a[i-1][j]+a[i][j-1])%mod;
            else a[i][j] = 0;
        }
    }
    rep(i,2,n){
        rep(j,1,m){
            if (t[i][j] == '.') {
                b[i][j] = (b[i-1][j] + b[i][j-1])%mod;
            }
            else b[i][j] = 0;
        }
    }
    cout << ((b[n-1][m-2]*a[n-2][m-1])%mod - (b[n-2][m-1]*a[n-1][m-2])%mod+mod*mod)%mod;
}