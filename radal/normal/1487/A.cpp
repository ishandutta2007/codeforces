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
ll a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        ll mi = inf;
        rep(i,0,n){
            cin >> a[i];
            mi = min (mi,a[i]);
        }
        int cnt = 0;
        rep(i,0,n){
            if (a[i] > mi) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}