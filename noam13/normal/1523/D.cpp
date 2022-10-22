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


const int M = 16;
int dp[1<<M], F[1<<M];
int solve(vi& a, int n, int m){
    //loop(i,0,n) cout<<a[i]<<" "; cout<<endl<<endl;
    int MASK = (1<<m) - 1;
    //fill(dp, dp+(1<<m), 0);
    fill(F, F+(1<<m), 0);
    loop(i,0,n) F[a[i]^MASK]++;
    for(int i = 0;i < m; ++i) for(int mask = 0; mask < (1<<m); ++mask){
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];
    }
    int best = 0, bestb = 0;
    loop(x,0,1<<m){
        if (F[x^MASK]<(n+1)/2) continue;
        int pc = __builtin_popcount(x);
        if (pc > bestb){
            bestb = pc;
            best = x;
        }
    }
    return best;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,p; cin>>n>>m>>p;
    auto DIST = uniform_int_distribution<int>(0, n-1);
    vector<int> a(n);
    vvi inds(n);
    loop(i,0,n){
        string s; cin>>s;
        loop(j,0,m){
            if (s[j]=='1') inds[i].pb(j), a[i]|=1LL<<j;
        }
    }
    const int T = 31;
    int best = 0, bestb = 0;  
    loop(_,0,T){
        int ind = DIST(rng);
        auto vec = inds[ind];
        int sz = vec.size(), x = a[ind];
        vi na(n);
        loop(i,0,n){
            int y = a[i] & x;
            int yy = 0;
            loop(j,0,sz) if(y&(1LL<<vec[j])) {
                yy|=1<<j;
            }
            na[i] = yy;
        }
        int bb = solve(na, n, sz);
        int pc = __builtin_popcount(bb);
        if (pc > bestb){
            bestb = pc;
            best = 0;
            loop(i,0,sz) if(bb&(1LL<<i)) best|=1LL<<vec[i];
        }
    }
    loop(i,0,m) cout<<((best>>i)&1); cout<<endl;
    //cout<<best<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
5 5 4
11001
10101
10010
01110
11011


3 4 3
1000
0110
1001





3 15 15
111111111111111
111111111111111
111111111111111


3 4 3
1100
1100
1100

*/