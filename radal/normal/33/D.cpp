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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=3e16,maxk = 1e5+20;
const long double eps = 0.0001;
int n,m,k;
pll a[N];
pair<ll,pll> b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    rep(i,0,n) cin >> a[i].X >> a[i].Y;
    rep(i,0,m) cin >> b[i].X >> b[i].Y.X >> b[i].Y.Y;
    rep(i,0,k){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        int d1,d2;
        int ans = 0;
        rep(j,0,m){
            d1 = abs(a[x].X-b[j].Y.X)+abs(a[x].Y-b[j].Y.Y);
            d2 = abs(a[y].X-b[j].Y.X)+abs(a[y].Y-b[j].Y.Y);
            if ((d1 < b[j].X && d2 > b[j].X) || (d1 > b[j].X && d2 < b[j].X)) ans++;
        }
        cout << ans << endl;
    }
}