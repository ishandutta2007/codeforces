#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10;
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

int a[N],b[N],l[N];
map<int,vector<int> > mp;
int seg[4*N],lz[N*4];
int n,k,d;

inline void pass(int v){
    if (!lz[v]) return;
    int u = (v << 1);
    lz[u] += lz[v];
    lz[u|1] += lz[v];
    seg[u] += lz[v];
    seg[u|1] += lz[v];
    lz[v] = 0;
}

void build(int l,int r,int v){
    seg[v] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}

void upd(int l,int r,int s,int e,int x,int v = 1){
    if (s >= e || s >= r || l >= e) return;
    if (s <= l && r <= e){
        lz[v] += x;
        seg[v] += x;
        return;
    }
    pass(v);
    int m = (l+r) >> 1, u = (v << 1);
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}

ll que(int l,int r,int s,int e,int v = 1){
    if(l >= e || s >= r) return -2*inf;
    if (s <= l && r <= e) return seg[v];
    pass(v);
    int m = (l+r) >> 1,u = (v << 1);
    return max(que(l,m,s,e,u),que(m,r,s,e,u|1));
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> d;
    if (!d){
        int ans = 0;
        pll p = {-1,-1};
        rep(i,0,n) cin >> a[i];
        rep(i,0,n){
            int j = i;
            while (j < n && a[j] == a[i]){
                j++;
            }
            if (j-i > ans){
                ans = j-i;
                p = {i+1,j};
            }
            i = j-1;
        }
        cout << p.X << ' ' << p.Y << endl;
        return 0;
    }
    rep(i,0,n){
        cin >> a[i];
        a[i] += inf;
        b[i] = a[i]/d;
        if (!mp[a[i]].empty()) l[i] = mp[a[i]].back()+1;
        mp[a[i]].pb(i);
        if (!i) continue;
        if (a[i]%d == a[i-1]%d)
            l[i] = max(l[i],l[i-1]);
        else
            l[i] = i;
    }
    stack<int> st1,st2;
    int ans = 0;
    pll p = {-1,-1};
    rep(i,0,n){
        upd(0,n,0,i,1);
        while (!st1.empty() && b[st1.top()] <= b[i]){
            int j = st1.top();
            st1.pop();
            if (st1.empty()) upd(0,n,0,j+1,-b[i]+b[j]);
            else upd(0,n,st1.top()+1,j+1,-b[i]+b[j]);
        }
        while (!st2.empty() && b[st2.top()] >= b[i]){
            int j = st2.top();
            st2.pop();
            if (st2.empty()) upd(0,n,0,j+1,b[i]-b[j]);
            else upd(0,n,st2.top()+1,j+1,b[i]-b[j]);
        }
        st1.push(i);
        st2.push(i);
        int L = l[i]-1,R = i,m;
        if (i-L <= ans) continue;
        while (R-L > 1){
            m = (L+R) >> 1;
            if (que(0,n,l[i],m+1) >= -k) R = m;
            else L = m;
        }
        if (i-L > ans){
            ans = i-L;
            p = {R+1,i+1};
        }
    }
    cout << p.X << ' ' << p.Y;
}