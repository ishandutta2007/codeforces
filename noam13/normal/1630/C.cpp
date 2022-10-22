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
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i], a[i]--;
    vi last(n, -1), fst(n, -1); 
    loop(i,0,n) last[a[i]] = i;
    loopr(i,0,n) fst[a[i]] = i;
    vii segs;
    loop(i,0,n) if(last[i]!=-1) segs.pb({fst[i], last[i]});
    sort(all(segs));
    //cout << segs << endl;
    
    int cnt = 0;
    int sz = segs.size();
    int i=0;
    while(i<sz){
        ii p = segs[i];
        if (p.x==p.y){
            cnt++, i++;
        }
        else{
            cnt+=2;
            int maxi = p.y; i++;
            while(1){
                int prv = maxi;
                while(i<sz && segs[i].x<prv){
                    chkmax(maxi, segs[i].y), i++;
                }
                if (maxi==prv) break;
                cnt++;
            }
        }
    }
    cout << n - cnt << endl;
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
g++ c.cpp -o a & a
6
1 2 3 1 2 3

7
1 2 1 2 7 4 7

13
1 2 3 2 1 3 3 4 5 5 5 4 7

*/