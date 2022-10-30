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
const long long int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
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
int a[N],ans[N],f[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        memset(f,0,sizeof f);
        int n;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
            if (f[a[i]+10000]){
                ans[i] = -1;
                f[a[i]+10000] = 0;
            }
            else{
                ans[i] = 1;
                f[a[i]+10000] = 1;
            }
        }
        vector<int> ve;
        rep(i,0,n){
            if (f[a[i]+10000]){
                f[a[i]+10000] = 0;
                ve.pb(i);
            }
        }
        if (ve.size() == 1){
            int x = a[ve[0]];
            if (ve[0]){
                ans[0] += x;
                ans[ve[0]] = -a[0];
                if (!ans[0]){
                    ans[0] += x;
                    ans[ve[0]] -= a[0];
                }
            }
            else{
                ans[1] += x;
                ans[0] = -a[1];
                if (!ans[1]){
                    ans[1] += x;
                    ans[ve[0]] -= a[1];
                }
            }
            rep(i,0,n) cout << ans[i] << ' ';
            cout << endl;
            continue;
        }
        if (ve.empty()){
            rep(i,0,n) cout << ans[i] << ' ';
            cout << endl;
            continue;
        }
        int sum = 0,sz = ve.size();
        rep(i,0,sz-1){
            sum += a[ve[i]];
            ans[ve[i]] = 1;
        }
        if(!sum){
            ans[ve[0]] += a[ve[sz-1]];
            ans[ve[sz-1]] = -a[ve[0]];
            rep(i,0,n) cout << ans[i] << ' ';
            cout << endl;
            continue;
        }
        ans[ve[sz-1]] = -sum;
        rep(i,0,sz-1) ans[ve[i]] = a[ve[sz-1]];
        rep(i,0,n) cout << ans[i] << ' ';
        cout << endl;
    }
}