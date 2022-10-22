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
    return v * (p%2?b:1) % MOD;
}
void add(int &a, int b){ a = (a+b)%MOD; }
const int N = 3e6 + 10;
int f[N], invf[N];

int choose(int n, int k){
    if (k<0 || k>n) return 0;
    return f[n] * invf[k] % MOD * invf[n-k] % MOD;
}
int ans[N];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    f[0] = 1;
    loop(i,1,N) f[i] = f[i-1] * i % MOD;
    invf[N-1] = pp(f[N-1], MOD-2);
    loopr(i,0,N-1) invf[i] = invf[i+1] * (i+1) % MOD;
    int base = 3;
    loop(x,0,base){
        ans[x] = 0;
        loop(i,1,n+1) {
            //cout<<"IX: "<<i<<" "<<x<<" "<<choose(3*i, x)<<endl;
            add(ans[x], choose(3*i, x));
        }
        //cout<<"X: "<<ans[x]<<endl;
    }
    int inv3 = pp(3, MOD-2);
    loop(x,base,3*n+1){
        ans[x] = (3*ans[x-1] + ans[x-2])%MOD;
        int cc = (x+3)/3;
        if ((x+2)/3 != cc) ans[x] = ans[x];
        else if ((x+1)/3 != cc) {
            //add(ans[x], 1);
            //add(ans[x], MOD - choose(3*(cc-1), x-2));
        }
        else if ((x)/3 != cc) {
            add(ans[x], choose(3*cc, x+1));
            add(ans[x], MOD - choose(3*(cc-1), x-1));
            add(ans[x], MOD - choose(3*(cc-1), x-2));
        }
        ans[x] = (MOD-ans[x]) % MOD;
        add(ans[x], choose(3*(n+1), x+1));
        ans[x] = ans[x] * inv3 % MOD;
    }
    loop(i,0,q){
        int x; cin>>x;
        cout << ans[x] << endl;
    }
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
2 3
1
5
6

*/