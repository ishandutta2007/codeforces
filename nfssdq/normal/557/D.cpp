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

vector < int > vc[100001];
pair < int, int > pp[100001];
int col[100001], deg[100001], id[100001], cnt[100001][2];
int dfs(int c, int f, int g){
    col[c] = f;
    int ret = 0;
    id[c] = g;
    if(f == 1) f = 2;
    else f = 1;
    REP(i, vc[c].size()){
        if(col[ vc[c][i] ] == 0)ret |= dfs(vc[c][i], f, g);
        else if(col[vc[c][i]] != f) return 1;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, m; cin >> n >> m;
    REP(i, m){
        cin >> pp[i].xx >> pp[i].yy;
        vc[pp[i].xx].pb(pp[i].yy);
        vc[pp[i].yy].pb(pp[i].xx);
        deg[pp[i].xx]++;
        deg[pp[i].yy]++;
    }
    if(m == 0){
        cout << 3 << " " ;
        LL res = (n * (n-1) * (n-2)) / 6ll;
        cout << res << endl;
        return 0;
    }
    int mx = 0, cnt1 = 0;
    FOR(i, 1, n + 1){
        mx = max(mx, deg[i]);
        if(deg[i] == 1) cnt1++;
    }
    if(mx == 1){
        cnt1 /= 2ll;
        cout << 2 << " ";
        LL res = cnt1 * (n-2);
        cout << res << endl;
        return 0;
    }
    int f = 0, cc = 1;
    FOR(i, 1, n + 1){
        if(col[i] == 0){
            f |= dfs(i, 1, cc++);
        }
    }
    if(f){
        cout << 0 << " " << 1 << endl;
        return 0;
    }
    cout << 1 << " ";
    LL res = 0;
    FOR(i, 1, n + 1) {
        cnt[id[i]][col[i]-1]++;
    }
    FOR(i, 1, cc){
        if(cnt[i][0]+cnt[i][1] >= 3) {
            res += ((LL)cnt[i][0] * (LL)(cnt[i][0]-1)) / 2ll;
            res += ((LL)cnt[i][1] * (LL)(cnt[i][1]-1)) / 2ll;
        }
    }
    cout << res << endl;
}