#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
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

int m;
inline void add(int &a, int b){
    a += b;
    if (a>=m) a-=m;
}
inline void sub(int &a, int b){
    a -= b;
    if (a<0) a+=m;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n>>m;
    vvvvi dp(2, vvvi(n, vvi(n, vi(2, 0)))); 
    vvi sum(n, vi(n));
    int op = 0;
    #define pr op^1
    dp[op][0][0][0] = 1, sum[0][0] = 1; 
    loop(i,1,n){
        op^=1;
        loop(amt,0,i+1) loop(y,0,amt+1) loop(b,0,2) dp[op][amt][y][b] = 0;
        loop(amt,1,i+1){
            loop(y,0,amt+1){
                add(dp[op][amt][y][0], dp[pr][amt-1][amt-1][0]);
                if (y) {
                    sub(dp[op][amt][y][0], dp[pr][amt-1][y-1][0]);
                    add(dp[op][amt][y][1], dp[pr][amt-1][y-1][0]);
                    add(dp[op][amt][y][1], dp[pr][amt-1][y-1][1]);
                }
                /*loop(x,0,amt){
                    if (y<=x) add(dp[i][amt][y][0], dp[i-1][amt-1][x][0]);
                    else add(dp[i][amt][y][1], 
                        dp[i-1][amt-1][x][1]+dp[i-1][amt-1][x][0]);
                }*/
                if (i>1){
                    add(dp[op][amt][y][0], sum[i-2][amt-1]);
                }
                add(sum[i][amt], dp[op][amt][y][0]);
                add(sum[i][amt], dp[op][amt][y][1]);
                //add(dp[i][y][1], dp[i][y][0]);
                if (y) {
                    loop(b,0,2) add(dp[op][amt][y][b], dp[op][amt][y-1][b]);
                }
            }
        }
    }
    int ans = 0;
    loop(amt,0,n) add(ans, sum[n-1][amt]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -D_GLIBCXX_DEBUG -o a & a
3 100000007

*/