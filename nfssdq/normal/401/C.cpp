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
    LL a = 0,b = 0,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    if(a > b + 1){
        cout << -1 << endl;
        return 0;
    }
    if(b > 2*a + 2){
        cout << -1 << endl;
        return 0;
    }
    if(a >= b){
        while(a > 0 && b > 0){
            cout << "01";
            a--; b--;
        }
        if(a > 0)cout << "0" << endl;
        return 0;
    }
    if(b >= 2*a){
        REP(i, a)cout << "110";
        b -= 2*a;
        REP(i, b)cout << "1";
        return 0;
    }
    c = b % a;
    REP(i, c){
        cout << "110";
    }
    for(int i = c; i < a; i++)cout << "10";
}