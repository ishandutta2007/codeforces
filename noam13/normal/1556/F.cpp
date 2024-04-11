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

int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) %MOD;
}
int inv(int a){ return pp(a, MOD-2); }
void add(int &a, int b){a =  (a+b)%MOD;}
void sub(int &a, int b){
    a = (a-b)%MOD;
    if (a<0) a+=MOD;
}
int n, N; 
vi a;
vvi win;
vi cut;
int solve(){
    vi dp(N); //dp[1<<s] = 1;
    loop(mask,1,N){
        /*if ((mask&(1<<s))==0) continue;
        if (mask == (1<<s)) continue;*/
        vi inds;
        loop(i,0,n) if(mask&(1<<i)) inds.pb(i);
        dp[mask] = inds.size();
        /*if (inds.size()==1) {
            dp[mask] = 1;
            continue;
        }*/
        for(int sml = mask; sml > 0; sml = (sml-1) & mask){
            if (sml==mask) continue;
            int p = 1;
            vi x,y;
            for(int i:inds) {
                if(sml&(1<<i)) x.pb(i);
                else y.pb(i);
            }
            for(int xx:x) for(int yy:y) p = p*win[yy][xx] % MOD;
            sub(dp[mask], dp[sml] * p);
        }
    }
    return dp[N-1];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n; N = 1<<n;
    a = vi(n); loop(i,0,n) cin>>a[i];
    win = vvi(n, vi(n)); 
    loop(i,0,n) loop(j,0,n) if (i!=j) win[i][j] = a[i]*inv(a[i]+a[j])%MOD;
    /*cut = vi(N);
    loop(mask,0,N){
        vi x,y;
        loop(i,0,n) {
            if(mask&(1<<i)) x.pb(i);
            else y.pb(i);
        }
        int v = 1;
        for(int xx:x) for(int yy:y) v = v*win[yy][xx] % MOD;
        cut[mask] = v;
    }*/
    int ans = solve();
    /*loop(i,0,n){
        add(ans, solve(i));
    }*/
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
2
1 2



*/