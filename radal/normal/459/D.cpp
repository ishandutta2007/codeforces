#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e6+10,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
int fen[N],a[N],l[N],r[N],n;
map<int,vector<int>> ind;
void upd(int l){
    for (; l <= n; l |= (l+1))
        fen[l]++;
}
int que(int r){
    int ans = 0;
    for (; r >= 0; r = (r&(r+1))-1)
        ans += fen[r];
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        ind[a[i]].pb(i);
        l[i] = ind[a[i]].size();
    }
    ll ans = 0;
    rep(i,0,n){
        r[i] = ind[a[i]].size()-(lower_bound(all(ind[a[i]]),i)-ind[a[i]].begin());
        ans += i-que(r[i]);
        upd(l[i]);
    }
    cout << ans;
    return 0;
}