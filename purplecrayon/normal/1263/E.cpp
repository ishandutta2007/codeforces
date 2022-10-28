#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e6+10, MAXM = 3e3+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll LINF = 1e18+10;

int t1[4*MAXN], t2[4*MAXN], lzy[4*MAXN];
void push(int v, int tl, int tr, int val){
    t1[v]+=val, t2[v]+=val;
    if (tl != tr) lzy[2*v]+=val, lzy[2*v+1]+=val;
}
void upd(int v, int tl, int tr, int l, int r, int val){
    push(v, tl, tr, lzy[v]), lzy[v]=0;
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) { push(v, tl, tr, val); return; }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, l, r, val), upd(2*v+1, tm+1, tr, l, r, val);
    t1[v] = min(t1[2*v], t1[2*v+1]);
    t2[v] = max(t2[2*v], t2[2*v+1]);
}
void init(){ memset(t1, 0, sizeof(t1)); memset(t2, 0, sizeof(t2)); memset(lzy, 0, sizeof(lzy)); }
void upd(int l, int val){ upd(1, 0, MAXN-1, l, MAXN-1, val); }
int qMx(){ return t2[1]; }
int qMn(){ return t1[1]; }
void solve(){
    int n; cin >> n;
    string s; cin >> s; init();
    int pos=0, ps=0; vector<int> a(n, 0);
    for (int i = 0; i < n; i++){
        if (s[i]=='L') pos = max(pos-1, 0);
        else if (s[i]=='R') pos++;
        else if (s[i]=='(') upd(pos, 1-a[pos]), ps += 1-a[pos], a[pos]=1;
        else if (s[i]==')') upd(pos, -1-a[pos]), ps += -1-a[pos], a[pos]=-1;
        else upd(pos, 0-a[pos]), ps += 0-a[pos], a[pos]=0;
        if (qMn() < 0 || ps) cout << "-1 ";
        else cout << qMx() << " ";
        // cout << pos << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t; 
    while (t--) solve();
}