#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
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
const long long int N = 2e5+20,mod = 1e9+7,inf=1e14+1,maxm = 1e5+1;
int n;
ll k;
ll a[N],pre[N],seg[N*2];
vector<ll> ve;
void upd(int l,int r,int p,int v){
    seg[v]++;
    if (r-l == 1) return;
    int m = (l+r)/2;
    if (p < m) upd(l,m,p,2*v);
    else upd(m,r,p,2*v+1);
}
int que(int l,int r,int s,int e,int v){
    if (s == e || l >= e || s >= r) return 0;
    if (l >= s && e >= r) return seg[v];
    int m = (l+r)/2;
    return que(l,m,s,e,2*v)+que(m,r,s,e,2*v+1);
}
inline ll check(ll m){
    rep(i,1,2*N) seg[i] = 0;
    upd(0,n+1,lower_bound(ve.begin(),ve.end(),0)-ve.begin(),1);
    ll ans = 0;
    rep(i,1,n+1){
        //pre[i]-pre[j] > m
        ans += que(0,n+1,0,lower_bound(ve.begin(),ve.end(),pre[i]-m)-ve.begin(),1);
        upd(0,n+1,lower_bound(ve.begin(),ve.end(),pre[i])-ve.begin(),1);
        if (ans >= k) break;
    }
    return ans;
}
inline ll bs(){
    ll l = -inf,r = inf,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (check(m) < k) r = m;
        else l = m;
    }
    return r;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    ve.pb(0);
    rep(i,1,n+1){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
        ve.pb(pre[i]);
    }
    sort(ve.begin(),ve.end());
    cout << bs();
    return 0;
}