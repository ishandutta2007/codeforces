#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+10,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
int a[N];
ll seg[N*4],lz[N*4];

void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v] = a[l];
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}
void upd(int l,int r,int s,int e,int p,int v = 1){
    if (l >= e || s >= r || s >= e) return;
    if (s <= l && r <= e){
        seg[v] += p;
        lz[v] += p;
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
    if (lz[v]){
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,p,u);
    upd(m,r,s,e,p,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}

ll que(int l,int r,int s,int e,int v = 1){
    if (s <= l && r <= e) return seg[v];
    if (s >= r || l >= e) return 1ll*inf*inf;
    int u = (v << 1),m = (l+r) >> 1;
    if (lz[v]){
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        lz[v] = 0;
    }
    return min(que(l,m,s,e,u),que(m,r,s,e,u|1));;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    build(0,n);
    cin >> q;
    while (q--){
        string s;
        fflush(stdin);
        getline(cin,s);
        if (s == "") getline(cin,s);
        vector <int> num;
        int cur = 0;
        int flag = 1;
        for (char ch : s){
            if(ch == ' '){
                num.pb(flag*cur);
                flag = 1;
                cur = 0;
            }
            else if(ch == '-')
                flag = -1;
            else
                cur = cur * 10 + (ch - '0');
        }
        num.pb(flag*cur);
        int l = num[0],r = num[1];
        if (num.size() == 2){
            if (l <= r){
                cout << que(0,n,l,r+1) << endl;
                continue;
            }
            cout << min(que(0,n,l,n),que(0,n,0,r+1)) << endl;
            continue;
        }
        int v = num[2];
        if (l <= r){
            upd(0,n,l,r+1,v);
        }
        else{
            upd(0,n,l,n,v);
            upd(0,n,0,r+1,v);
        }
    }
    return 0;
}