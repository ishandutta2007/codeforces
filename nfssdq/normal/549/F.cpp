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

int ar[300011], sum_p[300001], sum_s[300011];
int seg[1200001], pos[1200001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        pos[idx] = s;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    if(seg[idx * 2 + 1] > seg[idx * 2 + 2]){
        seg[idx] = seg[idx * 2 + 1];
        pos[idx] = pos[idx * 2 + 1];
    } else {
        seg[idx] = seg[idx * 2 + 2];
        pos[idx] = pos[idx * 2 + 2];
    }
}
pair < int, int > query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed){
        return mp(seg[idx],pos[idx]);
    }
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        pair < int, int > pl = query(idx * 2 + 1, s, mid, st, mid);
        pair < int, int > pr = query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        if(pl.xx >= pr.xx) return pl;
        return pr;
    }
}
vector < pair < int, int > > queryp[300001], querys[300001];
int n, k;
void go(int l, int r){
    if(l >= r) return;

    pair < int, int > p = query(0, 1, n, l, r);
    go(l, p.yy - 1);
    go(p.yy + 1, r);

    int modsum = 0;
    if(p.yy - l < r - p.yy){
        for(int i = p.yy; i >= l; i--){
            queryp[r].pb(mp(1, (k - modsum + sum_p[p.yy]) % k));
            queryp[p.yy].pb(mp(0, (k - modsum + sum_p[p.yy]) % k));
            modsum = (modsum + ar[i - 1]) % k;
        }
        querys[l].pb(mp(1, sum_s[p.yy]));
        querys[p.yy].pb(mp(0, sum_s[p.yy]));
    } else {
        for(int i = p.yy; i <= r; i++){
            querys[l].pb(mp(1, (k - modsum + sum_s[p.yy]) % k));
            querys[p.yy].pb(mp(0, (k - modsum + sum_s[p.yy]) % k));
            modsum = (modsum + ar[i + 1]) % k;
        }
        queryp[r].pb(mp(1, sum_p[p.yy]));
        queryp[p.yy].pb(mp(0, sum_p[p.yy]));
    }
}
LL cnt[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    FOR(i, 1, n + 1){
        cin >> ar[i];
        insert(0, 1, n, i, ar[i]);
        sum_p[i] = (sum_p[i - 1] + ar[i]) % k;
    }
    for(int i = n; i >= 1; i--){
        sum_s[i] = (sum_s[i + 1] + ar[i]) % k;
        ar[i] %= k;
    }

    go(1, n);

    LL res = 0;
    set0(cnt);
    for(int i = 1; i <= n; i++){
        cnt[sum_p[i]]++;
        REP(j, queryp[i].size()){
            if(queryp[i][j].xx == 1){
                res += cnt[ queryp[i][j].yy ];
            } else {
                res -= cnt[ queryp[i][j].yy ];
            }
        }
    }

    set0(cnt);
    for(int i = n; i >= 1; i--){
        cnt[sum_s[i]]++;
        REP(j, querys[i].size()){
            if(querys[i][j].xx == 1){
                res += cnt[ querys[i][j].yy ];
            } else {
                res -= cnt[ querys[i][j].yy ];
            }
        }
    }

    cout << res << endl;
}