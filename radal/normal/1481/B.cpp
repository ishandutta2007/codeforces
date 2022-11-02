#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
const long long int N=5e2+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
int h[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k,mx=0,sum=0;
        cin >> n >> k;
        rep(i,0,n){
            cin >> h[i];
            mx = max(mx,h[i]);
        }
        rep(i,0,n)sum += mx-h[i];
        if (sum < k){
            cout << -1 << endl;
            continue;
        }
        int ans = -1;
        bool f =0;
        rep(j,0,k){
            if (f) break;
            rep(i,0,n-1){
                if (h[i] < h[i+1]){
                    h[i]++;
                    if (j == k-1) ans = i+1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}