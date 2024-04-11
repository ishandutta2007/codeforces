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
#define ALL(A)     A.begin(), A.end()
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

vector < int > vc[301];
LL in[301], out[301], vis[301], cost[301];
LL ar[401], cc;
void dfs(int c){
    vis[c] = 1;
    ar[cc++] = c;
    REP(i, vc[c].size()){
        if(vis[vc[c][i]] == 0) dfs(vc[c][i]);
    }
}
LL dp[100001][301];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b >> c;
    FOR(i, 1, a + 1) cin >> cost[i];
    REP(i, b){
        cin >> d >> e;
        vc[d].pb(e);
        in[e]++; out[d]++;
    }
    FOR(i, 1, a + 1){
        if(in[i] == 0){
            cc = 0;
            dfs(i);
            for(int j = cc-2; j >= 0; j--){
                c -= cost[ar[j]] * (cc - j - 1);
            }
            for(int j = 1; j < cc; j++) cost[ar[j]] += cost[ar[j-1]];
        }
    }
    if(c < 0){
        cout << 0 << endl;
        return 0;
    }
    FOR(i, 1, a + 1){
        if(vis[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    REP(i, a+1) dp[0][i] = 1;
    FOR(i, 1, c + 1){
        FOR(j, 1, a + 1){
            if(cost[j] <= i)dp[i][j] += dp[i - cost[j]][j];
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[c][a] << endl;
}