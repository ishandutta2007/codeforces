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
#define ALL(A)     A.begin(), A.end()
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

int go(LL m, LL a, LL b, LL c){
    LL ea = a - m, eb = b - m;
    if(ea < 0) return 0;
    if(eb >= 0){
        LL ec = c - m;
        if(ec >= 0) return 1;
        if(-ec > (ea+eb)) return 0;
        return 1;
    }
    eb *= -1;
    if(c >= eb){
        if(ea + c - eb >= m) return 1;
        return 0;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = linf,x,y,z = 0;
    cin >> a >> b >> c;
    if(a < b) swap(a, b);
    if(a < c) swap(a, c);
    if(b < c) swap(b, c);
    LL lo = 0, hi = (a+b+c) / 3, mid = (lo + hi) / 2;
    while(lo < mid){
        if(go(mid, a, b, c)) lo = mid;
        else hi = mid - 1;
        mid = (lo + hi) / 2;
    }
    if(go(mid + 1, a, b, c)) mid++;
    cout << mid << endl;
}