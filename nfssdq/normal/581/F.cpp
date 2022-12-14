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

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>

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

vector < int > vc[5001];
LL dp[5001][2501][2], sz[5001], down[5001], pre[5001];
int leaf[5001];
void dfs(int c, int p){
    int fl = 0;
    pre[c] = p;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        fl = 1;
        dfs(vc[c][i], c);
        down[c] += down[ vc[c][i] ];
    }
    if(fl == 0) down[c]++;
    if(fl == 0) leaf[c] = 1;
}
int nxt[5001];
LL go(int c, int v, int f){
    LL &ret = dp[c][v][f];
    if(ret != -1) return ret;
    ret = inf;
    if(v > down[c] && nxt[c] == -1) return ret;

    if(leaf[c]){
        if(nxt[c] == -1){
            if(v) ret = min(ret, (LL)(f == 0));
            else ret = min(ret, (LL)(f != 0));
        } else {
            if(v == 0){
                return ret = (f != 0) + go(nxt[c], v, f);
            }
            if(f == 0) ret = min(1 + go(nxt[c], v - 1, f), go(nxt[c], v, f));
            else ret = min(go(nxt[c], v - 1, f), 1 + go(nxt[c], v, f));
        }
        return ret = min(ret, (LL)inf);
    }

    int lo = 0, hi = v;
    if(nxt[c] == -1) lo = v;
    hi = min(hi, (int)down[c]);
    for(int i = lo; i <= hi; i++){
        for(int j = 0; j <= 1; j++){
            LL p = (f != j) + go(vc[c][0], i, j);
            if(nxt[c] != -1) p += go(nxt[c], v - i, f);
            ret = min(ret, p);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    int deg2 = -1;
    FOR(i, 1, n+1){
        if(vc[i].size() > 1){
            deg2 = i;
            break;
        }
    }
    if(deg2 == -1){
        cout << 1 << endl;
        return 0;
    }

    dfs(deg2, 0);
    memset(nxt, -1, sizeof nxt);
    FOR(i, 1, n+1){
        sz[i] = vc[i].size();
        REP(j, vc[i].size()){
            if(vc[i][j] == pre[i]){
                swap( vc[i][j], vc[i][sz[i]-1] );
                sz[i]--;
                break;
            }
        }
        REP(j, sz[i] - 1){
            nxt[ vc[i][j] ] = vc[i][j+1];
        }
    }

    memset(dp, -1, sizeof dp);
    cout << go(deg2, down[deg2]/2, 0) << endl;
}