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

vector < int > vc[200001];
LL dp[200001][3], nxt[200001], pre[200001], val[200001];
LL go(int c, int p){
    LL &ret = dp[c][p];
    if(ret != -1) return ret;
    ret = 0;
    if(p == 0){
        if(nxt[c]) {
            if(vc[c].size() == 0){
                ret = max(ret, go(nxt[c], 0));
                ret = max(ret, go(nxt[c], 1) + val[c]);
            }
            else {
                ret = max(ret, go(nxt[c], 1) + go(vc[c][0], 1));
                ret = max(ret, go(nxt[c], 0) + go(vc[c][0], 0));
                ret = max(ret, go(nxt[c], 1) + go(vc[c][0], 0) + val[c]);
            }
        }
        else if(vc[c].size() > 0) ret = max(ret, go(vc[c][0], 0));
    } else if(p == 1){
        if(nxt[c]) {
            if(vc[c].size() == 0){
                ret = max(ret, go(nxt[c], 1));
                ret = max(ret, go(nxt[c], 0) + val[c]);
            }
            else {
                ret = max(ret, go(nxt[c], 1) + go(vc[c][0], 0));
                ret = max(ret, go(nxt[c], 0) + go(vc[c][0], 1));
                ret = max(ret, go(nxt[c], 0) + go(vc[c][0], 0) + val[c]);
            }
        }
        else if(vc[c].size() > 0) {
            ret = max(ret, go(vc[c][0], 1));
            ret = max(ret, go(vc[c][0], 0) + val[c]);
        }
        else ret = max(ret, val[c]);
    } else {
        if(nxt[c]){
            if(vc[c].size() == 0){
                ret = max(ret, val[c] + go(nxt[c], 2));
            } else {
                ret = max(ret, val[c] + go(nxt[c], 2) + go(vc[c][0], 0));
                ret = max(ret, go(nxt[c], 2) + go(vc[c][0], 2));
            }
        } else if(vc[c].size() > 0){
            ret = max(ret, go(vc[c][0], 2));
            ret = max(ret, val[c] + go(vc[c][0], 0));
        } else ret = max(ret, val[c]);
    }
    return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	REP(i, n){
	    cin >> pre[i] >> val[i+1];
	    if(i)vc[ pre[i] ].pb(i+1);
	}
	FOR(i, 1, n+1){
	    if(vc[i].size() == 0) continue;
        REP(j, vc[i].size() - 1){
            nxt[ vc[i][j] ] = vc[i][j+1];
        }
	}
	memset(dp, -1, sizeof dp);
	cout << go(1, 2) << endl;
}