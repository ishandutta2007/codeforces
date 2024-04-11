#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=6e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int seg[N];
int n,m,a[N];
void build(int l,int r,int v,bool b){
    if (r-l == 1){
        seg[v] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,2*v,!b);
    build(mid,r,2*v+1,!b);
    if (b)
        seg[v] = (seg[2*v]|seg[2*v+1]);
    else
        seg[v] = (seg[2*v]^seg[2*v+1]);
}
void upd(int l,int r,int p,int v,bool b,int val){
    if (r-l == 1){
        seg[v] = val;
        return;
    }
    int mid = (l+r)/2;
    if (p < mid)
        upd(l,mid,p,2*v,!b,val);
    else
        upd(mid,r,p,2*v+1,!b,val);
    if (b)
        seg[v] = (seg[2*v]|seg[2*v+1]);
    else
        seg[v] = (seg[2*v]^seg[2*v+1]);
}
int main(){
    int y;
    cin >> y >> m;
    n = (1 << y);
    rep(i,0,n) cin >> a[i];
    build(0,n,1,(y&1));
    rep(i,0,m){
        int p,b;
        cin >> p >> b;
        upd(0,n,p-1,1,(y&1),b);
        cout << seg[1] << endl;
    }
    return 0;
}