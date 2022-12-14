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

LL ar[100001][5], tp[5], out[5];
LL seg[400001][5];
void insert(int idx, int s, int e, int p){
    if(s == e){
        REP(i, 5) seg[idx][i] = ar[s][i];
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p);
    else insert(idx * 2 + 2, mid + 1, e, p);
    REP(i, 5) seg[idx][i] = max(seg[idx * 2 + 1][i], seg[idx * 2 + 2][i]);
}
void query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed){
        REP(i, 5) tp[i] = max(tp[i], seg[idx][i]);
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
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, m, k;
    cin >> n >> m >> k;
    REP(i, n) REP(j, m) cin >> ar[i][j];
    REP(i, n){
        insert(0, 0, n - 1, i);
    }
    int r = -1, mx = 0;
    REP(i, n){
        r = max(r, i);
        for(int j = r; j < n; j++){
            set0(tp);
            query(0, 0, n - 1, i, j);
            LL sum = 0; REP(K, 5) sum += tp[K];
            if(sum <= k) {
                if(j-i+1 > mx){
                    mx = j - i + 1;
                    REP(K, 5) out[K] = tp[K];
                }
                r = j;
            } else break;
        }
    }
    REP(i, m) cout << out[i] << " ";
    cout << endl;
}