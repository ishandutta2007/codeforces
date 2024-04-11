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


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b >> c;
    if(c == 1){
        cout << a << endl;
        cout << 1 << endl;
        cout << a << endl;
        return 0;
    }
    if(c == 2){
        d = 100000000000000ll; e = -1;
        for(LL i = a; i < b; i++){
            f = i ^ (i+1);
            if(f < d){
                d = f;
                e = i;
            }
            if(f == 1) break;
        }
        if(d > a){
            cout << a << endl << 1 << endl << a << endl;
            return 0;
        }
        cout << d << endl;
        cout << 2 << endl;
        cout << e << " " << e+1 << endl;
        return 0;
    }
    if(c == 3){
        for(LL i = a; i <= min(b, a + 100000ll); i++){
            for(int j = 0; j < 50; j++){
                if(i < 1ll<<j) {
                    d = 1ll<<j;
                    break;
                }
            }
            g = 100000000000000ll;
            for(int j = 0; j < 50; j++){
                e = d | 1ll<<j;
                f = i ^ e;
                if(f > e) swap(f, e);
                if(f > i && f < e) g = min(g, e);
            }
            f = i ^ g;
            if(g <= b){
                cout << 0 << endl;
                cout << 3 << endl;
                cout << i << " " << f << " " << g << endl;
                return 0;
            }
        }
        if((a ^ (a+1)) == 1){
            cout << 1 << endl;
            cout << 2 << endl;
            cout << a << " " << a+1 << endl;
        } else {
            cout << 1 << endl;
            cout << 2 << endl;
            cout << a+1 << " " << a+2 << endl;
        }
        return 0;
    }
    if((b - a + 1) >= 10){
        for(LL i = a; i <= b; i++){
            if(i % 4ll == 0){
                cout << 0 << endl;
                cout << 4 << endl;
                cout << i << " " << i+1 << " " << i+2 << " " << i+3 << endl;
                return 0;
            }
        }
    }
    d = 100000000000000ll; e = -1;
    REP(i, 1<<(b - a + 1)){
        if(i == 0) continue;
        if(__builtin_popcount(i) > c) continue;
        f = 0;
        REP(j, (b - a + 1)){
            if(i & 1<<j){
                f ^= (a + (LL)j);
            }
        }
        if(f < d) {
            d = f;
            e = i;
        }
    }
    cout << d << endl;
    cout << __builtin_popcountll(e) << endl;
    REP(i, (b - a + 1)){
        if(e & 1<<i) cout << a + (LL)i << " ";
    }
    cout << endl;
}