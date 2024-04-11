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
const int INF = 1e18, MOD = 998244353;

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

void add(int& a, int b){ a = (a+b)%MOD;}

int n = 200;
int mem[10];
int ask(int dd){
    if (mem[dd]!=-1) return mem[dd];
    int d = 1<<dd;
    if (d>n) return mem[dd] = 0;
    vii p;
    loop(i,0,n) loop(j,0,n){
        p.pb({i,j});
        j+=d-1;
    }
    cout<<"? "<<p.size()<<endl;
    for(auto x:p) cout<<x.x+1<<" "<<x.y+1<<" ";
    //cout<<"DD: "<<dd<<" "<<d;
    cout<<endl;
    cin>>mem[dd];
    return mem[dd];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    loop(i,0,10) mem[i] = -1;
    int area = ask(0);
    int l = 1, r = 8, mid, ans = 0;
    while(l<r){
        mid = (l+r)/2;
        int mult = (1<<mid), acp = ask(mid);
        if (acp * mult != area) r = mid;
        else l = mid + 1, ans = mid;
    }
    int mult = (1<<ans);
    int h = abs(ask(ans+1) * 2 - area / mult);
    int w = area / h;
    cout << "! " << 2*(h+w-2) << endl;
    return 0;
}
/*
color a
cls
g++ h.cpp -D_GLIBCXX_DEBUG -o a & a



*/