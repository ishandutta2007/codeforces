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

int dp[1<<17][101], ar[101], isp[60];
vector < int > primes, vc[1<<17];
int pc[101], pre[1<<17][101];
int go(int bp, int c){
    if(c == 0)return 0;
    int &ret = dp[bp][c];
    if(ret != -1) return ret;
    ret = 70000;
    for(int i = 1; i <= 60; i++){
        if((bp & pc[i]) != 0) continue;
        int a = abs(ar[c] - i) + go(bp | pc[i], c - 1);
        if(a < ret){
            ret = a;
            pre[bp][c] = i;
        }
    }
    return ret;
}
int res[101];
void print(int bp, int c){
    if(c == 0) return;
    res[c] = pre[bp][c];
    print(bp | pc[pre[bp][c]], c - 1);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> a;
    REP(i, a) cin >> ar[i + 1];
    for(int i = 2; i <= 60; i++){
        if(isp[i] == 0){
            primes.pb(i);
            for(int j = i * 2; j <= 60; j += i) isp[j] = 1;
        }
    }
    for(int i = 2; i <= 60; i++){
        for(int j = 0; j < primes.size(); j++){
            if(i % primes[j] == 0) pc[i] |= 1<<j;
        }
    }
    REP(i, 1<<17){
        for(int j = 1; j <= 60; j++) if((i & pc[j]) == 0) vc[i].pb(j);
    }
    for(int i = 1; i <= a; i++){
        for(int j = 0; j < 1<<17; j++){
            dp[j][i] = 70000;
            REP(k, vc[j].size()){
                c = vc[j][k];
                if((j & pc[c]) != 0) continue;
                b = abs(ar[i] - c) + dp[j | pc[c]][i - 1];
                if(b < dp[j][i]){
                    dp[j][i] = b;
                    pre[j][i] = c;
                }
            }
        }
    }
    print(0, a);
    for(int i = 1; i <= a; i++) cout << res[i] << " " ;
    cout << endl;
}