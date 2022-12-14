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

vector < int > love[100001], hate[100001];
int ar[100001], vis[100001];
void get_out(){
    cout << 0 << endl;
    exit(0);
}
void go(int c, int f){
//    cout << c << " " << f << endl;

    if(f == 1 && ar[c] == -1) get_out();
    if(f == -1 && ar[c] == 1) get_out();
    if(ar[c] != 0) return;
    if(vis[c]) return;

    ar[c] = f;
    vis[c] = 1;
    REP(i, love[c].size()){
        if(f == 0 || f == 1)go(love[c][i], 1);
        else go(love[c][i], -1);
    }
    REP(i, hate[c].size()){
        if(f != -1) go(hate[c][i], -1);
        else go(hate[c][i], 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, m){
        int x, y, v;
        cin >> x >> y >> v;
        if(v == 1) {
            love[x].pb(y);
            love[y].pb(x);
        } else {
            hate[x].pb(y);
            hate[y].pb(x);
        }
    }
    go(1, 0);
    LL res = 1;
    for(int i = 2; i <= n; i++){
        if(vis[i] != 0) continue;
        go(i, 0);
        if(ar[i] == 0) res = (res * 2ll) % mod;
    }
    cout << res << endl;
}