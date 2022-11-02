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
const long long int N=1e6+10,mod = 17,inf=4e18,maxm = 1000;
const long double eps = 0.0001;
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    long long ans = poww(a,k/2);
    ans *= ans;
    ans %= mod;
    if (k%2){
        ans*=a;
        ans %= mod;
    }
    return ans;
}
int d[N];
int main(){
    ios :: sync_with_stdio(0);
    ll n,k;
    cin >> n >> k;
    ll p = 1;
    ll g = k;
    rep(i,0,n){
        cin >> d[i];
        g = gcd(g,d[i]);
    }
    k /= g;
    rep(i,0,n){
        int c = d[i]/g;
        if (gcd(k/gcd(k,c),c) != 1) continue;
        p*=c;
        p%=k;
    }
    cout << ((!p) ? "YES" : "NO");
    return 0;
}