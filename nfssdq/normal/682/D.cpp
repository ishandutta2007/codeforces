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

int dp[1001][1001][11][2], vis[1001][1001][11][2];
string S, T;
int go(int x, int y, int k, int f){
    if(x < 0 || y < 0){
        if(k == 0) return 0;
        return -10000;
    }
    int &ret = dp[x][y][k][f];
    if(vis[x][y][k][f]) return ret;
    vis[x][y][k][f] = 1;

    ret = -10000;
    ret = max(ret, go(x - 1, y, k, 0));
    ret = max(ret, go(x, y - 1, k, 0));
    if(S[x] == T[y]){
        if(f) ret = max(ret, 1 + go(x-1, y-1, k, 1));
        if(k)ret = max(ret, 1 + go(x - 1, y - 1, k - 1, 1));
    }

    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    cin >> S >> T;
    cout << go(n-1, m-1, k, 0) << endl;
}