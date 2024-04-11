#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
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
const long long int N=3e6+10,mod = 1e9+7,inf=1e18;
int ans[N],n;
int neg[N];
vector<int> tajz[N];
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
inline int mkay(int d){
    return ((d < mod) ? d : d-mod);
}
int f(int k){
    if (k == 1) return 1;
    if (ans[k] != -1) return ans[k];
    ans[k] = poww(k,n);
    neg[k] = neg[k-1];
    ll c = 0;
    for (int u : tajz[k]){
        neg[k] += mkay(c+ans[u]-ans[u-1]+mod);
        neg[k] = mkay(neg[k]);
    }
    ans[k] += mod;
    ans[k] -= neg[k];
    ans[k] %= mod;
    return ans[k];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(ans,-1,sizeof ans);
    int k;
    ans[1] = 1;
    ans[0] = 0;
    cin >> n >> k;
    rep(i,1,k+1) for (int j = 2; j*i <= k; j++) tajz[j*i].pb(i); 
    int out = 0;
    ans[1] = 1;
    rep(i,2,k+1){
        f(i);
        out += ans[i]^i;
        out %= mod;
    }
    cout << out;
}