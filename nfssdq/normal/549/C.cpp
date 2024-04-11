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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    int odd = 0;
    REP(i, n){
        int v; cin >> v;
        if(v % 2) odd++;
    }
    int even = n - odd;
    int stan_move = (n - k + 1) / 2;
    int dan_move = (n - k) /2;
    if(k == n){
        if(odd % 2 == 1) cout << "Stannis" << endl;
        else cout << "Daenerys" << endl;
        return 0;
    }
//    int f = 0;
//        if(dan_move >= odd) f = 1;
//        if(dan_move >= even){
//            if(k % 2 == 0) f = 1;
//        }
//        if(f) cout << "Daenerys" << endl;
//        else cout << "Stannis" << endl;
    if((n-k) % 2 == 0){
        int f = 0;
        if(dan_move >= odd) f = 1;
        else if(dan_move >= even){
            if(k % 2 == 0) f = 1;
        } else f = 1;
        if(f) cout << "Daenerys" << endl;
        else cout << "Stannis" << endl;
    } else {
        int f = 0;
        if(dan_move >= odd) f = 1;
        if(dan_move >= even){
            if(k % 2 == 0) f = 1;
        }
        if(f) cout << "Daenerys" << endl;
        else cout << "Stannis" << endl;
    }
}