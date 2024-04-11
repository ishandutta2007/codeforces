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
int x,y;
map<int,int> ans;
int neg[N];
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
    if (ans.find(k) != ans.end()) return ans[k];
    ans[k] = poww(2,k-1);
    vector<int> tajz;
    int s = sqrt(k);
    rep(i,2,s+2){
        if (k%i == 0){
            if (k/i >= i) tajz.pb(i);
            if (k/i > i) tajz.pb(k/i);
        }
    }
    tajz.pb(1);
    for (int u : tajz){
        f(u);
        ans[k] = mkay(ans[k]-ans[u]+mod);
    }
    return ans[k];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ans[1] = 1;
    ans[0] = 0;
    cin >> x >> y;
    if (y%x){
        cout << 0;
        return 0;
    }
    if (y == x){
        cout << 1;
        return 0;
    }
    y/=x;

    cout << f(y);
}