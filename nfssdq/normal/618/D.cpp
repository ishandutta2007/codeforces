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

int ar[200001][2];
vector < int > vc[200001];
int deep = 0;
int dfs(int c, int p){
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        int v = 1 + dfs(vc[c][i], c);
        if(v > ar[c][0]){
            ar[c][1] = ar[c][0];
            ar[c][0] = v;
        } else if(v > ar[c][1]){
            ar[c][1] = v;
        }
    }
    deep = max(deep, ar[c][0] + ar[c][1]);
    return ar[c][0];
}
int dp[200001][2];
int go(int c, int p, int f){
    int &ret = dp[c][f];
    if(ret != -1) return ret;
    ret = 0;

    vector < int > vp;

    int sum = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        go(vc[c][i], c, 0);
        go(vc[c][i], c, 1);
        vp.pb(dp[vc[c][i]][1] - dp[vc[c][i]][0] + 1);
        sum += dp[vc[c][i]][0];
    }

    ret = sum;

    vsort(vp);
    reverse(vp.begin(), vp.end());
    if(vp.size() == 0) return ret;
    if(f == 0){
        ret = max(ret, sum + vp[0]);
        if(vp.size() > 1) ret = max(ret, sum + vp[0] + vp[1]);
    } else {
        ret = max(ret, sum + vp[0]);
    }

    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y; cin >> n >> x >> y;
    REP(i, n-1){
        int a, b; cin >> a >> b;
        vc[a].pb(b);
        vc[b].pb(a);
    }

    if(x < y){
        memset(dp, -1, sizeof dp);
        cout << (LL)(n-1-go(1, 0, 0)) * (LL)y + (LL)go(1, 0, 0) * (LL)x << endl;
    } else if(x > y){
        dfs(1, 0);
        if(deep >= 3) cout << (LL)(n-1) * (LL)y << endl;
        else cout << ((LL)(n-2) * (LL)y) + x << endl;
    } else {
        cout << (LL)(n-1) * (LL)y << endl;
    }
}