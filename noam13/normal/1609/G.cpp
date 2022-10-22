#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 1e18, MOD = 1e9+7;

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

const int MAX = 1e5, SZ = 4*MAX;
struct Seg{
    int maxi[SZ], prop[SZ];
    Seg(){
        fill(maxi, maxi+SZ, 0);
        fill(prop, prop+SZ, 0);
    }
    void addprop(int cur, int d){
        prop[cur] += d, maxi[cur]+=d;
    }
    void push(int cur){
        addprop(2*cur, prop[cur]);
        addprop(2*cur+1, prop[cur]);
        prop[cur] = 0;
    }
    void pull(int cur){
        maxi[cur] = max(maxi[2*cur], maxi[2*cur+1]);
    }
    void update(int cur, int l, int r, int a, int b, int d){
        if (l>=b || r<=a) return ;
        if (a<=l && r<=b) return addprop(cur, d);
        push(cur);
        int m = (l+r)/2;
        update(2*cur, l, m, a,b,d);
        update(2*cur+1, m, r, a,b,d);
        pull(cur);
    }
    int find(int cur, int l, int r, int v){
        if (l+1==r) return l;
        push(cur), pull(cur);
        int m = (l+r)/2;
        if (maxi[2*cur]>v) return find(2*cur, l, m, v);
        return find(2*cur+1, m, r, v);
    }
};
int C2(int x){
    return (x*(x+1))/2;
}
struct SumSeg{
    int sum[SZ], slp[SZ], add[SZ];
    SumSeg(){
        fill(sum, sum+SZ, 0);
        fill(slp, slp+SZ, 0);
        fill(add, add+SZ, 0);
    }
    void addprop(int cur, int l, int r, int sl, int ad){
        slp[cur] += sl, add[cur] += ad;
        sum[cur] += (r-l)*ad + C2(r-l)*sl;
    }
    void push(int cur, int l, int r, int m){
        addprop(2*cur, l, m, slp[cur], add[cur]);
        addprop(2*cur+1, m, r, slp[cur], add[cur]+(m-l)*slp[cur]);
        slp[cur] = add[cur] = 0;
    }
    void pull(int cur){
        sum[cur] = sum[2*cur] + sum[2*cur+1];
    }
    void update(int cur, int l, int r, int a, int b, int sl){
        if (l>=b || r<=a) return ;
        if (a<=l && r<=b) return addprop(cur, l, r, sl, (l-a)*sl);
        int m = (l+r)/2;
        push(cur, l, r, m);
        update(2*cur, l, m, a,b, sl);
        update(2*cur+1, m, r, a,b, sl);
        pull(cur);
    }
    int query(int cur, int l, int r, int a, int b){
        if (l>=b || r<=a) return 0;
        if (a<=l && r<=b) return sum[cur];
        int m = (l+r)/2;
        push(cur, l, r, m), pull(cur);
        return query(2*cur, l, m, a,b) + query(2*cur+1, m, r, a,b);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m, q; cin>>n>>m>>q;
    vi a(n), b(m);
    loop(i,0,n) cin>>a[i];
    loop(j,0,m) cin>>b[j];
    vi da(n-1), db(m-1);
    loop(i,1,n) da[i-1] = a[i]-a[i-1];
    loop(j,1,m) db[j-1] = b[j]-b[j-1];
    Seg seg;
    SumSeg sumseg;
    loop(j,0,m-1) seg.update(1, 0, m, j, j+1, db[j]);
    seg.update(1, 0, m, m-1, m, INF);
    loop(j,0,m) sumseg.update(1, 0, m, j, j+1, b[j]);
    auto query = [&]()->int{
        int ans = 0, j = 0;
        loop(i,0,n){
            int k = (i==n-1?m-1:seg.find(1, 0, m, da[i]));
            ans += sumseg.query(1, 0, m, j, k+1); // [j,k]
            ans += (k-j+1)*a[i];
            j = k;
        }
        return ans;
    };
    loop(ind,0,q){
        int op,k,d; cin>>op>>k>>d;
        if (op==1){
            //cout<<"A: "<<da<<" INF"<<a<<endl;
            k = n-k;
            loop(i,k,n) a[i]+=(i-k+1)*d; 
            loop(i,k-1,n-1) if(i>=0) da[i]+=d;
            //cout<<"A: "<<da<<" "<<a<<endl;
        }
        else{
            k = m-k;
            seg.update(1, 0, m, k-1, m-1, d);
            sumseg.update(1, 0, m, k, m, d);
        }
        cout << query() << endl;
    }
    return 0;
}
/*
clear
g++ temp.cpp -o a ; ./a
5 3 4
1 2 4 7 11
5 7 10
1 3 2
2 2 5
1 5 4
2 1 7



*/