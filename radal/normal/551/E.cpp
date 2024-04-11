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
typedef pair<ll,int> pll;
const int N = 5e5+20,mod = 1e9+7,inf = 2e9,sq = 800+10;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    int r = poww(a,k/2);
    return 1ll*r*r%mod*poww(a,k&1)%mod;
}
ll a[N],b[sq];
vector<pll> ve[sq];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,0,sq) ve[i].reserve(sq);
    rep(i,0,n){
        cin >> a[i];
        ve[i/sq].pb({a[i],i});
    }
    rep(i,0,(n-1)/sq+1) sort(ve[i].begin(),ve[i].end());
    while (q--){
        int t,l;
        cin >> t >> l;
        if (t == 1){
            int r,x;
            cin >> r >> x;
            l--;
            int R = min(r,l/sq*sq+sq),L = l/sq*sq;
            rep(i,l,R) a[i] += x;
            ve[l/sq].clear();
            R = min(n,L+sq);
            rep(i,L,R) ve[l/sq].pb({a[i],i});
            sort(ve[l/sq].begin(),ve[l/sq].end());
            if ((r-1)/sq == l/sq) continue;
            L = (r-1)/sq*sq;
            R = min(L+sq,n);
            rep(i,L,r) a[i] += x;
            ve[L/sq].clear();
            rep(i,L,R) ve[L/sq].pb({a[i],i});
            sort(ve[L/sq].begin(),ve[L/sq].end());
            r = L;
            l = l/sq*sq+sq;
            for(int i = l; i < r; i+=sq)
                b[i/sq]+=x;
        }
        else{
            int L = inf,R = -1;
            rep(i,0,(n-1)/sq+1){
                if (b[i] >= l) continue;
                int x = lower_bound(ve[i].begin(),ve[i].end(),make_pair(l-b[i],0))-ve[i].begin();
                if (x >= ve[i].size() || ve[i][x].X != l-b[i]) continue;
                L = min(L,ve[i][x].Y);
                x = upper_bound(ve[i].begin(),ve[i].end(),make_pair(l-b[i],inf))-ve[i].begin()-1;
                if (x >= 0) R = max(R,ve[i][x].Y);
            }
            if (R == -1) cout << -1 << endl;
            else cout << R-L << endl;
        }
    }
}