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


vector < int > vp[1000001][2];
int vc[1000001][2];
void printAndExit(){
    cout << "IMPOSSIBLE" << endl;
    exit(0);
}
int go(int c, int l, int r){

    int mn = r+1, mx = 0;

    REP(i, vp[c][1].size()) mn = min(mn, vp[c][1][i]);
    REP(i, vp[c][1].size()) l = max(l, vp[c][1][i]);
    REP(i, vp[c][0].size()) mx = max(mx, vp[c][0][i]);

    if(mx >= mn) printAndExit();

    int last = c;
    if(mx > c){
        last = go(c + 1, mx, r);
        vc[c][0] = c + 1;
    }
    REP(i, vp[c][1].size()){
        if(vp[c][1][i] <= last) printAndExit();
    }

    if(last >= l && vp[c][1].size() == 0) return last;

    vc[c][1] = last + 1;
    return go(last + 1, l, r);
}
void dfs(int c){
    if(vc[c][0] != -1) dfs(vc[c][0]);
    cout << " " << c;
    if(vc[c][1] != -1) dfs(vc[c][1]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, c;
    cin >> n >> c;
    REP(i, c){
        int a,b; string s;
        cin >> a >> b >> s;

        if(a >= b){
            printAndExit();
        }

        if(s == "LEFT") vp[a][0].pb(b);
        else vp[a][1].pb(b);
    }

    memset(vc, -1, sizeof vc);

    go(1, n, n);
    dfs(1);
}