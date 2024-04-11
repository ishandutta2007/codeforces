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

const bool de = 0;
vi aa;
int ask_and(int i, int j){
    cout<<"and "<<i+1<<" "<<j+1<<endl;
    int v; 
    if(de) v = aa[i]&aa[j];
    else cin>>v;
    return v;
}
int ask_or(int i, int j){
    cout<<"or "<<i+1<<" "<<j+1<<endl;
    int v; 
    if(de) v = aa[i]|aa[j];
    else cin>>v;
    return v;
}
int ask_xor(int i, int j){
    return ask_or(i,j) ^ ask_and(i,j);
}
int solve(){
    int n,k; cin>>n>>k; k--;
    if(de){
        aa = vi(n);
        loop(i,0,n) cin>>aa[i];
    }
    vi arr(n);
    int ab1 = ask_and(0,1), ab2 = ask_or(0,1);
    int v = ab2^ab1;
    int ac1=ask_and(0,2), ac2=ask_or(0,2);
    int bc1=ask_and(1,2), bc2=ask_or(1,2);
    int a = ab1, b = ab1;
    loop(i,0,31){
        int bb = int(1)<<i;
        if (v&bb){
            if ((ac1&bb) && (bc1&bb)==0) a=a|bb;
            else if((bc1&bb) && (ac1&bb)==0) b=b|bb;
            else if ((ac2&bb) && (bc2&bb)==0) a=a|bb;
            else if ((bc2&bb) && (ac2&bb)==0) b=b|bb;
        }
    }
    arr[0] = a, arr[1] = b, arr[2] = a ^ (ac2^ac1);
    loop(i,3,n) arr[i] = arr[0] ^ ask_xor(0,i);
    sort(all(arr));
    int ans = arr[k];
    cout<<"finish "<<ans<<endl;
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


*/