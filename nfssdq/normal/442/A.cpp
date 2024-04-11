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

int ar[6][6], flag[6];

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a;
    REP(i, a){
        string s; cin >> s;
        b = 1, c = 1;
        if(s[0] == 'G') b = 2;
        if(s[0] == 'B') b = 3;
        if(s[0] == 'Y') b = 4;
        if(s[0] == 'W') b = 5;
        c = s[1] - '0';
        ar[b][c]++;
    }
    g = 11;
    REP(i, 1<<5){
        REP(j, 1<<5){
            f = 0;
            FOR(k, 1, 6){
                flag[k] = 0;
                if(i & 1<<(k - 1)){
                    FOR(l, 1, 6){
                        if(ar[k][l] && !(j & 1<<(l - 1))) f++;
                    }
                    if(f == 1) f = 0;
                } else flag[k] = 1;
            }
            e = 0;
            FOR(l, 1, 6){
                d = 0;
                FOR(k, 1, 6){
                    if(flag[k]) d += (ar[k][l] != 0);
                }
                if(j & 1<<(l - 1)){
                    if(d > 1) f += 100;
                } else {
                    if(d == 1) e++;
                    else if(d > 1) f += 100;
                }
            }
            if(e > 1) f += 100;
            f--;
            if(f <= 0) g = min((int)g, __builtin_popcount(i) + __builtin_popcount(j));
        }
    }
    cout << g << endl;
}