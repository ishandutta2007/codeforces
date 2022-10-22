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

template <class A, class B> pair<A,B> operator+(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);

struct Seg{
    int n, sz;
    vi a;
    Seg(int n=0): n(n){
        for(sz = 1; sz<n; sz*=2);
        a.resize(2*sz);
    }
    void add(int l, int r, int d){
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) a[l++] += d;
            if (r%2==0) a[r--] += d;
        }
    }
    int query(int i){
        if (i<0) return 0;
        int res = 0;
        // cout<<"A: "<<a<<endl;
        for(i+=sz; i; i/=2) res+=a[i];
        return res;
    }
};


struct SEG{
    int n, sz;
    vvi st;
    vvii a;

    SEG(int n=0): n(n){
        for(sz = 1; sz<n; sz*=2);
        a.resize(2*sz, vii(3));
        st.resize(2*sz, vi(2));
        loop(i,0,2*sz) build(i);
    }
    void pull(int i){
        loop(j,0,3){
            ii p = a[2*i+1][j];
            ii q = a[2*i][p.y];
            a[i][j] = {p.x+q.x, q.y};
        }
    }
    void build(int i){
        if (!st[i][0] && !st[i][1]){
            loop(j,0,3) a[i][j] = {0, j};
        }
        else if (st[i][0] && st[i][1]) {
            loop(j,0,3) a[i][j] = {1, 2};
        }
        else if (st[i][0]) {
            a[i][0] = {1, 2};
            a[i][1] = a[i][2] = {0, 1};
        }
        else{
            a[i][1] = {1, 2};
            a[i][0] = a[i][2] = {0, 0};
        }
    }
    void insert(int i, int id){
        i+=sz;
        // insert
        st[i][id] = 1;
        build(i);
        for(i/=2; i; i/=2) pull(i);
    }
    void erase(int i, int id){
        i+=sz;
        // erase
        st[i][id] = 0;
        build(i);
        for(i/=2; i; i/=2) pull(i);
    }
    int query(int r){
        r--;
        int cur = 2, res = 0;
        int l = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2) {
            if (l%2) l++;
            if (r%2 == 0){
                ii p = a[r][cur];
                res += p.x, cur = p.y;
                r--;
            }
        }
        return res;
    }
};

int prev(set<int>& s, int x){
    return *(--s.lower_bound(x));
}

int n;
vvi cnt;
vector<set<int>> s;
Seg seg;
SEG ansseg;

void init(){
    cnt.resize(2, vi(n+1));
    s.resize(2);
    loop(i,0,2) cnt[i][0] = 1, s[i].insert(0);
    //seg = Seg(n+10);
    //seg.add(1, n+9, 1);
    ansseg = SEG(2*n+10);
    loop(j,0,2) ansseg.insert(0, j);
}
int prev(int id, int x){
    return *(--s[id].lower_bound(x));
}
void insert(int id, int x){
    if ((cnt[id][x]++) == 0) {
        //s[id].insert(x);
        ansseg.insert(x, id);
    }
}
void erase(int id, int x){
    if ((--cnt[id][x]) == 0) {
        //s[id].erase(x);
        ansseg.erase(x, id);
    }
}
int getans(int x){
    return ansseg.query(x);
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    init();
    loopr(i,0,n){
        insert(1, a[i]);
    }
    int ans = 0;
    loop(i,0,n){
        erase(1, a[i]);
        // solve
        /*int cur = a[i];
        int cc = 0;
        while(cur) {
            cur = min(prev(0, cur), prev(1, cur));
            cc++;
        }*/
        ans += getans(a[i]);
        insert(0, a[i]);
    }
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
6
1 4 2 4 0 2


*/