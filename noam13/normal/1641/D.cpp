#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const int INF = 2e9 + 100, MOD = 1e9 + 7;

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

const int N = 1e5+10;
int a[N][5];
int ww[N];
int nums[N];
const int r = 14, IT = 400;
int best[1<<r]; // change
int solve(){
    int n,m; cin >> n >> m;
    map<int, int> conv;
    loop(i,0,n) {
        loop(j,0,m){
            cin>>a[i][j];
            conv[a[i][j]];
        }
        cin>>ww[i];
    }
    int cnt = 0;
    for(auto &p:conv) p.y=cnt++;
    loop(i,0,n) loop(j,0,m) a[i][j] = conv[a[i][j]];
    // cout << a << endl;
    vi rmp(cnt);
    auto DIST = uniform_int_distribution<int>(0, r-1);
    int mask = (1<<(r)) - 1;
    int ans = INF;
    loop(it,0,IT) {
        loop(i,0,cnt) rmp[i] = DIST(rng);
        fill(best, best+mask+1, INF);
        loop(i,0,n){
            int x =0;
            loop(j,0,m){
                x ^= (1<<rmp[a[i][j]]);
            }
            nums[i] = x;
            //if (best[x^mask]!=INF) chkmin(ans, best[x^mask]+ww[i]);
            if (__builtin_popcount(x)==m) chkmin(best[x], ww[i]);
        }
        loop(x,0,mask+1){
            loop(j,0,r) if(x&(1<<j)){
                chkmin(best[x], best[x^(1<<j)]);
            }
        }
        loop(i,0,n){
            int x = nums[i];
            if (__builtin_popcount(x)==m){
                if (best[mask^x]!=INF) chkmin(ans, ww[i]+best[mask^x]);
            }
        }
    }
    if (ans==INF) cout<<-1<<endl;
    else cout << ans << endl;
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
g++ d.cpp -o a & a
4 2
1 2 5
4 3 1
2 3 2
4 5 3





*/