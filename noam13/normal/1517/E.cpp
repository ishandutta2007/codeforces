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
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e9, MOD = 998244353;

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

void add(int &a, int b){ a = (a+b)%MOD; }

int brute(vi &a){
    int n = a.size();
    int ans = 0;
    loop(x,0,(1<<n)){
        vb b(n);
        vi ps, cs;
        loop(i,0,n) {
            b[i] = x&(1<<i);
            if (b[i]) ps.pb(i);
            else cs.pb(i);
        }
        int v = 0;
        loop(i,0,n) v += (b[i]?a[i]:-a[i]);
        if (v<=0) continue;
        bool ok = 1;
        loop(i,0,int(ps.size())-2){
            if (ps[i+1]-ps[i]<ps[i+2]-ps[i+1]) ok = 0;
        }
        loop(i,0,int(cs.size())-2){
            if (cs[i+1]-cs[i]>cs[i+2]-cs[i+1]) ok = 0;
        }
        ans+=ok;
        if (ok) cout<<b<<endl;
    }
    return ans;
}
int solve(vi& a, int n, int lim){
    if (lim < 0) return 0;
    int ans = 1;
    vi pref(n);
    loop(i,0,n) pref[i] = a[i] + (i>1?pref[i-2]:0);
    int cnt = 0;
    loop(i,0,n){ 
        cnt += a[i];
        if (cnt <= lim){
            int l = 1, r = (n-1-i)/2+1, res = 0;
            while(l<r){
                int mid = (l+r)/2;
                int v = cnt + pref[i+2*mid] - pref[i];
                if (v <= lim) res = mid, l = mid + 1;
                else r = mid;
            }
            //cout<<"LIM: "<<(cnt + pref[i+2]-pref[i])<<" "<<lim<<endl;
            ans += res+1;
        }
        if (i>0 && cnt-a[0] <= lim){
            int l = 0, r = (n-1-i)/2+1, res = 0;
            while(l<r){
                int mid = (l+r)/2;
                int v = cnt - a[0] + pref[i+2*mid] - pref[i];
                if (v <= lim) res = mid, l = mid + 1;
                else r = mid;
            }
            //cout<<"RES: "<<i<<" "<<n<<" "<<res<<endl;
            ans += res+1;
        }
    }
    return ans;
}
int solve(){
    int n; cin>>n;
    int lim = 0;
    vi a(n); loop(i,0,n) cin>>a[i], lim += a[i];
    lim = (lim-1)/2;
    if (n==1) return cout<<1<<endl,0;
    if (n == 2){
        int ans = 0;
        loop(i,0,2) loop(j,0,2){
            ans += (i%2?a[0]:0) + (j%2?a[1]:0) <= lim;
        }
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    int cnt = 0;
    loopr(i,0,n){ // ....CC
        cnt += a[i];
        if (i<n-1 && cnt<=lim) ans++;
    }
    //cout<<ans<<endl;
    ans += solve(a, n-2, lim - a[n-1]); //....PC
    //cout<<ans<<endl;
    ans += solve(a, n-1, lim); //.....P
    cout<<ans%MOD<<endl;
    // cout<<"BRUTE: "<<endl<<brute(a)<<endl;
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
g++ e2.cpp -D_GLIBCXX_DEBUG -o a & a
1
2
754718575 480778441


3
5
2 1 2 1 1
4
9 2 2 2
1
998244353


2
3
26500 19169 15724
6
491 2995 19942 4827 5436 32391





*/