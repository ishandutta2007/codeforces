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



int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vi cnt(n);
    int ans = n;
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        if (a>b) swap(a,b);
        if (cnt[a]++==0) ans--;
    }
    int q; cin>>q;
    loop(i,0,q){
        int op; cin>>op;
        if (op == 3){
            cout << ans << endl;
            continue;
        }
        int a,b; cin>>a>>b; a--, b--;
        if (a>b) swap(a,b);
        if (op==1){
            if (cnt[a]++==0) ans--;
        }
        else{
            if (--cnt[a]==0) ans++;
        }
    }
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
4 3
2 1
1 3
3 4
4
3
1 2 3
2 3 1
3

*/