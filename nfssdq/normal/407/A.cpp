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
#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
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

vector < pair < int, int > > v1, v2, v3;

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h,x,y,z;
    cin >> a >> b;
    c = a * a + b * b;
    d = sqrt(c);
    for(int i = 0; i <= d; i++){
        e = c - i * i;
        f = sqrt(e);
        if(f * f == e) v1.pb(mp(i, f));
    }
    for(int i = 0; i <= a; i++){
        e = a * a - i * i;
        f = sqrt(e);
        if(f * f == e) v2.pb(mp(i, f));
    }
    for(int i = 0; i <= b; i++){
        e = b * b - i * i;
        f = sqrt(e);
        if(f * f == e) v3.pb(mp(i, f));
    }
    REP(i, v1.size()){
        if(v1[i].xx == 0 || v1[i].yy == 0)continue;
        REP(j, v2.size()){
            if(v2[j].xx == 0 || v2[j].yy == 0)continue;
            if(v2[j].xx == v1[i].xx || v2[j].yy == v1[i].yy)continue;
            c = (v1[i].xx - v2[j].xx) * (v1[i].xx - v2[j].xx) + (v1[i].yy - v2[j].yy) * (v1[i].yy - v2[j].yy);
            if(c == b * b){
                cout << "YES" << endl;
                cout << 0 << " " << 0 << endl;
                cout << v2[j].xx << " " << v2[j].yy << endl;
                cout << v1[i].xx << " " << v1[i].yy << endl;
                return 0;
            }
        }
    }
    REP(i, v1.size()){
        if(v1[i].xx == 0 || v1[i].yy == 0)continue;
        REP(j, v3.size()){
            if(v3[j].xx == 0 || v3[j].yy == 0)continue;
            if(v3[j].xx == v1[i].xx || v3[j].yy == v1[i].yy)continue;
            c = (v1[i].xx - v3[j].xx) * (v1[i].xx - v3[j].xx) + (v1[i].yy - v3[j].yy) * (v1[i].yy - v3[j].yy);
            if(c == a * a){
                cout << "YES" << endl;
                cout << 0 << " " << 0 << endl;
                cout << v3[j].xx << " " << v3[j].yy << endl;
                cout << v1[i].xx << " " << v1[i].yy << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}