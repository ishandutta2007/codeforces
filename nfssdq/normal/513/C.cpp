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

LL ar[5][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) cin >> ar[i][0] >> ar[i][1];
    double res = 0.0;
    for(int i = 1; i <= 10000; i++){
        for(int j = 1; j < (1<<n); j++){
            if(__builtin_popcount(j) == 1) continue;
            REP(k, n){
                if((j & 1<<k) == 0) continue;
                double prob = 1.0;
                REP(l, n){
                    if(j & 1<<l){
                        if(l == k){
                            if(ar[l][1] < i) prob = 0.0;
                            else if(i >= ar[l][0]) prob *= (double)(ar[l][1] - i) / (double)(ar[l][1] - ar[l][0] + 1);
                        } else {
                            if(i < ar[l][0] || ar[l][1] < i) prob = 0.0;
                            else prob *= 1.0 / (double)(ar[l][1] - ar[l][0] + 1);
                        }
                    } else {
                        if(i < ar[l][0]) prob = 0.0;
                        else if(i <= ar[l][1])prob *= (double)(i - ar[l][0]) / (double)(ar[l][1] - ar[l][0] + 1);
                    }
                }
                res += (double)(i) * prob;
            }
            double prob = 1.0;
            REP(l, n){
                if(j & 1<<l){
                    if(i < ar[l][0] || ar[l][1] < i) prob = 0.0;
                    else prob *= 1.0 / (double)(ar[l][1] - ar[l][0] + 1);
                } else {
                    if(i < ar[l][0]) prob = 0.0;
                    else if(i <= ar[l][1])prob *= (double)(i - ar[l][0]) / (double)(ar[l][1] - ar[l][0] + 1);
                }
            }
            res += (double)i * prob;
        }
    }
    cout << fixed << setprecision(10) << res << endl;
}