#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=7e4+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
pll a[N];
bitset<N> b,c;
int t[N];
bool mark[N];
vector<int> ans[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,s,mx=0;
    cin >> n >> s;
    rep(i,0,n){
        cin >> a[i].X;
        a[i].Y = i;
    }
    sort(a,a+n);
    b[0] = 1;
    rep (i,0,n-1){
        c = (b << a[i].X);
        c = (c & (~(c&b)));
        b |= (b << a[i].X);
        int ind = c._Find_first();
        while (ind != c.size()){
            t[ind] = i;
            ind = c._Find_next(ind);
        }
    }
    if (a[n-1].X > s || !b[s-a[n-1].X]){
        cout << -1;
        return 0;
    }
    mark[n-1] = 1;
    int val = s-a[n-1].X;
    while (val){
        mark[t[val]] = 1;
        val -= a[t[val]].X;
    }
    ans[a[0].Y].pb(a[0].X);
    rep(i,1,n){
        if (mark[i-1]) ans[a[i].Y].pb(a[i].X);
        else{
            ans[a[i].Y].pb(a[i].X-a[i-1].X);
            ans[a[i].Y].pb(a[i-1].Y);
        }
    }
    rep(i,0,n){
        int sz = ans[i].size();
        cout << ans[i][0] << ' ' << sz-1 << ' ';
        rep(j,1,sz) cout << ans[i][j]+1 << ' ';
        cout << endl;
    }
    return 0;
}