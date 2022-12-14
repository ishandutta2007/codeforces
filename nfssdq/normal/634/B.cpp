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

LL dp[52][2][2][2], ar[2][52];

LL go(int c, int car, int f1, int f2){
    if(c == 51){
        if(car == 0 && f1 && f2) return 1;
        return 0;
    }
    LL &ret = dp[c][car][f1][f2];
    if(ret != -1) return ret;
    ret = 0;


    REP(i, 2){
        REP(j, 2){
            if((i ^ j) != ar[1][c]) continue;
            int v = i+j+car;
            int pv = v % 2;
            int tv = v / 2;
            if(pv != ar[0][c]) continue;

            ret += go(c + 1, tv, f1|i, f2|j);
        }
    }


    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof dp);
    LL S, X; cin >> S >> X;
    REP(i, 52){
        if(S & (1ll<<i)) ar[0][i] = 1;
        if(X & (1ll<<i)) ar[1][i] = 1;
    }

    LL v = go(0, 0, 0, 0);
    cout << v << endl;
}