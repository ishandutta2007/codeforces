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
pair < int, pair < int, int > > pp[100001];

int vis[100001], fl;
vector < int > v1, v2;
void dfs(int c, int p){
    vis[c] = p + 1;
    if(p == 0) v1.pb(c);
    else v2.pb(c);
    REP(i, vc[c].size()){
        if(vis[vc[c][i]] == 0) dfs(vc[c][i], p^vp[c][i]);
        if((vis[vc[c][i]]-1) != (p^vp[c][i])) fl = 1;
    }
}

vector < int > res[2];
int go(int n, int m, int f){
    FOR(i, 1, n+1) vc[i].clear(), vp[i].clear();
    set0(vis);
    REP(i, m){
        pp[i].xx ^= f;
        if(pp[i].xx == 0){
            vc[pp[i].yy.xx].pb(pp[i].yy.yy);
            vp[pp[i].yy.xx].pb(1);
            vc[pp[i].yy.yy].pb(pp[i].yy.xx);
            vp[pp[i].yy.yy].pb(1);
        } else {
            vc[pp[i].yy.xx].pb(pp[i].yy.yy);
            vp[pp[i].yy.xx].pb(0);
            vc[pp[i].yy.yy].pb(pp[i].yy.xx);
            vp[pp[i].yy.yy].pb(0);
        }
    }
    fl = 0;
    int tot = 0;
    FOR(i, 1, n+1){
        if(vis[i] == 0){
            v1.clear(); v2.clear();
            dfs(i, 0);
            if(v1.size() > v2.size()) v1 = v2;
            tot += v1.size();
            REP(j, v1.size()) res[f].pb(v1[j]);
        }
    }

    REP(i, m){
        if(pp[i].xx == 1){
            if(vis[pp[i].yy.xx] != vis[pp[i].yy.yy]) fl = 1;
        }
    }

    if(fl == 0) return tot;
    else return mod;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, m){
        int x, y; string s; cin >> x >> y >> s;
        if(s == "B") pp[i] = mp(0, mp(x, y));
        else pp[i] = mp(1, mp(x, y));
    }

    int t1 = go(n, m, 0);
    int t2 = go(n, m, 1);
    if(t1 > n && t2 > n){
        cout << -1 << endl;
        return 0;
    } else if(t1 > t2) res[0] = res[1];
    cout << res[0].size() << endl;
    REP(i, res[0].size()) cout << res[0][i] << " ";
    cout << endl;
}