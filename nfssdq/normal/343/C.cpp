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

LL ar[100001], head[100001], n, m;
bool go(LL t){
    int last = 0;
    REP(i, n){
        if(last >= m) return 1;
        if(ar[last] < head[i] && head[i] - ar[last] > t) return 0;
        // first shot
        int l1 = last, l2 = last;
        LL p = 0;
        if(ar[l1] <= head[i]) p += (head[i] - ar[l1]) * 2ll;
        if(p <= t){
            while(l1 < m && ar[l1] <= head[i]) l1++;
            while(l1 < m && p + ar[l1] - head[i] <= t) l1++;
        }
        // second shot
        p = 0;
        if(ar[l2] <= head[i])p = head[i] - ar[l2];
        if(p <= t){
            while(l2 < m && ar[l2] <= head[i]) l2++;
            while(l2 < m && p + (ar[l2] - head[i])*2ll <= t) l2++;
        }
        last = max(l1, l2);
    }
    if(last < m) return 0;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> n >> m;
    REP(i, n) cin >> head[i];
    REP(i, m) cin >> ar[i];
    LL lo = 0, hi = (LL)(1e11), mid = (lo + hi) / 2;
    while(lo < mid){
        if(go(mid)) hi = mid;
        else lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    if(go(mid) == 0) mid++;
    go(mid);
    cout << mid << endl;
}