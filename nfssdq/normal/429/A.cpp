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
#define linf       (1<<60)-1
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

vector < int > vc[100001], out;
int ar[100001], fin[100001];
void dfs(int c, int e, int o, int d, int p){
    int b = ar[c]^fin[c];
    if(d == 0){
        if(e != b){
            out.pb(c);
            e ^= 1;
        }
    } else {
        if(o != b){
            out.pb(c);
            o ^= 1;
        }
    }
    REP(i, vc[c].size()){
        if(vc[c][i] != p)dfs(vc[c][i], e, o, d^1, c);
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    REP(i, a - 1){
        cin >> b >> c;
        vc[b].pb(c);
        vc[c].pb(b);
    }
    REP(i, a) cin >> ar[i + 1];
    REP(i, a) cin >> fin[i + 1];
    dfs(1, 0, 0, 0, 0);
    cout << out.size() << endl;
    REP(i, out.size()) cout << out[i] << endl;
}