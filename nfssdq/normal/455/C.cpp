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

int par[300001], res[300001];
int fnd(int x){
    if(par[x] == x) return x;
    return par[x] = fnd(par[x]);
}
void uni(int x, int y){
    int a = fnd(x);
    int b = fnd(y);
    if(a == b) return;
    int c = res[a]; c = (c + 1) / 2;
    int d = res[b]; d = (d + 1) / 2;
    int e = max(res[a], res[b]);
    res[a] = c + d + 1;
    res[a] = max(res[a], e);
    par[b] = a;
}
int vis[300001];
vector < int > vc[300001];
int dfs(int c, int p){
    vis[c] = 1;
    if(p == 0) par[c] = c;
    else par[c] = p;
    int ret = 0;
    int m2 = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] != p) {
            int t = dfs(vc[c][i], c) + 1;
            if(t > ret){
                m2 = ret;
                ret = t;
            } else if(t > m2) m2 = t;
            else if(t == ret) m2 = t;
            res[c] = max(res[c], res[vc[c][i]]);
        }
    }
    res[c] = max(res[c], ret+m2);
    return ret;
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b >> c;
    REP(i, b){
        cin >> d >> e;
        vc[d].pb(e);
        vc[e].pb(d);
    }
    for(int i = 1; i <= a; i++){
        if(vis[i] == 0){
            dfs(i, 0);
        }
    }
    REP(i, c){
        cin >> d >> e;
        if(d == 1){
            f = fnd(e);
            cout << res[f] << endl;
        } else {
            cin >> f;
            uni(e, f);
        }
    }
}