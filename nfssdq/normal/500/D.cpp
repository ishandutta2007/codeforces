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

vector < int > vc[100001], vp[100001];
LL dis[100001], sum[100001], sz[100001], pre[100001];
double ss = 0;
void dfs(int c, int p, LL d){
    dis[c] = p;
    pre[c] = p;
    REP(i, vc[c].size()){
        if(vc[c][i] != p) {
            dfs(vc[c][i], c, d + vp[c][i]);
            LL cc = vp[c][i] * sz[ vc[c][i] ] + sum[ vc[c][i] ];
            ss += cc*sz[c] + sum[c]*sz[ vc[c][i] ];
            sum[c] += cc;
            sz[c] += sz[ vc[c][i] ];
        }
    }
    ss += sum[c];
    sz[c]++;
}
LL ar[100001][3];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 0,x = 1,y,z;
    cin >> a;
    REP(i, a - 1){
        cin >> b >> c >> d;
        ar[i][0] = b; ar[i][1] = c; ar[i][2] = d;
        vc[b].pb(c);
        vc[c].pb(b);
        vp[b].pb(d);
        vp[c].pb(d);
    }
    dfs(1, 0, 0);
    double nc3 = (double)(a * (a - 1)) / 6.0;
    cin >> b;
    REP(i, b){
        cin >> c >> d; c--;
        LL p = ar[c][2] - d;
        ar[c][2] = d;
        if(pre[ ar[c][1] ] != ar[c][0]) swap(ar[c][1], ar[c][0]);
        x = sz[1] - sz[ar[c][1] ];
        y = sz[ar[c][1]];
        ss -= p*x*y;
        double res = (double)ss / nc3;
        cout << fixed << setprecision(10) << res << endl;
    }
}