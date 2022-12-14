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

vector < LL > vc;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    vc.pb(0);
    FOR(i, 1, 10){
        REP(j, 1<<i){
            a = 0;
            REP(k, i){
                a *= 10;
                if(j & 1<<k) a += 7;
                else a += 4;
            }
            vc.pb(a);
        }
    }
    vc.pb(1e9);
    vsort(vc);
    LL pl, pr, vl, vr;
    cin >> pl >> pr >> vl >> vr >> a;
    if(pl == pr && vl == vr)
    f = 0;
    LL tot = (pr - pl + 1) * (vr - vl + 1);
    FOR(i, 1, vc.size() - 1){
        if(i + a >= vc.size()) break;
        b = vc[i], c = vc[i + a - 1];
        g = h = 0;
        if(b >= vl && vc[i-1] < vr && c <= pr && vc[i+a] > pl){
            g = (min(b,vr) - max(vl, vc[i-1]+1) + 1) * (min(pr, vc[i+a]-1) - max(c,pl) + 1);
        }
        if(b >= pl && vc[i-1] < pr && c <= vr && vc[i+a] > vl){
            h = (min(b,pr) - max(pl, vc[i-1]+1) + 1) * (min(vr, vc[i+a]-1) - max(c,vl) + 1);
        }
        f += g + h;
        if(g && h && a == 1) f--;
    }
    cout << fixed << setprecision(10) << (double)f/(double)tot << endl;
}