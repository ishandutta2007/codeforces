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

int dis[4][1001][1001], n, m; ;
queue < pair < int, int > > Q;
char pp[1011][1011];
int nxt[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
void go(int c){
    while(!Q.empty()) Q.pop();
    REP(i, n){
        REP(j, m) if(pp[i][j] == '0'+c) {
            dis[c][i][j] = 0;
            Q.push(mp(i, j));
        }
    }

    while(!Q.empty()){
        pair < int, int > p = Q.front();
        Q.pop();

        REP(i, 4){
            int x = p.xx + nxt[i][0], y = p.yy + nxt[i][1];
            if(x < 0 || x >= n || y < 0 || y >= m || pp[x][y] == '#') continue;
            if(dis[c][x][y] <= dis[c][p.xx][p.yy]+1) continue;
            dis[c][x][y] = dis[c][p.xx][p.yy]+1;
            Q.push(mp(x, y));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    REP(i, n) cin >> pp[i];

    setinf(dis);
    go(1); go(2); go(3);

    int res = inf;
    FOR(i, 1, 4){
        int dd[4]; setinf(dd);
        dd[i] = 1;
        REP(j, n){
            REP(k, m){
                if(pp[j][k] >= '1' && pp[j][k] <= '3' && pp[j][k] != '0'+i)
                    dd[pp[j][k]-'0'] = min(dd[pp[j][k]-'0'], dis[i][j][k]);
            }
        }

        LL sum = 0;
        FOR(j, 1, 4) sum += dd[j] - 1;
        if(sum < res) res = sum;
    }

    REP(i, n){
        REP(j, m){
            if(pp[i][j] != '.') continue;
            LL sum = 1;
            FOR(k, 1, 4){
                sum += dis[k][i][j] - 1;
            }
            if(sum < res) res = sum;
        }
    }

    if(res > 10000000) cout << -1 << endl;
    else cout << res << endl;

}