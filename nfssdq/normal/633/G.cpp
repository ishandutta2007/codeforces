/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

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
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int M;
bitset<2001>seg[400001];
bitset < 2001 > vv, tmp;

int isp[1001], ar[100001], pos[100001];

void rotate(int idx, int x){
    seg[idx] <<= x;
    tmp = seg[idx] & vv;
    tmp >>= M;
    seg[idx] |= tmp;
}

void build(int idx, int s, int e){
    if(s == e){
        int v = ar[pos[s]];
        seg[idx].set(v);
        return;
    }
    int mid = (s + e) / 2;
    build(idx * 2 + 1, s, mid);
    build(idx * 2 + 2, mid + 1, e);
    seg[idx] = seg[idx * 2 + 1] | seg[idx * 2 + 2];
}

int lzy[400001];
void insert(int idx, int s, int e, int st, int ed, int x){
    if(lzy[idx]) {
        if(s != e){
            lzy[idx * 2 + 1] = (lzy[idx * 2 + 1] + lzy[idx]) % M;
            rotate(idx * 2 + 1, lzy[idx]);
            rotate(idx * 2 + 2, lzy[idx]);
            lzy[idx * 2 + 2] = (lzy[idx * 2 + 2] + lzy[idx]) % M;
        }
        lzy[idx] = 0;
    }
    if(s == st && e == ed){
        rotate(idx, x);
        lzy[idx] = (lzy[idx] + x) % M;
//        cout << idx << " " << s << " " << e << endl;
//        REP(i, 2) cout << seg[idx][i] << " ";
//        cout << endl;
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(idx * 2 + 1, s, mid, st, ed, x);
    else if(st > mid) insert(idx * 2 + 2, mid + 1, e, st, ed, x);
    else {
        insert(idx * 2 + 1, s, mid, st, mid, x);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, x);
    }
    seg[idx] = seg[idx * 2 + 1] | seg[idx * 2 + 2];
//    cout << idx << " " << s << " " << e << endl;
//    REP(i, 2) cout << seg[idx][i] << " ";
//    cout << endl;
}

bitset < 2001 > tmp1;

void query(int idx, int s, int e, int st, int ed){
    if(lzy[idx]) {
        if(s != e){
            lzy[idx * 2 + 1] = (lzy[idx * 2 + 1] + lzy[idx]) % M;
            rotate(idx * 2 + 1, lzy[idx]);
            rotate(idx * 2 + 2, lzy[idx]);
            lzy[idx * 2 + 2] = (lzy[idx * 2 + 2] + lzy[idx]) % M;
        }
        lzy[idx] = 0;
    }
    if(s == st && e == ed){
        tmp1 |= seg[idx];
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        query(idx * 2 + 1, s, mid, st, mid);
        query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
    }
}

int ST[100001], ED[100001], T = 0;
vector < int > vc[100001];
void dfs(int c, int p){
    T++;
    ST[c] = T;
    pos[T] = c;
    REP(i, vc[c].size()){
        if(vc[c][i] != p) dfs(vc[c][i], c);
    }
    ED[c] = T;
}

vector < int > prime;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= 1000; i++){
        for(int j = i * 2; j <= 1000; j += i) isp[j] = 1;
    }
    isp[1] = isp[0] = 1;

    int n; cin >> n >> M;
    FOR(i, 1, n+1){
        cin >> ar[i];
        ar[i] %= M;
    }

    for(int i = M; i < 2001; i++) vv.set(i);

    REP(i, M) if(isp[i] == 0)prime.pb(i);

    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    dfs(1, 0);
    build(0, 1, n);

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int v, x; cin >> v >> x;
            x %= M;
            insert(0, 1, n, ST[v], ED[v], x);
        } else {
            int v; cin >> v;
            tmp1.reset();
            query(0, 1, n, ST[v], ED[v]);
            int cnt = 0;
            REP(i, prime.size()) if(tmp1.test(prime[i])) cnt++;
            cout << cnt << endl;
        }
    }
}