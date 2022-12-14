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

char pp[3001][3001];
int ar[1001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e = 0,f = 0,g,h = 0,x = 0,y,z;
    cin >> a;
    REP(i, a){
        cin >> ar[i];
        d += ar[i];
    }
    REP(i, 3000) REP(j, 3000) pp[i][j] = ' ';
    e = 10000, f = 1500;
    x = 0, y = 1500;
    REP(i, a){
        if(i % 2 == 0){
            while(ar[i] > 0){
                pp[y--][x++] = '/';
                ar[i]--;
            }
            y++;
            e = min(e, y);
            f = max(f, y);
        } else {
            while(ar[i] > 0){
                pp[y++][x++] = '\\';
                ar[i]--;
            }
            y--;
            e = min(e, y);
            f = max(f, y);
        }
    }
    for(int i = e; i <= f; i++){
        for(int j = 0; j < x; j++) cout << pp[i][j];
        cout << endl;
    }
}