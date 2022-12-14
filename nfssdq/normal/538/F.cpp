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

int ar[200001], seg[20][300001];
void insert(int s, int e, int p, int v, int d){
    seg[d][p] = v;
    if(s == e) {
        return;
    }
    if(p == e){
        sort(seg[d] + s, seg[d] + e + 1);
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(s, mid, p, v, d + 1);
    else insert(mid + 1, e, p, v, d + 1);
}
int query(int d, int s, int e, int st, int ed, int v){
    if(s == st && e == ed){
        return lower_bound(seg[d]+s, seg[d] + e + 1, v) - seg[d]-s;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) return query(d + 1, s, mid, st, ed, v);
    else if(st > mid) return query(d + 1, mid + 1, e, st, ed, v);
    else return query(d+1, s, mid, st, mid, v)+query(d+1,mid+1,e,mid+1,ed,v);
}
LL res[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) {
        cin >> ar[i+1];
        insert(1, n, i+1, ar[i+1], 0);
    }
    LL cnt = 0;
    for(LL i = 1; i <= n; i++){
        for(LL j = 1; j < n; j++){
            LL l = j*(i-1)+2, r = j*i + 1;
            if(r > n) r = n;
            if(l > n) break;
            res[j] += query(0, 1, n, l, r, ar[i]);
        }
    }
    FOR(j, 1, n) cout << res[j] << " ";
    cout << endl;

}