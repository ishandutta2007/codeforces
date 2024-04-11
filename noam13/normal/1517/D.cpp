#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#include <bits/stdc++.h>
using namespace std;
// #define int int64_t
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

const int N = 501, K = 41;
ii dir[] = {{0,-1},{1,0},{0,1}, {-1,0}};
int n,m, k;
inline bool inside(ii p){
    return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m;
}
int conv(ii p){
    return p.x * m + p.y;
}
int hor[N][N], ver[N][N];
int dp[K][N][N];

int32_t main(){
    scanf("%d%d%d", &n, &m, &k);
    loop(i,0,n) loop(j,0,m-1) scanf("%d", &hor[i][j]);
    loop(i,0,n-1) loop(j,0,m) scanf("%d", &ver[i][j]);
    if (k%2){
        loop(i,0,n) {
            loop(j,0,m) printf("-1 ");
            printf("\n");
        }
        return 0;
    }
    k/=2;
    loop(i,0,n) loop(j,0,m) dp[0][i][j] = 0;
    loop(x,1,k+1){
        loop(i,0,n) loop(j,0,m) dp[x][i][j] = INF;
        loop(i,0,n) loop(j,0,m){       
            if (i+1 < n) 
                chkmin(dp[x][i+1][j], dp[x-1][i][j] + 2*ver[i][j]);
            if (i-1>=0) 
                chkmin(dp[x][i-1][j], dp[x-1][i][j] + 2*ver[i-1][j]);
            if (j+1 < m) 
                chkmin(dp[x][i][j+1], dp[x-1][i][j] + 2*hor[i][j]);
            if (j-1 >= 0) 
                chkmin(dp[x][i][j-1], dp[x-1][i][j] + 2*hor[i][j-1]);
        }
    }
    loop(i,0,n) {
        loop(j,0,m) printf("%d ", dp[k][i][j]);
        printf("\n");
    }
    return 0;
}
/*
color a
cls
g++ d.cpp -D_GLIBCXX_DEBUG -o b & b
5 5 20
1 1 2 3
1 1 4 5
1 1 6 7
8 9 1 1 
1 1 1 1
1 1 2 5 9
9 5 6 4 1 
7 6 5 1 2 
1 2 4 5 8


*/