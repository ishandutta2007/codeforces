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
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int seg[N*4][28],lz[N*4],n,a[26];
string s;
void build(int l,int r,int v,int i){
    if (r-l == 1){
        seg[v][i] = ((s[l]-'a') == i);
        return;
    }
    int m = (l+r)/2;
    build(l,m,2*v,i);
    build(m,r,2*v+1,i);
    seg[v][i] = seg[2*v+1][i]+seg[2*v][i];
}
inline void pass(int l,int r,int v){
    if (lz[v] == -1) return;
    lz[2*v] = lz[v];
    lz[2*v+1] = lz[v];
    rep(i,0,27){
        seg[2*v][i] = 0;
        seg[2*v+1][i] = 0;
    }
    int m = (l+r)/2;
    seg[2*v][lz[v]] = m-l;
    seg[2*v+1][lz[v]] = r-m;
    lz[v] = -1;
}
int get(int l,int r,int s,int e,int i,int v){
    if (l >= s && e >= r) return seg[v][i];
    if (e <= l || s >= r) return 0;
    int m = (l+r)/2;
    pass(l,r,v);
    return get(l,m,s,e,i,2*v)+get(m,r,s,e,i,2*v+1);
}
void upd(int l,int r,int s,int e,int v,int k){
    if (l >= s && e >= r){
        rep(i,0,26)
            seg[v][i] = 0;
        seg[v][k] = r-l;
        lz[v] = k;
        return;
    }
    if (l >= e || s >= r) return;
    int m = (l+r)/2;
    pass(l,r,v);
    upd(l,m,s,e,2*v,k);
    upd(m,r,s,e,2*v+1,k);
    rep(i,0,26) seg[v][i] = seg[2*v][i]+seg[2*v+1][i];
}
int main(){
    //ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(lz,-1,sizeof lz);
    int m;
    cin >> n >> m >> s;
    rep(i,0,26) build(0,n,1,i);
    rep(i,0,m){
        int l,r,co = 0;
        cin >> l >> r;
        l--;
        rep(j,0,26){
            a[j] = get(0,n,l,r,j,1);
            co += (a[j]&1);
        }

        if (((r-l)&1) < co) continue;
        int p = l;
        if (co){
            rep(j,0,26){
                if (a[j]%2){
                    upd(0,n,(l+r)/2,(l+r)/2+1,1,j);
                    a[j]--;
                    break;
                }
            }
        }
        rep(j,0,26){
            if (!a[j]) continue;
            upd(0,n,p,p+a[j]/2,1,j);
            upd(0,n,r-p+l-a[j]/2,r-p+l,1,j);
            p += a[j]/2;
        }
    }
    rep(i,0,n){
        rep(j,0,26){
            if (get(0,n,i,i+1,j,1)){
                cout << char(int('a')+j);
                break;
            }
        }
    }
    return 0;
}