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

int seg[2000001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = max(seg[idx], v);
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else if(p > mid) insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(st > ed) return 0;
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        return max(query(idx * 2 + 1, s, mid, st, mid), query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
    }
}
int dp[200001], diff[200001], sum[200001];
pair < int, int > pp[200001];
map < int, int > mm;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n){
        cin >> pp[i].xx >> pp[i].yy;
    }
    sort(pp, pp + n);

    REP(i, n){
        diff[i] = pp[i].xx - pp[i].yy;
        sum[i] = pp[i].xx + pp[i].yy;
        mm[ diff[i] ] = 1;
        mm[ sum[i] ] = 1;
    }
    int cnt = 0;
    for(map<int,int>::iterator it = mm.begin(); it != mm.end(); it++){
        (*it).yy = ++cnt;
    }
    int res = 0;
    for(int i = n-1; i >= 0; i--){
        diff[i] = mm[ diff[i] ];
        sum[i] = mm[ sum[i] ];
        pp[i] = mp(diff[i], sum[i]);
    }

    sort(pp, pp + n);

    for(int i = n-1; i >= 0; i--){
        dp[i] = query(0, 1, cnt, pp[i].yy, cnt) + 1;
        insert(0, 1, cnt, pp[i].xx, dp[i]);
        res = max(res, dp[i]);
    }

    cout << res << endl;

}