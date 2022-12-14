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
#define mod        1000000033ll
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


vector < int > vc[3001];
queue < int >Q;
int dis[3001][3001], mx[2][3001][3], id[2][3001][3];
pair < int, int > pp[3001];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, m){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
    }
    setinf(dis);
    FOR(i, 1, n+1){
        dis[i][i] = 0;
        Q.push(i);
        while(!Q.empty()){
            int c = Q.front();
            Q.pop();

            REP(j, vc[c].size()){
                if(dis[i][vc[c][j]] > 1 + dis[i][c]){
                    dis[i][vc[c][j]] = 1 + dis[i][c];
                    Q.push(vc[c][j]);
                }
            }
        }
    }

    memset(id, -1, sizeof id);
    FOR(i, 1, n+1){
        int cc = 0;
        FOR(j, 1, n+1){
            if(dis[i][j] > 4000 || i == j) continue;
            pp[cc++] = mp(dis[i][j], j);
        }
        sort(pp, pp + cc);
        reverse(pp, pp + cc);
        REP(j, min(cc,3)){
            mx[0][i][j] = pp[j].xx;
            id[0][i][j] = pp[j].yy;
        }
    }

    FOR(i, 1, n+1){
        int cc = 0;
        FOR(j, 1, n+1){
            if(dis[j][i] > 4000 || i == j) continue;
            pp[cc++] = mp(dis[j][i], j);
        }
        sort(pp, pp + cc);
        reverse(pp, pp + cc);
        REP(j, min(cc,3)){
            mx[1][i][j] = pp[j].xx;
            id[1][i][j] = pp[j].yy;
        }
    }

    int res[4], cst = 0;
    FOR(i, 1, n+1){
        FOR(j, 1, n+1){
            if(i == j || dis[i][j] > 4000) continue;
            REP(k, 3){
                if(id[1][i][k] == j || id[1][i][k] == -1) continue;
                REP(l, 3){
                    if(id[0][j][l] == i || id[0][j][l] == id[1][i][k] || id[0][j][l] == -1) continue;
                    if(mx[1][i][k] + mx[0][j][l] + dis[i][j] > cst){
                        cst = dis[i][j] + mx[1][i][k] + mx[0][j][l];
                        res[0] = id[1][i][k]; res[1] = i;
                        res[2] = j; res[3] = id[0][j][l];
                    }
                }
            }
        }
    }
    REP(i, 4) cout << res[i] << " ";
    cout << endl;
}