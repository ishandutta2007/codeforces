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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=2e7+10,mod = 2e18,inf=3e18,maxm = 1000;
const long double eps = 0.0001;
int m[N];
int main(){
    int n,a;
    cin >> a >> n;
    rep(i,1,a+n){
        ll j = i*i;
        if (j > a+n-1) break;
        rep(k,1,a+n){
            if (k*j > a+n-1) break;
            m[k*j] = j;

        }
    }
    ll ans = 0;
    rep(i,a,a+n){
        ans += i/m[i];
    }
    cout << ans;
    return 0;
}