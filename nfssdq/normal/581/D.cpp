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

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
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

int ar[5];
int res[1001][1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    REP(i, 3) ar[i] = i;
    int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int area = x1*y1 + x2*y2 + x3*y3;

    int sq = sqrt(area);
    if(sq * sq != area){
        cout << -1 << endl;
        return 0;
    }
    if(max(x1, max(x2, max(x3, max(y1, max(y2, y3))))) > sq){
        cout << -1 << endl;
        return 0;
    }

    if(x1 != sq && y1 != sq){
        if(x2 != sq && y2 != sq){
            if(x3 != sq && y3 != sq){
                cout << -1 << endl;
                return 0;
            }
            swap(x1, x3); swap(y1, y3);
            swap(ar[0], ar[2]);
        } else {
            swap(x1, x2); swap(y1, y2);
            swap(ar[0], ar[1]);
        }
    }

    if(x1 < y1) swap(x1, y1);
    if(x2 > y2) swap(x2, y2);
    if(x3 > y3) swap(x3, y3);
    if(y2 == sq && y3 == sq && x2 + x3 == sq - y1){
        REP(i, sq) REP(j, y1) res[i][j] = ar[0];
        FOR(j, y1, y1 + x2) REP(i, sq) res[i][j] = ar[1];
        FOR(j, y1 + x2, sq) REP(i, sq) res[i][j] = ar[2];

        cout << sq << endl;
        REP(i, sq) {
            REP(j, sq) cout << (char)(res[i][j] + 'A');
            cout << endl;
        }

        return 0;
    }

    if(x1 != sq) swap(x1, y1);
    if(x2 != sq - y1 && y2 != sq - y1){
        cout << -1 << endl;
        return 0;
    }
    if(x3 != sq - y1 && y3 != sq - y1){
        cout << -1 << endl;
        return 0;
    }
    if(y2 != sq - y1) swap(x2, y2);
    if(y3 != sq - y1) swap(x3, y3);
    if(x2 + x3 != sq){
        cout << -1 << endl;
        return 0;
    }
    REP(i, sq) REP(j, y1) res[i][j] = ar[0];
    FOR(j, y1, sq) REP(i, x2) res[i][j] = ar[1];
    FOR(j, y1, sq) FOR(i, x2, sq) res[i][j] = ar[2];

    cout << sq << endl;
    REP(i, sq) {
        REP(j, sq) cout << (char)(res[i][j] + 'A');
        cout << endl;
    }
}