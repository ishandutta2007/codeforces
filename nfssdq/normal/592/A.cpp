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

char pp[10][10];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    REP(i, 8) cin >> pp[i];
    int cW = inf, cB = inf;
    REP(i, 8){
        REP(j, 8){
            if(pp[i][j] == 'W'){
                int p = i, fl = 0;
                while(p > 0){
                    p--;
                    if(pp[p][j] != '.') fl = 1;
                }
                if(fl == 0) cW = min(cW, i);
            } else if(pp[i][j] == 'B'){
                int p = i, fl = 0;
                while(p < 7){
                    p++;
                    if(pp[p][j] != '.') fl = 1;
                }
                if(fl == 0) cB = min(cB, 7-i);
            }
        }
    }

    if(cW <= cB) cout << "A" << endl;
    else cout << "B" << endl;
}