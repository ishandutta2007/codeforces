#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e18, MOD = 1e9 + 7;

template <class A, class B> pair<A,B> operator+(pair<A,B>& a, pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(pair<A,B>& a, pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);


struct Node{
    int v, prop;
    int l,r,mid;
    Node *lp, *rp;
    Node(int l, int r): l(l), r(r), mid((l+r)/2),  v(0), prop(0), lp(0), rp(0){}
    void setprop(int p){
        prop += p, v += p;
    }
    void fix(){
        if (!lp) lp = new Node(l, mid);
        if (!rp) rp = new Node(mid+1,r);
        if (prop){
            lp->setprop(prop);
            rp->setprop(prop);
            prop = 0;
        }
        v = max(lp->v, rp->v);
    }
    void update(int a, int b, int x){
        if (a>r || b<l) return;
        if (a<=l && r<=b){
            setprop(x);
            return ;
        }
        fix();
        lp->update(a,b,x);
        rp->update(a,b,x);
        fix();
    }
    int query(int a, int b){
        if (a>r || b<l) return 0;
        if (a<=l && r<=b) return v;
        fix();
        return max(lp->query(a,b),rp->query(a,b));
    }
};
int solve(){
    int n, k; cin>>n>>k;
    int m = n*k, maxi = (n+k-2)/(k-1);
    //cout<<"MAXI: "<<maxi<<endl;
    vi a(m);
    vvi ind(n);
    loop(i,0,m) cin>>a[i], a[i]--, ind[a[i]].pb(i);
    vii ans(n,{-1,-1});
    Node seg(0,m);
    loop(iter,0,n){
        vector<pair<int, ii>> opt;
        loop(i,0,n) if(ans[i].x==-1){
            loop(j,0,k-1){
                if (seg.query(ind[i][j], ind[i][j+1])>=maxi) continue;
                opt.pb({ind[i][j+1], {i, j}});
                break;
            }
        }
        sort(all(opt));
        if (opt.size()==0) exit(1);
        int i = opt[0].y.x, j = opt[0].y.y;
        ans[i] = {ind[i][j], ind[i][j+1]};
        seg.update(ans[i].x, ans[i].y, 1);
    }
    loop(i,0,n) cout<<ans[i].x+1<<" "<<ans[i].y+1<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
4 3
2 4 3 1 1 4 2 3 2 1 3 4


*/