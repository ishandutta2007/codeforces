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
const long long int N=2e6+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int seg[4*N],idx[N];
bool c[N],vis[N];
int a[N],n,m;
void build(int l,int r,int v){
    if (r-l == 1){
        seg[v] = c[l];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,2*v);
    build(mid,r,2*v+1);
    seg[v] = seg[2*v]+seg[2*v+1];
    return;
}
inline int find(int ind){
    int l = 0,r = n+m,v = 1,seen=0,mid;
    while (r-l > 1){
        mid = (l+r)/2;
        if (seen+seg[2*v] < ind){
            seen += seg[2*v];
            l = mid;
            v = 2*v+1;
            continue;
        }
        r = mid;
        v*=2;
    }
    return r-1;
}
void upd(int l,int r,int v,int ind){
    if(c[ind]) seg[v]--;
    else seg[v]++;
    if (r-l == 1){
        c[ind] = !c[ind];
        return;
    }
    int mid = (l+r)/2;
    if (ind < mid) upd(l,mid,2*v,ind);
    else upd(mid,r,2*v+1,ind);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(a,-1,sizeof a);
    cin >> n >> m;
    rep(i,m,m+n){
        c[i] = 1;
        idx[i-m+1] = -1;
    }
    build(0,n+m,1);
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        int ind = find(y);
        if (a[ind] != -1 && a[ind] != x){
            cout << -1 << endl;
            return 0;
        }
        if (a[ind] == -1) idx[x]=ind-m;
        a[ind] = -1;
        a[m-i-1] = x;
        upd(0,n+m,1,ind);
        upd(0,n+m,1,m-i-1);
    }
    rep(i,0,n+m){
        if (a[i] != -1){
            if (vis[a[i]]){
                cout << -1;
                return 0;
            }
            vis[a[i]] = 1;
        }
    }
    vector<int> ve(n);
    int p = 1;
    rep(i,0,n+m){
        if (c[i] == 0) continue;
        if (a[i] != -1){
            ve[idx[a[i]]] = a[i];
            continue;
        }
    }
    for (int u : ve){
        if(u) cout << u << ' ';
        else{
            while (vis[p]) p++;
            cout << p<< ' ';
            p++;
        }
    }
    return 0;
}