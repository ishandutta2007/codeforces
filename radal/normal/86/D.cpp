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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,sq = 500;
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
map<pll,ll> ans;
int a[N],cnt[N*5];
pll Q[N];
inline bool cmp(pll i,pll j){
    if (i.X/sq != j.X/sq) return (i.X < j.X);
    return (i.Y < j.Y);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,0,n){
        cin >> a[i];
    }
    vector<pll> ve;
    rep(i,0,q){
        cin >> Q[i].X >> Q[i].Y;
        Q[i].X--;
        ve.pb(Q[i]);
    }
    sort(all(ve),cmp);
    int l = ve[0].X,r = ve[0].Y;
    ll cur = 0;
    rep(i,l,r){
        cnt[a[i]]++;
        cur += (2*cnt[a[i]]-1)*a[i];
    }
    ans[ve[0]] = cur;
    rep(i,1,q){
        int L = ve[i].X,R = ve[i].Y;
        while (l > L){
            l--;
            cnt[a[l]]++;
            cur += (2*cnt[a[l]]-1)*a[l];
        }
        while (r > R){
            r--;
            cur -= (2*cnt[a[r]]-1)*a[r];
            cnt[a[r]]--;
        }
        while (r < R){
            cnt[a[r]]++;
            cur += (2*cnt[a[r]]-1)*a[r];
            r++;
        }
        while (l < L){
            cur -= (2*cnt[a[l]]-1)*a[l];
            cnt[a[l]]--;
            l++;
        }
        ans[ve[i]] = cur;
    }
    rep(i,0,q) cout << ans[Q[i]] << endl;
    return 0;
}