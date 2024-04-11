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

vector < int > nxt[1<<13], vc[14];
vector < pair < int, int > > vp[14];
LL dp[14][1<<13][2];
int n, ar[14][14], ok[14][1<<13];
LL go(int c, int bp, int f){
    if(f == 0){
        REP(i, vp[c].size()){
            if((bp & 1<<vp[c][i].xx) == 0 && vp[c][i].xx != c) return 0;
            if((bp & 1<<vp[c][i].yy) == 0 && vp[c][i].yy != c) return 0;
        }
    }
    if(bp == 0) return 1;
    LL &ret = dp[c][bp][f];
    if(ret != -1) return ret;
    ret = 0;

    REP(i, nxt[bp].size()){
        int p = nxt[bp][i], cc = -1, last = -1;
        if(ok[c][p] == 0) continue;
        REP(j, n){
            if(bp & 1<<j) last = j;
            if((p & 1<<j) && ar[c][j]){
                if(cc == -1) cc = j;
                else cc = -2;
            }
        }
        if(cc == -2) continue;
        if((p & 1<<last) == 0) continue;
        if(cc == -1){
            REP(j, n){
                if(p & 1<<j) ret += go(j, p ^ (1<<j), 0) * go(c, bp ^ p, 1);
            }
        } else {
            ret += go(cc, p ^ (1<<cc), 0) * go(c, bp ^ p, 1);
        }
    }


//    cout << c << " " << bp << " " << ret << endl;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cnt = 0;
    REP(i, 1<<13){
        FOR(j, 1, i+1){
            if((i & j) == j) nxt[i].pb(j);
        }
    }

    int m, q; cin >> n >> m >> q;
    REP(i, m){
        int x, y; cin >> x >> y;
        vc[x-1].pb(y-1);
        vc[y-1].pb(x-1);
        ar[x-1][y-1] = ar[y-1][x-1] = 1;
    }

    REP(i, q){
        int x, y, v; cin >> x >> y >> v;
        x--; y--; v--;
        vp[v].pb(mp(x, y));
    }

    REP(i, n){
        REP(j, 1<<n){
            if(j & 1<<i) continue;

            int fl = 1;
            REP(k, n){
                if((j & 1<<k) == 0) continue;
                REP(l, vc[k].size()){
                    if((j & 1<<vc[k][l]) == 0 && vc[k][l] != i) fl = 0;
                }
                if(fl == 0)break;
            }
            REP(l, vp[i].size()){
                if((j & 1<<vp[i][l].xx) && (j & 1<<vp[i][l].yy)) fl = 0;
            }

            ok[i][j] = fl;
//            if(fl) cout << i << " " << j << endl;
        }
    }

    memset(dp, -1, sizeof dp);
    cout << go(0, ((1<<(n-1))-1)<<1, 0) << endl;
}