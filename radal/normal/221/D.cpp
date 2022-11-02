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
const long long int N=1e5+20,mod = 1e9+7,inf=1e9,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int a[N],cnt[N];
int pre[N][500];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,n;
    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i];
        if (a[i] > 1e5) continue;
        cnt[a[i]]++;
    }
    vector<int> ve;
    rep(i,1,1e5+1){
        if (i <= cnt[i]){
            if (i == a[0]) pre[0][ve.size()]++;
            ve.pb(i);

        }
    }
    int sz = ve.size();
    rep(i,1,n){
        rep(j,0,sz){
            if (ve[j] == a[i]) pre[i][j] = pre[i-1][j]+1;
            else pre[i][j] = pre[i-1][j];
        }
    }
    rep(i,0,m){
        int l,r,ans = 0;
        cin >> l >> r;
        rep(j,0,sz){
            /*if (!i && n == 1e5 && a[0] == 1){
                if (pre[l-2][j]+ve[j] == pre[r-1][j]) cout << ve[j] << ' ' << pre[r-1][j] << ' ' << pre[l-2][j] << endl;
            }*/
            if(l == 1){
                ans += (ve[j] == pre[r-1][j]);
                continue;
            }
            if (ve[j]+pre[l-2][j] == pre[r-1][j]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}