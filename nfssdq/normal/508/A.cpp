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

LL ar[1001][1001];

int main() {
    ios_base:: sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b >> c;
    REP(ts, c){
        cin >> d >> e;
        ar[d][e] = 1;
        f = 0;
        for(int i = d - 1; i <= d; i++){
            for(int j = e - 1; j <= e; j++){
                if(i < 1) break;
                if(j < 1) break;
                f += ar[i][j];
            }
        }
        if(f == 4){
            cout << ts+1 << endl;
            return 0;
        }
        f = 0;
        for(int i = d - 1; i <= d; i++){
            for(int j = e; j <= e+1; j++){
                if(i < 1) break;
                if(j > b) break;
                f += ar[i][j];
            }
        }
        if(f == 4){
            cout << ts+1 << endl;
            return 0;
        }
        f = 0;
        for(int i = d; i <= d+1; i++){
            for(int j = e - 1; j <= e; j++){
                if(i > a) break;
                if(j < 1) break;
                f += ar[i][j];
            }
        }
        if(f == 4){
            cout << ts+1 << endl;
            return 0;
        }
        f = 0;
        for(int i = d; i <= d + 1; i++){
            for(int j = e; j <= e + 1; j++){
                if(i > a) break;
                if(j > b) break;
                f += ar[i][j];
            }
        }
        if(f == 4){
            cout << ts+1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}