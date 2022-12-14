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


LL dp[1000001], ar[1000011];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    LL res = 0;

    FOR(i, 1, n+1){
        cin >> ar[i]; ar[i]--;
    }

    FOR(i, 1, n+1){
        res = (res + ar[i]) % mod;
        if(ar[i] < ar[i-1]) res = (res + ar[i] * dp[i-1]) % mod;
        else res = (res + ar[i-1] * dp[i-1]) % mod;

        if(ar[i] < ar[i+1]){
            dp[i] = ar[i];
            if(ar[i] < ar[i-1]){
                dp[i] = (dp[i] + ar[i] * dp[i-1]) % mod;
            } else {
                dp[i] = (dp[i] + ar[i-1] * dp[i-1]) % mod;
            }
        } else {
            dp[i] = ar[i+1];
            if(ar[i+1] < ar[i-1]){
                dp[i] = (dp[i] + ar[i+1] * dp[i - 1]) % mod;
            } else {
                dp[i] = (dp[i] + ar[i-1] * dp[i - 1]) % mod;
            }
        }

    }

    cout << res << endl;


}