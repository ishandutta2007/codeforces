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
const long long int N = 1e5+20,mod = 1e9+7,inf=1e9,maxm = 1e6+1;
ll a[N],seg[4*N][2];
void build(int l,int r,int v){
    if (r-l == 1){
        seg[v][0] = l;
        seg[v][1] = a[l];
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    if (a[seg[u][0]] > a[seg[u+1][0]]) seg[v][0] = seg[u][0];
    else seg[v][0] = seg[u+1][0];
    seg[v][1] = seg[u][1]+seg[u+1][1];
}
void upd(int l,int r,int p,int val,int v){
    if (r-l == 1){
        a[l] = val;
        seg[v][1] = a[l];
        return;
    }
    int m = (l+r)/2;
    int u = 2*v;
    if (p < m) upd(l,m,p,val,u);
    else upd(m,r,p,val,u+1);
    if (a[seg[u][0]] > a[seg[u+1][0]]) seg[v][0] =  seg[u][0];
    else seg[v][0] = seg[u+1][0];
    seg[v][1] = seg[u][1]+seg[u+1][1];
}
int que1(int l,int r,int s,int e,int v){
    if(l >= s && e >= r) return seg[v][0];
    if (l >= e || s >= r) return N-1;
    int m = (l+r)/2;
    int x = que1(l,m,s,e,2*v),y = que1(m,r,s,e,2*v+1);
    if (a[x] > a[y]) return x;
    else return y;
}
ll que2(int l,int r,int s,int e,int v){
    if (l >= s && e >= r) return seg[v][1];
    if (l >= e || s >= r) return 0;
    int m = (l+r)/2;
    return que2(l,m,s,e,2*v)+que2(m,r,s,e,2*v+1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];
    build(0,n,1);
    while (m--){
        int t,l,r;
        cin >> t >> l >> r;
        l--;
        if (t == 3){
            upd(0,n,l,r,1);
            continue;
        }
        if (t == 2){
            int x;
            cin >> x;
            int mx = que1(0,n,l,r,1);
            while (a[mx] >= x){
                upd(0,n,mx,a[mx]%x,1);
                mx = que1(0,n,l,r,1);
            }
        }
        else{
            cout << que2(0,n,l,r,1) << endl;
        }
    }
    return 0;
}