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

LL ar[111][100011], val[100001], fact[100001], inv[100001];
LL ncr(LL N, LL R){
    LL p =(fact[N] * ((inv[R]*inv[N-R])%mod)) % mod;
    return p;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    fact[0] = 1;
    FOR(i, 1, 100001) fact[i] = (fact[i - 1] * i) % mod;
    REP(i, 100001) inv[i] = modinverse(fact[i], mod);
    cin >> a >> b;
    FOR(i, 1, a + 1) cin >> val[i];
    REP(i, b){
        cin >> c >> d >> e;
        ar[e][c]++;
        for(int j = e; j >= 0; j--){
            ar[j][d + 1] = (ar[j][d + 1] - ncr(d - c + e - j, e - j) + mod) % mod;
        }
    }
    for(int i = 100; i >= 0; i--){
        FOR(j, 1, a + 1){
            ar[i][j] = (ar[i][j] + ar[i + 1][j] + ar[i][j - 1]) % mod;
        }
    }
    FOR(i, 1, a + 1){
        cout << (ar[0][i] + val[i])%mod << " ";
    }
    cout << endl;
}