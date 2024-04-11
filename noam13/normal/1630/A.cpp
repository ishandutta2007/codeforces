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
    int n, k; cin>>n>>k;
    if (n==4 && k==3) return cout<<-1<<endl,0;
    int mask = n-1;
    vii ans; 
    if (k==n-1){
        ans.pb({mask, mask^1});
        ans.pb({3, 1});
        ans.pb({0, mask^3});
        loop(i,0,n/2) if(i!=0 && i!=1 && i!=3) ans.pb({i, mask^i});
    }
    else if (k==0){
        loop(i,0,n/2) ans.pb({i, mask^i});
    }
    else{
        ans.pb({mask, k});
        ans.pb({0, mask^k});
        int kk = min(k, mask^k);
        loop(i,1,n/2) if(i!=kk) ans.pb({i, mask^i});
    }
    int v = 0;
    for(ii p:ans) {
        cout<<p.x<<" "<<p.y<<endl;
        v+=(p.x&p.y);
    }
    //cout<<"ANS: "<<v<<" "<<k<<endl;
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
g++ a.cpp -o a & a
6
4 0
4 1
4 2
4 3
8 7
8 2

*/