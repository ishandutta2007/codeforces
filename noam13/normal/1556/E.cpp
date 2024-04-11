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

struct SEG{
    int n, sz;
    vi a, b;
    SEG(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
        b.resize(2*sz);
    }
    void update(int i, int x){
        i+=sz;
        a[i]=x, b[i]=x;
        for(i/=2;i;i/=2) {
            a[i] = max(a[2*i], a[2*i+1]);
            b[i] = min(b[2*i], b[2*i+1]);
        }
    }
    int maxi(int l, int r){
        int res = -INF;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) res = max(res, a[l++]);
            if (r%2==0) res = max(res, a[r--]);
        }
        return res;
    }
    int mini(int l, int r){
        int res = INF;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) res = min(res, b[l++]);
            if (r%2==0) res = min(res, b[r--]);
        }
        return res;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    vi a(n), b(n);
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    vi dif(n); loop(i,0,n) dif[i] = b[i]-a[i];
    vi pref(n+1); loop(i,0,n) pref[i+1] = pref[i]+dif[i];
    SEG seg(n+1);
    loop(i,0,n+1) seg.update(i, pref[i]);
    //loop(i,0,n+1) cout<<pref[i]<<" "; cout<<endl;
    //cout<<seg.maxi(0,n)<<endl;
    loop(i,0,q){
        int l, r; cin>>l>>r; 
        int bef = pref[l-1];
        int mini = seg.mini(l,r), maxi = seg.maxi(l,r);
        //cout<<"MINI: "<<mini<<" "<<maxi<<endl;
        if (mini<bef || pref[r]-pref[l-1]!=0) cout<<-1<<endl;
        else cout<<maxi-bef<<endl;
    }
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
8 5
0 1 2 9 3 2 7 5
2 2 1 9 4 1 5 8
2 6
1 7
2 4
7 8
5 8


*/