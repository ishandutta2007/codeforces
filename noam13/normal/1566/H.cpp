#include <bits/stdc++.h>
using namespace std;
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
const int INF = 1e9, MOD = 1e9 + 7;

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

const int MAX = 1e6 + 10;
int c,n; 
int divs[MAX];
void precalc(){
    fill(divs, divs+MAX, -1);
    loop(i,2,MAX){
        if (divs[i]!=-1) continue;
        for(int j = i; j<MAX; j+=i) divs[j] = i;
    }
}
int f(int x){
    int xx = x;
    vi d;
    while(x>1){
        d.pb(divs[x]), x/=divs[x];
    }
    sort(all(d)), d.resize(unique(all(d))-d.begin());
    for(int dd:d) x*=dd;
    //cout<<"X: "<<xx<<" "<<x<<" "<<d<<endl;
    return x;
}
void solve(vi& a, int need, vi &res, vvi& opt){
    const int M = 260;
    int n = a.size();
    assert(n <= M);
    //typedef bitset<20> bit;
    vector<bitset<20>> mat(n);
    vector<bitset<M>> who(n);
    loop(i,0,n) mat[i] = a[i], who[i][i] = 1;
    // mat[n] = need;
    int row = 0;
    vi col(20,-1);
    loop(j,0,20){
        int good = -1;
        loop(i,row,n) if(mat[i][j]) {good = i; break;}
        if (good == -1) continue;
        col[j] = row;
        swap(mat[row], mat[good]);
        swap(who[row], who[good]);
        loop(i,row+1,n) if(mat[i][j]) mat[i]^=mat[row], who[i]^=who[row];
        row++;
    }
    bitset<20> b = need; bitset<M> w;
    loop(j,0,20){
        if (b[j]){
            int i = col[j];
            assert(i != -1);
            w ^= who[i], b ^= mat[i];
        }
    }
    loop(i,0,n) if(w[i]) res.pb(a[i]);
    loop(i, row, n){
        if (who[i]==0) continue;
        opt.pb(vi(0));
        loop(j,0,n) if(who[i][j]) opt.back().pb(a[j]);
    }
}

double getT(){
    static double t = 1e9;
    t = t*0.999;
    return t;
}
double P(int o, int n, double t){
    if (n<o) return 1.0;
    return exp((o-n)/t);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    auto start = clock();
    cin>>c>>n;
    precalc();
    vvi gs(c+1);
    loop(i,1,c+1){
        gs[f(i)].pb(i);
    }
    vi ask;
    loop(i,1,c+1) if(gs[i].size()) ask.pb(i);
    vi ans(c+1);
    cout << ask.size() << " "; 
    for(auto i:ask) cout<<i<<" "; cout<<endl;
    for(int i:ask){
        int x; cin>>x;
        ans[i] = x;
    }
    int all = ans[1];
    vi lrg(c+1);// = ans;
    loop(i,1,c+1){
        if (!gs[i].size()) continue;
        //if (i>1) lrg[i] ^= all;
        for(int j=i;j<=c; j+=i) lrg[j]^=(ans[i]^all);
    }
    lrg[1] = all;
    vi exc = lrg;
    loopr(i,1,c+1){
        if (!gs[i].size()) continue;
        for(int j=2*i;j<=c; j+=i) if (gs[j].size()) exc[i]^=exc[j];
    }
    vi res;
    vvi opt;
    loop(i,1,c+1){
        if (!gs[i].size()) continue;
        solve(gs[i], exc[i], res, opt);
    }
    vb in(c+1);
    for(int x:res) in[x] = 1;
    int m = opt.size(), sz = res.size();
    auto realD = uniform_real_distribution<double>(0,1);
    while(sz!=n && (clock()-start<=3*CLOCKS_PER_SEC)){
        int ind = rng()%m;
        int nn = sz;
        for(int x:opt[ind]) nn+=(in[x]?-1:1);
        if (P(abs(n-sz), abs(n-nn), getT()) >= realD(rng)){
            for(int x:opt[ind]) in[x]=in[x]^1;
            sz = nn;
        }
    }
    if (sz!=n) return 1;
    res.clear();
    loop(i,0,c+1) if(in[i]) res.pb(i);
    assert(res.size()==n);
    loop(i,0,n) cout<<res[i]<<" "; cout<<endl;
    return 0;
}
/*
color a
cls
g++ h.cpp -o b & b
10 6
4 4 2 11 4 4 1

10 2 3 5  7 1 6
1  4 2 11 4 4 4

*/