
#include<iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
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


typedef long long ll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//auto DIST = uniform_int_distribution<int>(0, INF);

int n, mod;
ll pp(ll b, int pw){
    if (!pw) return 1;
    ll v = pp(b * b % mod, pw/2);
    return v * (pw%2?b:1) % mod;
}
inline int inv(int x){
    return pp(x, mod - 2);
}
inline void add(int &a, int b){
    a = (a + b) % mod;
}

vvi g;
const int N = 2010;
int dp[N][N];
int pref[N];
int val[N];
int ps[N], ss[N];
void dfs(int cur, int p=-1){ // calc dp, pref
    vi ch;
    for(int nei:g[cur]) if(nei!=p){
        dfs(nei, cur);
        pref[nei] = 0;
        ch.pb(nei);
    }
    if (ch.size()==0){
        loop(i,0,n-1) dp[cur][i] = 1;
        return ;
    }
    loop(k,0,n-1){
        dp[cur][k] = 0;
        for(int c:ch)add(pref[c], dp[c][k]);
        if (cur != 0 && k){
	        loop(i,0,ch.size()){
	            int c=ch[i];
	            add(val[c], ll(ps[i]) * ss[i+1] % mod);
                add(dp[cur][k], ll(dp[c][k]) * val[c]%mod);
            }
        }
        ps[0] =1;
            loop(i,0,ch.size()){
	            int c=ch[i];
                ps[i+1]=(ll(pref[c])*ps[i])%mod;
	        }
	        ss[ch.size()]=1;
	        loopr(i,0,ch.size()){
	               int c=ch[i];
              	 ss[i]=(ll(pref[c])*ss[i+1])%mod;
	        }
        add(dp[cur][k], ss[0]);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>mod;
    g.resize(n);
    loop(i,1,n){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    fill(val, val + n, 0);
    dfs(0);
    int fact[N], ifact[N];
    fact[0] = 1; loop(i,1,n+1) fact[i] = ll(i) * fact[i-1] % mod;
    ifact[n] = inv(fact[n]); loopr(i,0,n) ifact[i] = ll(i+1) * ifact[i+1] % mod;
    auto C = [&](int n, int x){
        return ll(fact[n]) * ifact[x] % mod * ifact[n-x] % mod;
    };
    loop(i,0,n-1){
        loop(j,0,i){
            add(dp[0][i], mod-(dp[0][j] * C(i+1, j+1)%mod));
        }
    }
    loop(i,0,n-1) cout<<dp[0][i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
4 998244353
1 2
2 3
1 4


*/