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
int st[400][N];
pll inp[N];
pair<pll,int> in[N];
int ti[N],co[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,s;
    cin >> n;
    s = sqrt(n)+1;
    rep(i,0,n){
        int t,a,x;
        cin >> a >> t >> x;
        in[i] = {{a,t},x};
        ti[i] =t;
        co[i] = x;
    }
    sort(ti,ti+n);
    sort(co,co+n);
    rep(i,0,n){
        int a = in[i].X.X,x = lower_bound(co,co+n,in[i].Y)-co+1,t = lower_bound(ti,ti+n,in[i].X.Y)-ti+1;;
        inp[t] = {a,x};
        if (a == 1){
            st[t/s][x]++;
            continue;
        }
        if (a == 2){
            st[t/s][x]--;
            continue;
        }
        int ans = 0,p = 1;
        while (p <= t-s){
            ans += st[p/s][x];
            p+=s;
        }
        p--;
        
        rep(j,p,t){
            if (inp[j].Y == x){
                if (inp[j].X == 1) ans++;
                if (inp[j].X == 2) ans--;
            }
        }
        cout << ans << endl;

    }
    return 0;
}