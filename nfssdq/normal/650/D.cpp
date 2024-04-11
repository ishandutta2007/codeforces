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

int seg[4000001], lzy[4000001];
void update(int idx, int s, int e){
    seg[idx] = lzy[idx] = 0;
    if(s == e) return;
    lzy[idx * 2 + 1] = lzy[idx * 2 + 2] = 1;
}
void insert(int idx, int s, int e, int p, int v){
    if(lzy[idx]){
        update(idx, s, e);
    }
    if(s == e){
        seg[idx] = max(seg[idx], v);
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(lzy[idx]) update(idx, s, e);
    if(st > ed) return 0;
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else return max(query(idx * 2 + 1, s, mid, st, mid), query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}

void insert1(int idx, int s, int e, int st, int ed, int v){
    if(lzy[idx]) update(idx, s, e);
    if(st > ed) return;
    if(s == st && e == ed){
        seg[idx] = max(seg[idx], v);
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert1(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) insert1(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        insert1(idx * 2 + 1, s, mid, st, mid, v);
        insert1(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
    }
}
int query1(int idx, int s, int e, int p){
    if(lzy[idx]) update(idx, s, e);
    if(s == e) return seg[idx];
    int mid = (s + e) / 2;
    if(p <= mid) return max(seg[idx], query1(idx*2+1, s, mid, p));
    else return max(seg[idx], query1(idx * 2 + 2, mid + 1, e, p));
}

vector < int > qq[400001];
map < int, int > mm;
int ar[400001], res[400001], len[2][400001], on[400001];
pair < int, int > pp[400001];
vector < int > vc, vp[400001];

int arr[2][400001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    FOR(i, 1, n+1) {
        cin >> ar[i];
        mm[ar[i]] = 1;
    }
    REP(i, m){
        cin >> pp[i].xx >> pp[i].yy;
        qq[pp[i].xx].pb(i);
        mm[pp[i].yy] = 1;
    }

    int cc = 0;
    for(auto &v: mm) {
        v.yy = ++cc;
    }


    REP(i, m) pp[i].yy = mm[pp[i].yy];


    int mx = 0;
    FOR(i, 1, n+1){
        ar[i] = mm[ar[i]];
        len[0][i] = 1 + query(0, 1, cc, 1, ar[i]-1);
        insert(0, 1, cc, ar[i], len[0][i]);
        mx = max(mx, len[0][i]);
    }

    set0(seg);
    for(int i = n; i >= 1; i--){
        len[1][i] = 1 + query(0, 1, cc, ar[i] + 1, cc);
        insert(0, 1, cc, ar[i], len[1][i]);
    }

    for(int i = 1; i <= n; i++){
        if(len[0][i]+len[1][i]-1 == mx) vp[len[0][i]].pb(i);
    }
    FOR(i, 1, mx+1){
        if(vp[i].size() == 1){
            on[vp[i][0]] = 1;
        }
    }


    set0(seg);
    for(int i = 1; i <= n; i++){
        REP(j, qq[i].size()){
            arr[0][qq[i][j]] = 1 + query(0, 1, cc, 1, pp[qq[i][j]].yy-1);
        }
        len[0][i] = 1 + query(0, 1, cc, 1, ar[i]-1);
        insert(0, 1, cc, ar[i], len[0][i]);
    }

    set0(seg);
    for(int i = n; i >= 1; i--){
        REP(j, qq[i].size()){
            arr[1][qq[i][j]] = 1 + query(0, 1, cc, pp[qq[i][j]].yy+1, cc);
        }
        len[1][i] = 1 + query(0, 1, cc, ar[i]+1, cc);
        insert(0, 1, cc, ar[i], len[1][i]);
    }


    REP(i, m){
//        cout << arr[0][i] << " " << arr[1][i] << " " << on[pp[i].xx] << endl;
        int v = arr[0][i] + arr[1][i] - 1;
        if(on[pp[i].xx]) v = max(v, mx - 1);
        else v = max(v, mx);
        cout << v << "\n";
    }

}