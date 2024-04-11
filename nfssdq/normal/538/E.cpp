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

int leaf = 0;
vector < int > vc[200001];
int sz[200001];
void dfs1(int c, int p){
    int cnt = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        dfs1(vc[c][i], c);
        cnt++;
        sz[c] += sz[ vc[c][i] ];
    }
    if(!cnt) {
        leaf++;
        sz[c] = 1;
    }
}
int dfs2(int c, int p, int h){
    vector < int > tmp;
    int cnt = 0;
    REP(i, vc[c].size()) if(vc[c][i] != p) cnt++;
    if(cnt == 0) return 1;
    if(h == 0){
        int ret = 0;
        REP(i, vc[c].size()){
            if(vc[c][i] == p) continue;
            tmp.pb(sz[vc[c][i]] - dfs2(vc[c][i], c, 1));
        }
        vsort(tmp);
        return sz[c] - tmp[0];
    } else {
        int ret = 0;
        REP(i, vc[c].size()){
            if(vc[c][i] == p) continue;
            tmp.pb(sz[ vc[c][i] ] - dfs2(vc[c][i], c, 0));
        }
        vsort(tmp);
        REP(i, tmp.size()) ret += tmp[i] + 1;
        return sz[c] - (ret - 1);
    }
}
int dfs3(int c, int p, int h){
    vector < int > tmp;
    int cnt = 0;
    REP(i, vc[c].size()) if(vc[c][i] != p) cnt++;
    if(cnt == 0) return 1;
    if(h == 0){
        int ret = 0;
        REP(i, vc[c].size()){
            if(vc[c][i] == p) continue;
            tmp.pb(dfs3(vc[c][i], c, 1));
        }
        vsort(tmp);
        REP(i, tmp.size()) ret += tmp[i];
        return ret;
    } else {
        int ret = 0;
        REP(i, vc[c].size()){
            if(vc[c][i] == p) continue;
            tmp.pb(dfs3(vc[c][i], c, 0));
        }
        vsort(tmp);
        return tmp[0];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    dfs1(1, 0);

    cout << dfs2(1, 0, 0) << " " << dfs3(1, 0, 0) << endl;

}