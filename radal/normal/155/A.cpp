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
typedef pair<ll,ll> pll;
const long long int N=(1<<23)+20,mod = 1e9+7,inf=2e9,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int main(){
    int n;
    cin >> n;
    int mi,mx,t=0;
    cin >> mi;
    mx = mi;
    rep(i,0,n-1){
        int x;
        cin >> x;
        if (x < mi){
            mi=x;
            t++;
        }
        if (x > mx){
            mx = x;
            t++;
        }
    }
    cout <<t;
    return 0;
}