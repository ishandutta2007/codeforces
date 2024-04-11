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
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int seg[4*N][27],lz[4*N],n,cnt[27];
string s;
void build(int l,int r,int i,int v){
    lz[v] = -1;
    if (r-l == 1){
        seg[v][i] = ((s[l]-'a') == i);
        return;
    }
    int m = (l+r+1)/2;
    build(l,m,i,2*v);
    build(m,r,i,2*v+1);
    seg[v][i] = seg[2*v][i]+seg[2*v+1][i];
}
inline void put(int l,int r,int v,int k){
    rep(i,0,26){
        if (i != k) seg[v][i] = 0;
        else seg[v][i] = r-l;
    }
    lz[v] = k;
}
void upd(int s,int e,int l,int r,int k,int v){
    if (s >= l && e <= r){
        put(s,e,v,k);
        return;
    }
    if (r <= s || l >= e) return;
    int m = (s+e+1)/2;
    if (lz[v] > -1){
        put(s,m,2*v,lz[v]);
        put(m,e,2*v+1,lz[v]);
        lz[v] = -1;
    }
    upd(s,m,l,r,k,2*v);
    upd(m,e,l,r,k,2*v+1);
    rep(i,0,26) seg[v][i] = seg[2*v][i]+seg[2*v+1][i];
}
int qu(int s,int e,int l,int r,int v,int k){
    if (l <= s && e <= r)
        return seg[v][k];
    if (l >= e || r <= s)
        return 0;
    int m = (s+e+1)/2;
    if (lz[v] > -1){
        put(s,m,2*v,lz[v]);
        put(m,e,2*v+1,lz[v]);
        lz[v] = -1;
    }
    return qu(s,m,l,r,2*v,k)+qu(m,e,l,r,2*v+1,k);
}
int main(){
    int q;
    cin >> n >> q;
    cin >> s;
    rep(i,0,26) build(0,n,i,1);
    while (q--){
        int l,r,k;
        cin >> l >> r >> k;
        l--;
        rep(i,0,26) cnt[i] = qu(0,n,l,r,1,i);
        int p = l;
        if (!k){
            repr(i,25,0){
                if(!cnt[i]) continue;
                upd(0,n,p,cnt[i]+p,i,1);
                p += cnt[i];
            }
        }
        else{
            rep(i,0,26){
                if (!cnt[i]) continue;
                upd(0,n,p,p+cnt[i],i,1);
                p+=cnt[i];
            }
        }
    }
    rep(i,0,n){
        rep(j,0,26){
            int x = qu(0,n,i,i+1,1,j);
            if (x){
                cout << char(int('a')+j);
                break;
            }
        }
    }
    return 0;
}