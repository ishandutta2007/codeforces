#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL seg[4000001][2];
void build(int idx, int s, int e){
    seg[idx][0] = e - s + 1;
    if(s == e) return;
    int mid = (s + e) / 2;
    build(idx * 2 + 1, s, mid);
    build(idx * 2 + 2, mid + 1, e);
}
void insert(int idx, int s, int e, int p, LL v){
    if(s == e){
        if(v) {
            seg[idx][0] = 0;
            seg[idx][1] = v - 1;
        } else {
            seg[idx][1] = 0;
            seg[idx][0] = 1;
        }
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx][0] = seg[idx * 2 + 1][0] + max(0ll, seg[idx * 2 + 2][0] - seg[idx * 2 + 1][1]);
    seg[idx][1] = seg[idx * 2 + 2][1] + max(0ll, seg[idx * 2 + 1][1] - seg[idx * 2 + 2][0]);
}
int query(int idx, int s, int e, int p, LL v){
    if(seg[idx][0] <= v) return 0;
    if(s == e) return s;
    int mid = (s + e) / 2;
    if(p <= mid) return query(idx * 2 + 1, s, mid, p, v);
    int res = query(idx * 2 + 2, mid + 1, e, p, max(0ll, v - seg[idx * 2 + 1][0]) + seg[idx * 2 + 1][1]);
    if(res) return res;
    return query(idx * 2 + 1, s, mid, mid, v);
}

LL bit[1000001];
void b_insert(int x, LL v){
    for(int i = x; i <= 1000000; i += i & -i) bit[i] += v;
}
LL b_query(int x) {
    LL res = 0;
    for(int i = x; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int queries[300001][2];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    build(0, 1, 1000000);
    int Q; cin >> Q;
    FOR(i, 1, Q+1){
        string s; cin >> s;
        if(s == "?") {
            int ed; cin >> ed;
            int st = query(0, 1, 1000000, ed, 0);
            LL res = st + 1 + b_query(ed) - b_query(st) - ed;
            if(st == ed) res = 0;
            cout << res << endl;
        } else if (s == "+") {
            int t, d; cin >> t >> d;
            insert(0, 1, 1000000, t, d);
            b_insert(t, d);
            queries[i][0] = t;
            queries[i][1] = d;
        } else {
            int id; cin >> id;
            insert(0, 1, 1000000, queries[id][0], 0);
            b_insert(queries[id][0], -queries[id][1]);
        }
    }
}