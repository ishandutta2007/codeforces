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

int ar[1001][1001];
int cnt[1001][1001];
int bit[1<<15 + 1], M = (1<<15) - 1;
int popcount(int a){
    return bit[a&M]+bit[(a>>15)&M];
}
int go(int a, int b, int mid){
    set0(cnt);
    int nl = 1161/30;
    REP(i, a){
        REP(j, b){
            if(ar[i][j] >= mid) cnt[i][j/30] |= 1<<(j%30);
        }
    }
    REP(i, a){
        REP(j, i){
            int f = 0;
            REP(k, nl) f += popcount(cnt[i][k]&cnt[j][k]);
            if(f > 1) return 1;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    REP(i, 1<<15) bit[i] = __builtin_popcount(i);
    cin >> a >> b;
    REP(i, a) REP(j, b) cin >> ar[i][j];
    LL lo = 0, hi = 1e9 + 10, mid = (lo + hi) / 2;
    while(lo < mid){
        set0(cnt);
        int nl = 1061/30;
        REP(i, a){
            REP(j, b){
                if(ar[i][j] >= mid) cnt[i][j/30] |= 1<<(j%30);
            }
        }
        g = 0;
        REP(i, a){
            REP(j, i){
                f = 0;
                REP(k, nl) f += popcount(cnt[i][k]&cnt[j][k]);
                if(f > 1){
                    g = 1;
                    goto pp;
                }
            }
        }
        pp:
        if(g) lo = mid;
        else hi = mid - 1;
        mid = (lo + hi) / 2;
    }
    if(go(a, b, mid + 1)) mid++;
    cout << mid << endl;
}