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
#define PI         2.0*acos(0.0)
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

LL ar[100001], bit[100001], tmp[100001];
void insert(int x, int v){
    for(int i = x; i <= 100000; i += i & -i) bit[i] += v;
}
int query(int x){
    LL ret = 0;
    for(int i = x; i > 0; i -= i & -i) ret += bit[i];
    return  ret;
}
LL go(LL n, LL m, LL w, LL d){
    FOR(i, 1, n + 1) tmp[i] = ar[i];
    set0(bit);
    for(int i = 1; i <= n; i++){
        tmp[i] += query(i);
        if(tmp[i] >= d) continue;
        LL e = d - tmp[i];
        while(e > 0){
            e--; m--;
            if(m < 0) return 0;
            insert(i, 1); insert(i + w, -1);
        }
    }
    return 1;
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b >> c;
    FOR(i, 1, a + 1) cin >> ar[i];
    LL lo = 1, hi = 2000000000ll, mid = (lo + hi) / 2;
    while(lo < mid){
        e = go(a, b, c, mid);
        if(e == 1)lo = mid;
        else hi = mid - 1;
        mid = (lo + hi) / 2;
    }
    e = go(a, b, c, mid + 1);
    if(e == 1)mid++;
    cout << mid << endl;
}