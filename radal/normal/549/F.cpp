#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 4e5+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int p){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    } 
    return z; 
}
int n,k;
int a[N],cnt[N*3];
ll ans;
void f(int l,int r){
    if (r-l == 1){
        return;
    }
    int m = (l+r) >> 1;
    f(l,m);
    f(m,r);
    int po = m-1,mx = -1,mx2 = -1;
    ll s = 0,s2 = 0;
    rep(i,m,r){
        s += a[i];
        mx2 = max(mx2,a[i]);
        while (po >= l && max(mx,a[po]) <= mx2){
            mx = max(mx,a[po]);
            s2 += a[po];
            cnt[s2%k]++;
            po--;
        }
        if ((s-mx2)%k) ans += cnt[k-(s-mx2)%k];
        else ans += cnt[0];
    }
    s2 = 0;
    repr(i,m-1,l){
        s2 += a[i];
        cnt[s2%k] = 0;
    }
    s = 0;
    s2 = 0;
    mx = -1;
    mx2 = -1;
    po = m;
    repr(i,m-1,l){
        s += a[i];
        mx2 = max(mx2,a[i]);
        while (po < r && max(mx,a[po]) < mx2){
            mx = max(mx,a[po]);
            s2 += a[po];
            cnt[s2%k]++;
            po++;
        }
        if ((s-mx2)%k) ans += cnt[k-(s-mx2)%k];
        else ans += cnt[0];
    }
    s2 = 0;
    rep(i,m,r){
        s2 += a[i];
        cnt[s2%k] = 0;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    rep(i,0,n){
        cin >> a[i];
    }
    f(0,n);
    cout << ans;
    return 0;
}