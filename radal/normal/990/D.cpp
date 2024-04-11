#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=1e12,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
bool adj[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    if  (n == 1){
        cout << "YES" << endl;
        cout << 0;
        return 0;
    }
    if (min(a,b) != 1 || (n <= 3  && max(a,b) == 1)){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    if (max(a,b) > 1){
        if (a > 1){
            rep(i,1,n-a+1){
                adj[i][0] = 1;
                adj[0][i] = 1;
            }
        }
        else{
            memset(adj,1,sizeof adj);
            rep(i,1,n-b+1){
                adj[i][0] = 0;
                adj[0][i] = 0;
            }
            rep(i,0,n) adj[i][i] = 0;
        }
    }
    else{
        rep(i,0,n-1){
            adj[i][i+1] = 1;
            adj[i+1][i] = 1;
        }
    }
    rep(i,0,n){
        rep(j,0,n) cout << adj[i][j];
        cout << endl;
    }
    return 0;
}