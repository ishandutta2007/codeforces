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
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 3e5+10,mod = 1e9+7,inf = 1e18,fx = 1e14;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N];
map<ll,int> cnt;
ll pre[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    cnt[0]++;
    rep(i,0,n){
        cin >> a[i];
        pre[i] = a[i];
        if (i) pre[i] += pre[i-1];
        ll z = 1;
        if (k == 0){
            ans += cnt[pre[i]];
            cnt[pre[i]]++;
            continue;
        }
        if (k == 1){
            ans += cnt[pre[i]-1];
            cnt[pre[i]]++;
            continue;
        }
        if (k == -1){
            ans += cnt[pre[i]+1]+cnt[pre[i]-1];
            cnt[pre[i]]++;
            continue;
        }
        while (z <= fx && z >= -fx){
            ans += cnt[pre[i]-z];
            z *= k;
        }
        cnt[pre[i]]++;
    }
    cout << ans;
}