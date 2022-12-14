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

int dp[1000011][33];
int ar[1000001];

vector < int > prime;
int isp[100001], pr[33], tmp[33], dp1[2][33];
map < int, int > mm;

LL mn[33];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= 100000; i++){
        if(isp[i] == 0){
            prime.pb(i);
            for(int j = i * 2; j <= 100000; j += i) isp[j] = 1;
        }
    }

    int n; LL A, B; cin >> n >> A >> B;
    FOR(i, 1, n+1){
        cin >> ar[i];
    }

    set < int > S;
    int v1 = ar[n], v2 = ar[n]+1, v3 = ar[n]-1;
    for(int i = 0; i < prime.size(); i++){
        while(v1 % prime[i] == 0){
            S.insert(prime[i]);
            v1 /= prime[i];
        }
        while(v2 % prime[i] == 0){
            S.insert(prime[i]);
            v2 /= prime[i];
        }
        while(v3 % prime[i] == 0){
            S.insert(prime[i]);
            v3 /= prime[i];
        }
    }
    if(v1 > 1) S.insert(v1);
    if(v2 > 1) S.insert(v2);
    if(v3 > 1) S.insert(v3);

    int cc = 0;
    for(auto &v: S) pr[++cc] = v;

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= cc; j++){
            if(ar[i]%pr[j] == 0) dp[i][j] = dp[i+1][j];
            else if((ar[i]-1) % pr[j] == 0) dp[i][j] = 1 + dp[i+1][j];
            else if((ar[i]+1) % pr[j] == 0) dp[i][j] = 1 + dp[i+1][j];
            else dp[i][j] = inf;

            dp[i][j] = min(dp[i][j], inf);
        }
    }

    S.clear();
    v1 = ar[1], v2 = ar[1]+1, v3 = ar[1]-1;
    for(int i = 0; i < prime.size(); i++){
        while(v1 % prime[i] == 0){
            S.insert(prime[i]);
            v1 /= prime[i];
        }
        while(v2 % prime[i] == 0){
            S.insert(prime[i]);
            v2 /= prime[i];
        }
        while(v3 % prime[i] == 0){
            S.insert(prime[i]);
            v3 /= prime[i];
        }
    }
    if(v1 > 1) S.insert(v1);
    if(v2 > 1) S.insert(v2);
    if(v3 > 1) S.insert(v3);

    int dd = 0;
    for(auto &v: S) tmp[++dd] = v;
    FOR(i, 1, dd+1) mm[tmp[i]] = i;


    LL res = 1ll<<55;
    setinf(mn);
    FOR(i, 1, cc+1) res = min(res, (LL)dp[1][i] * B);

    int fl = 0;
    for(int i = 1; i <= n; i++){
        FOR(j, 1, cc+1){
            if(i == n) continue;
            res = min(res, (LL)dp[i+1][j] * B + (LL)i * A);
        }

        fl ^= 1;
        for(int j = 1; j <= dd; j++){
            if(ar[i]%tmp[j] == 0) dp1[fl][j] = dp1[fl^1][j];
            else if((ar[i]-1) % tmp[j] == 0) dp1[fl][j] = 1 + dp1[fl^1][j];
            else if((ar[i]+1) % tmp[j] == 0) dp1[fl][j] = 1 + dp1[fl^1][j];
            else dp1[fl][j] = inf;

            dp1[fl][j] = min(dp1[fl][j], inf);

            mn[j] = min(mn[j], (LL)dp1[fl][j]*B - (LL)i*A);
        }

        for(int j = 1; j <= dd; j++){
            res = min(res, (LL)dp1[fl][j] * B + (LL)(n-i) * A);
        }

        for(int j = 1; j <= cc; j++){
            if(i == n) continue;
            int c = mm[ pr[j] ];
            if(c == 0) continue;
            res = min(res, (LL)dp[i+1][j]*B + mn[c] + (LL)(i) * A);
        }
    }


    cout << res << endl;

}
/*
5 3 2
5 11 13 5 6


7
*/