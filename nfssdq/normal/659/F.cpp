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


LL ar[1001][1001], id[1001][1001];
pair < LL, pair < int, int > > val[1001 * 1001];
int nxt[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int pre[1001*1001], sz[1001 * 1001], on[1011][1011];
int Find(int x){
    if(x == pre[x]) return x;
    return pre[x] = Find(pre[x]);
}

int out[1001][1001];
LL lft;
void dfs(int x, int y, int v){
    out[x][y] = v;
    lft--;
    REP(i, 4){
        int nx = x + nxt[i][0];
        int ny = y + nxt[i][1];
        if(on[nx][ny] == 0 || out[nx][ny] || lft == 0) continue;
        dfs(nx, ny, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; LL K; cin >> n >> m >> K;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            id[i][j] = ++cnt;
            pre[cnt] = cnt;
            sz[cnt] = 1;
            cin >> ar[i][j];
            val[cnt] = mp(ar[i][j], mp(i,j));
        }
    }


    int res = -1, vv;
    sort(val + 1, val + cnt + 1);
    for(int i = cnt; i >= 1; i--){
        on[val[i].yy.xx][val[i].yy.yy] = 1;
        REP(j, 4){
            int x = val[i].yy.xx + nxt[j][0];
            int y = val[i].yy.yy + nxt[j][1];
            if(x <= 0 || x > n || y <= 0 || y > m || on[x][y] == 0) continue;
            int px = Find(id[x][y]), py = Find(id[val[i].yy.xx][val[i].yy.yy]);
            if(px == py) continue;
            pre[px] = py;
            sz[py] += sz[px];
        }

        if(K % val[i].xx) continue;
        if(sz[Find(id[val[i].yy.xx][val[i].yy.yy])] >= (K / val[i].xx)){
            cout << "YES" << endl;

            lft = K / val[i].xx;
            dfs(val[i].yy.xx, val[i].yy.yy, val[i].xx);
            res = 1;
            break;
        }
    }

    if(res == -1){
        cout << "NO" << endl;
        return 0;
    }



    FOR(i, 1, n+1){
        FOR(j, 1, m+1) {
            cout << out[i][j] << " ";
            assert(out[i][j] <= ar[i][j]);
        }
        cout << endl;
    }
}