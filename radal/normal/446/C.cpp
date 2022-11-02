#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
const long long int N=3e5+20,mod = 1e9+9,inf=1e9,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
int a[N];
int b[600],c[600],d[600];
int f[N],pre[N]; 
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q,s;
    cin >> n >> q;
    s = sqrt(n)+1;
    f[1] = 1;
    f[2] = 1;
    pre[1] = 1;
    pre[2] = 2;
    rep(i,3,n+1){
        f[i] = mkay(f[i-1],f[i-2]);
        pre[i] = mkay(pre[i-1],f[i]);
    }
    rep(i,0,n){
        cin >> a[i];
        b[i/s] = mkay(b[i/s],a[i]);
    }
    rep(i,0,q){
        int t,l,r;
        cin >> t >> l >> r;
        l--;
        if (t == 1){
            int p = l;
            if (l%s != 0){
                while (p < r && p/s == l/s){
                    a[p] = mkay(a[p],f[p-l+1]);
                    b[p/s] = mkay(b[p/s],f[p-l+1]);
                    p++;
                }
            }
            int y = p/s;
            while (p+s < r){
                c[y] = mkay(c[p/s],f[p-l+1]);
                d[y] = mkay(f[p-l+2],d[y]);
                b[y] = mkay((pre[p+s-l]-pre[p-l]+mod)%mod,b[y]);
                p+=s;
                y++;
            }
            rep(j,p,r){
                a[j] = mkay(a[j],f[j-l+1]);
                b[j/s] = mkay(b[j/s],f[j-l+1]);
            }
        }
        else{
            int ans = 0;
            if (l%s){
                int k = l/s,q = min(n,k*s+s);
                int u = c[k],v = d[k],w;
                a[k*s] = mkay(a[k*s],u);
                rep(j,k*s+1,q){
                    a[j] = mkay(a[j],v);
                    w = mkay(u,v);
                    u = v;
                    v = w;
                }
                c[k] = 0;
                d[k] = 0;
                rep(j,l,min(r,q)) ans = mkay(ans,a[j]);
                l = q;
            }
            while (l+s < r){
                ans = mkay(ans,b[l/s]);
                l+=s;
            }
            int u = c[l/s],v = d[l/s],w;
            rep(j,l,r){
                if(j == l){
                    ans = mkay(ans, mkay(a[j],u));
                    continue;
                }
                ans = mkay(ans,mkay(a[j],v));
                w = mkay(u,v);
                u = v;
                v = w;
            }
            cout << ans << endl;
        }
    }
    return 0;
}