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
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
map<int,ll> mp;
int n;
int a[N];
int spar[23][N];
inline int rgcd(int l,int r){
    int lg = __lg(r-l+1);
    int p = 1 << lg;
    return gcd(spar[lg][r],spar[lg][l+p-1]);
}
inline int binary(int l,int ind){
    int val = rgcd(ind,l);
    int r = n;
    if (rgcd(l,r-1) == val){
        mp[val] += r-l;
        return r-1;
    }
    int m;
    int L = l;
    while (r-l > 1){
        m = (l+r)/2;
        if (rgcd(ind,m) == val) l = m;
        else r = m;
    }
    mp[val]+=l-L+1;
    return l;
}
int main(){
    ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        spar[0][i] = a[i];
    }
    cin >> q;
    rep(j,1,19){
        rep(i,0,n){
            int p = 1 << (j-1);
            spar[j][i] = spar[j-1][i];
            if (i-p >= 0) spar[j][i] = __gcd(spar[j][i],spar[j-1][i-p]);
        }
    }
    rep(i,0,n){
        int l = i-1;
        while (l != n-1) l = binary(l+1,i);
    }
    rep(i,0,q){
        int x;
        cin >> x;
        cout << mp[x] << endl;
    }
    return 0;
}