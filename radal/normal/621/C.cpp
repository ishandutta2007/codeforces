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
typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e6+10,mod = 998244353,inf=4e18,maxm = 1000;
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
ll l[N],r[N],d[N];
int main(){
    ios :: sync_with_stdio(0);
    int n,p;
    cin >> n >> p;
    rep(i,0,n){
        cin >> l[i] >> r[i];
        ll k = r[i]-l[i]+1;
        if (l[i]%p == 0) k += p-1;
        else k += (l[i]%p-1);
        d[i] = k/p;
    }
    ld ans = 0;
    rep(i,0,n){
        int j;
        if (i < n-1) j = i+1;
        else j = 0;
        ld k = 1.0*(d[i]*(r[j]-l[j]+1)+d[j]*(r[i]-l[i]+1)-d[i]*d[j])/(r[i]-l[i]+1)/(r[j]-l[j]+1);
        ans += k;
    }
    cout << fixed << setprecision(7) << ans*2000;
    return 0;
}