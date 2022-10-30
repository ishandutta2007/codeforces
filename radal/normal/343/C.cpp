#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e5+30,mod = 1e9+7,inf=1e12;
ll h[N],p[N];
int n,m;
bool check(ll t){
    ll p2=0;
    rep(i,0,n){
        if (p2 == m) return 1;
        if(h[i]-p[p2] > t) return 0;
        ll init;
        if (h[i] > p[p2]){
            init = h[i]-p[p2];
        }
        else init = 0;
        while (p2 < m && p[p2] <= h[i]) p2++;
        while (p2 < m && init+p[p2]-h[i]+min(init,p[p2]-h[i]) <= t) p2++;
    }
    if (p2 == m) return 1;
    return 0;
}
ll binary(ll l, ll r){
    ll t;
    if (check(l)) return l;
    while (r-l > 1){
        t = (l+r)/2;
        if (check(t)) r = t;
        else l = t;
    }
    return r;
}
int main(){
    cin >> n >> m;
    rep(i,0,n)
        cin >> h[i];
    rep (i,0,m)
        cin >> p[i];
    cout << binary(0,1e12);
    return 0;
}