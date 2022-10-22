#include <bits/stdc++.h>
using namespace std;
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

typedef long long ll;
const ll INF = 2e18, MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<ll>(0, INF);

const int LOG = 62;
inline int count(ll x){
    return __builtin_popcountll(x);
}

const int MAX = 1e6+10;
ll ans = 0;
ll a[MAX];
int cnt[MAX];
ll l[MAX], r[MAX];
pair<ll, ll> pl[MAX];
int sokl[MAX];
//int pref[2][MAX][LOG];
int pref[2][LOG];
void solve(int L, int R){
    if (L+1==R) return ;
    //int ans = 0;
    int mid = (L+R)/2;
    solve(L, mid), solve(mid, R);  
    int lsz = mid-L, rsz = R-mid;
    loop(i,L,mid) l[i-L] = a[i];
    loop(i,mid,R) r[i-mid] = a[i];
    reverse(l, l+lsz);
    pl[0] = {l[0], l[0]};
    loop(i,1,lsz){
        pl[i] = pl[i-1];
        chkmin(pl[i].x, l[i]);
        chkmax(pl[i].y, l[i]);
    }
    auto ok = [&](pair<ll, ll> &p)->bool{
        return count(p.x)==count(p.y);
    };
    sokl[lsz] = 0;
    loopr(i,0,lsz){
        sokl[i] = sokl[i+1] + ok(pl[i]);
    }
    // b=0 -> minimum
    /*loop(b,0,2) loop(j,0,LOG) pref[b][0][j] = 0;
    loop(i,0,lsz){
        loop(j,0,LOG) {
            pref[0][i+1][j] = pref[0][i][j];
            pref[1][i+1][j] = pref[1][i][j];
        }
        pref[0][i+1][count(pl[i].x)]++;
        pref[1][i+1][count(pl[i].y)]++;
    }*/
    pair<ll, ll> p = {INF, -INF}; // (min, max)
    int mini = 0, maxi = 0; 
    loop(b,0,2) loop(i,0,LOG) pref[b][i] = 0; // [mini, maxi)
    loop(i,0,rsz){
        chkmin(p.x, r[i]);
        chkmax(p.y, r[i]);
        while(mini<lsz && l[mini]>p.x) {
            if (mini<maxi) {
                pref[0][count(pl[mini].x)]--;
                pref[1][count(pl[mini].y)]--;
            }
            else{
                pref[0][count(pl[mini].x)]++;
                pref[1][count(pl[mini].y)]++;
            }
            mini++;
        }
        while(maxi<lsz && l[maxi]<p.y){
            if (maxi<mini) {
                pref[0][count(pl[maxi].x)]--;
                pref[1][count(pl[maxi].y)]--;
            }
            else{
                pref[0][count(pl[maxi].x)]++;
                pref[1][count(pl[maxi].y)]++;
            }
            maxi++;
        }
        int x = mini, y = maxi;
        int b = 0;
        if (x>y) swap(x, y), b = 1;
        ans += sokl[y];
        if (ok(p)) ans+=x; // [0, x)
        int cnt;
        if (b) cnt = count(p.x);
        else cnt = count(p.y);

        ans += pref[b][cnt];
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    ans = 0;
    loop(i,0,n) cin>>a[i], cnt[i] = count(a[i]);
    solve(0, n);
    ans += n;
    cout << ans << endl;
    return 0;
}
/*
clear
g++ temp.cpp -o a ; ./a
10
0 5 7 3 9 10 1 6 13 7


5
1 2 3 4 5



5
4 8 8 2 4



*/