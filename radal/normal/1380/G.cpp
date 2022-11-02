#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr ll N = 3e5+10,mod = 998244353,inf = 1e9+10;
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
        k /= 2;
    } 
    return z; 
}
int a[N],pr[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
    pr[0] = a[0];
    rep(i,1,n) pr[i] = mkay(a[i],pr[i-1]);
    int inv = poww(n,mod-2);
    rep(k,1,n+1){
        int sum = 0;
        for (int j = k; j < n; j += k){
            if (j+k-1 < n)
                sum = mkay(sum,1ll*(j/k)*mkay(pr[j+k-1],-pr[j-1])%mod);
            else
                sum = mkay(sum,1ll*(j/k)*mkay(pr[n-1],-pr[j-1])%mod);
        }
        cout << 1ll*sum*inv%mod << ' ';
    }
    return 0;
}