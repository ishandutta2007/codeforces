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

template <class A, class B> pair<A,B> operator+(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);

struct Seg{
    int t;
    int l,r;
};
/*struct SEG{
    int n, sz, log=0;
    vi a;
    SEG(int n=0): n(n){
        for(sz=1;sz<n;sz*=2) log++;
        a.resize(2*sz);
        loop(i,0,n) a[i+sz] = 1;
        loopr(i,1,sz) a[i] = a[2*i] + a[2*i+1];
    }
    void fix(int i){
        for(i/=2; i; i/=2){
            if (a[i]) a[i] = a[2*i] + a[2*i+1];
        }
    }
    void update(int l, int r, int x){
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) a[l++] = x;
            if (r%2==0) a[r--] = x;
        }
        fix(l), fix(r);
    }
    void push(int i){
        loop(j,0,log){
            int ind = i>>(log-j);
            if (!a[ind]) a[2*ind] = a[2*ind+1] = 0;
        }
    }
    int query(int l, int r){
        push(l), push(r);
        int res = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) res += a[l++];
            if (r%2==0) res += a[r--];
        }
        return res;
    }
};*/
pair<ii, ii> combine(pair<ii, ii> x, pair<ii, ii> y){
    if (x.x<y.x) swap(x,y);
    return {x.x, max(x.y, y.x)};
}
struct SEG{
    int n, sz;
    vector<pair<ii, ii>> a;
    SEG(int n, vi& arr): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
        loop(i,0,n) a[i+sz] = {{arr[i], i}, {-INF, i}};
        loopr(i,1,sz) a[i] = combine(a[2*i], a[2*i+1]);
    }
    /*void update(int i, int x){
        a[i+=sz] = x;
        for(i/=2;i;i/=2) a[i] = combine(a[2*i], a[2*i+1]);
    }*/
    pair<ii, ii> query(int l, int r){
        pair<ii, ii> res = {{-INF,-1}, {-INF,-1}};
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) res = combine(res, a[l++]);
            if (r%2==0) res = combine(res, a[r--]);
        }
        return res;
    }
};
struct DSU{
    int n;
    vi p;
    DSU(int n): p(n+1,-1){}
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    int uni(int i){
        int a = find(i), b = find(i+1);
        p[a] = b;
        return b;
    }
};
int solve(){
    int n, q; cin >> n >> q;
    vector<Seg> zeros, ones;
    vii qur;
    loop(i,0,q){
        int t; cin>>t;
        if (t==0){
            int x,l,r; cin>>l>>r>>x; l--, r--;
            if (x) ones.pb({i, l, r});
            else zeros.pb({i, l, r});
        }
        else{
            int j; cin>>j; j--;
            qur.pb({i,j});
        }
    }
    DSU dsu(n);
    vi col(n, INF);
    for(auto s:zeros){
        for(int i = dsu.find(s.l); i<=s.r; i = dsu.uni(i)){
            col[i] = s.t;
        }
    }
    //cout<<"HI: "<<endl;
    //cout<<col<<endl;
    SEG seg(n, col);
    vi know(n, INF);
    for(auto s:ones){
        if (s.l==s.r){
            chkmin(know[s.l], s.t);
        }
        else{
            auto res = seg.query(s.l, s.r);
            assert(res.x.x==INF);
            int t = max(res.y.x, s.t);
            //cout<<"S: "<<s.l<<" "<<s.r<<" "<<s.t<<endl;
            //cout<<"Q: "<<res<<" "<<t<<endl;
            chkmin(know[res.x.y], t);
        }
    }
    //cout<<"KNOW: "<<know<<endl;
    for(auto q:qur){
        int ind = q.y, t = q.x;
        if (col[ind]<t) cout<<"NO"<<endl;
        else if (know[ind]<t) cout<<"YES"<<endl;
        else cout<<"N/A"<<endl;
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; //cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
6 9
0 4 5 0
1 5
1 6
0 4 6 1
1 6
0 2 5 1
0 2 2 0
1 3
1 2



*/