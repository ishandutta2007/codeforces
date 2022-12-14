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


LL dp[1<<20], vis[1<<20], ar[100], action[20][2], n;
LL go(LL bp){
    LL c = __builtin_popcount(bp);
    if(c == n) return 0;
    if(vis[bp]) return dp[bp];
    vis[bp] = 1;
    if(action[c][1] == 1){
        dp[bp] = -30000000;
        if(action[c][0] == 0){
            REP(i, n){
                if(bp & 1<<i) continue;
                dp[bp] = max(dp[bp], ar[i] + go(bp | 1<<i));
            }
        } else {
            REP(i, n){
                if(bp & 1<<i) continue;
                dp[bp] = max(dp[bp], go(bp | 1<<i));
            }
        }
    } else {
        dp[bp] = 30000000;
        if(action[c][0] == 0){
            REP(i, n){
                if(bp & 1<<i) continue;
                dp[bp] = min(dp[bp], -ar[i] + go(bp | 1<<i));
            }
        } else {
            REP(i, n){
                if(bp & 1<<i) continue;
                dp[bp] = min(dp[bp], go(bp | 1<<i));
            }
        }
    }
    return dp[bp];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    string s;
    cin >> a;
    REP(i, a) cin >> ar[i];
    sort(ar, ar + a);
    reverse(ar, ar + a);
    cin >> a; n = a;
    REP(i, a){
        cin >> s >> action[i][1];
        if(s == "p") action[i][0] = 0;
        else action[i][0] = 1;
    }
    set0(vis);
    cout << go(0) << endl;
}