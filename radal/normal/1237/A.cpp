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
const long long int N=3e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
vector<int> adj[N];
int a[N],b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    //cin >> T;
    T = 1;
    while (T--){
        int n;
        cin >> n;
        bool f = 0;
        rep(i,0,n){
            cin >> a[i];
            if (a[i]%2){
                if (f) {
                    b[i] = a[i]/2;
                    if (a[i] < 0) b[i]--;
                    f = 0;
                }
                else{
                    if (a[i] > 0) b[i] = a[i]/2+1;
                    else b[i] = a[i]/2;
                    f = 1;
                }
            }
            else b[i] = a[i]/2;
        }
        rep(i,0,n) cout << b[i] << endl;
    }
    return 0;
}