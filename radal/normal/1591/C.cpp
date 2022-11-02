#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod)return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        rep(i,0,n)
            cin >> a[i];
        sort(a,a+n);
        vector<int> v1,v2;
        rep(i,0,n){
            if (a[i] >= 0) break;
            v1.pb(-a[i]);
        }
        rep(i,0,n){
            if (a[i] > 0) v2.pb(a[i]);
        }
        ll sum = 0;
        int sz1 = v1.size(),sz2 = v2.size();
        for (int i = 0; i < sz1; i+= k){
            sum += (v1[i]*2);
        }
        for (int i = sz2-1; i >= 0; i -= k){
            sum += (v2[i]*2);
        }
        if (min(sz1,sz2) > 0) cout << sum - max(v1[0],v2[sz2-1]) << endl;
        else{
            if (!sz1 && !sz2){
                cout << 0 << endl;
                continue;
            }
            if (sz1 == 0) cout << sum-v2[sz2-1] << endl;
            else cout << sum - v1[0] << endl;
        }
    }
}