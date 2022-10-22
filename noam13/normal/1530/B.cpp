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


int solve(){
    int n,m; cin>>n>>m;
    vvb board(n, vb(m));
    auto ok = [&](int i, int j) -> bool{
        loop(dx,-1,2) loop(dy,-1,2){
            int x = i+dx, y = j+dy;
            if (x<0 || x>=n || y<0 || y>=m) continue;
            if (board[x][y]) return 0;
        }
        return 1;
    };  
    loop(j,0,m){
        if (ok(0,j)) board[0][j] = 1;
    }
    loop(i,0,n){
        if (ok(i,m-1)) board[i][m-1] = 1;
    }
    loopr(j,0,m){
        if (ok(n-1,j)) board[n-1][j] = 1;
    }
    loopr(i,0,n){
        if (ok(i,0)) board[i][0] = 1;
    }
    loop(i,0,n) { loop(j,0,m) cout<<board[i][j]+0; cout<<endl;}
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
3
3 5
4 4
5 6


*/