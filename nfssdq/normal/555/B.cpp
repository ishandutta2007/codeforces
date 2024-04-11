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

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
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

typedef pair<LL,LL> pii;
pii pp[200001];
pii ar[200001];
pair < pii, int > qq[200001];
LL res[200001];
int seg[800001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = (seg[idx * 2 + 1] + seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(st > ed || seg[idx] == 0) return -1;
    if(s == e) return s;
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else{
        int v = query(idx * 2 + 1, s, mid, st, mid);
        if(v != -1) return v;
        return query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, n) cin >> pp[i].xx >> pp[i].yy;
    REP(i, m) {
        cin >> ar[i].xx;
        ar[i].yy = i;
    }

    REP(i, n - 1){
        qq[i].xx.yy = pp[i+1].xx - pp[i].yy;
        qq[i].xx.xx = pp[i+1].yy - pp[i].xx;
        qq[i].yy = i;
    }
    sort(qq, qq + n - 1);
    sort(ar, ar + m);
    REP(i, m) insert(0, 0, m-1, i, 1);

    REP(i, n-1) swap(qq[i].xx.xx, qq[i].xx.yy);
    int last = 0;
    REP(i, n-1){
        int l = lower_bound(ar, ar + m, mp(qq[i].xx.xx, 0ll)) - ar;
        int r = upper_bound(ar, ar + m, mp(qq[i].xx.yy, 300000ll)) - ar - 1;
        int v = query(0, 0, m-1, l, r);
        if(v == -1){
            cout << "No" << endl;
            return 0;
        }
        res[qq[i].yy] = ar[v].yy + 1;
        insert(0, 0, m-1, v, 0);
    }
    cout << "Yes" << endl;
    REP(i, n-1) cout << res[i] << " ";
    cout << endl;
}