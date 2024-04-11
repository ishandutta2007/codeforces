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
#include<unordered_set>

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

#define MX 2
LL MODSQ = mod*mod;
LL mul_res[MX][MX];
void multiply(LL a[][MX], LL b[][MX]){
    set0(mul_res);
    for(int i = 0; i < MX; i++){
        for(int j = 0; j < MX; j++){
            for(int k = 0; k < MX; k++){
                mul_res[i][j] = (mul_res[i][j] + a[i][k] * b[k][j]);
        		if(mul_res[i][j] >= MODSQ) mul_res[i][j] -= MODSQ;
        	}
        	mul_res[i][j] %= mod;
        }
    }
}

LL big_res[MX][MX];
LL init[MX][MX];
void matrix_expo(LL n){
    if(n == 0){
        set0(big_res);
        REP(i, MX)big_res[i][i] = 1;
        return;
    }
    if(n % 2 == 0){
        matrix_expo(n / 2);
        multiply(big_res, big_res);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
    else {
        matrix_expo(n - 1);
        multiply(big_res, init);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    init[0][0] = 0; init[0][1] = 2;
    init[1][0] = 1; init[1][1] = 1;
    int n; cin >> n;
    REP(i, n){
        LL x; cin >> x;
        matrix_expo(x);
        REP(j, 2) REP(k, 2) init[j][k] = big_res[j][k];
    }
    LL v1 = (big_res[0][0] * modinverse(2ll, mod)) % mod;
    LL v2 = (big_res[0][0] + big_res[0][1]) % mod;
    v2 = (v2 * modinverse(2ll, mod)) % mod;
    cout << v1 << "/" << v2 << endl;
}