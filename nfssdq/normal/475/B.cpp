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

//#include <bits/stdc++.h>
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

string s1, s2;
int ar[21][21], X[21], Y[21], id[21][21], vis[500];
vector < int > vc[21*21];
void dfs(int c){
    vis[c] = 1;
    REP(i, vc[c].size()){
        if(vis[vc[c][i]] == 0) dfs(vc[c][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b;
    cin >> s1 >> s2;
    REP(i, a) {
        if(s1[i] == '>') X[i] = 1;
    }
    REP(i, b){
        if(s2[i] == 'v') Y[i] = 1;
    }
    REP(i, a) REP(j, b) id[i][j] = d++;
    REP(i, a){
        REP(j, b){
            if(X[i] == 1 && j < b - 1) {
                vc[id[i][j]].pb(id[i][j+1]);
            } else if(X[i] == 0 && j > 0){
                vc[id[i][j]].pb(id[i][j - 1]);
            }
            if(Y[j] == 1 && i < a - 1) {
                vc[id[i][j]].pb(id[i + 1][j]);
            } else if(Y[j] == 0 && i > 0){
                vc[id[i][j]].pb(id[i - 1][j]);
            }
        }
    }
    REP(i, a){
        REP(j, b){
            set0(vis);
            dfs(id[i][j]);
            REP(k, a){
                REP(l, a){
                    if(vis[id[k][l]] == 0){
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
}