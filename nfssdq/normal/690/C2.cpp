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

vector < int > vc[100001];
int mx[100001][2], res = 0;
int dfs(int c, int p){
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        int v = 1 + dfs(vc[c][i], c);
        if(v > mx[c][0]){
            mx[c][1] = mx[c][0];
            mx[c][0] = v;
        } else if(v > mx[c][1]) mx[c][1] = v;
    }
    res = max(res, mx[c][0] + mx[c][1]);
    return mx[c][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;cin >> n >> m;
    assert(m == n-1);
    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    dfs(1, 0);
    cout << res << endl;
}