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

int nxt[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
char pp[2001][2001];
int vis[2001][2001], n, m, cid[2001][2001];
void dfs(int x, int y, int v){
    vis[x][y] = 1;
    cid[x][y] = v;

    REP(i, 4){
        int cx = x + nxt[i][0];
        int cy = y + nxt[i][1];
        if(cx < 0 || cx >= n || cy < 0 || cy >= m || pp[cx][cy] == '*' || vis[cx][cy]) continue;
        dfs(cx, cy, v);
    }
}

int pre[2001*2001];
int Find(int x){
    if(x == pre[x]) return x;
    return pre[x] = Find(pre[x]);
}
int Union(int x, int y){
    int px = Find(x);
    int py = Find(y);

    if(px == py) return 0;

    pre[py] = px;

    return 1;
}

int vis1[2001*2001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    REP(i, n){
        cin >> pp[i];
    }

    int cnt = 0;
    REP(i, n){
        REP(j, m){
            if(pp[i][j] == '*' || vis[i][j]) continue;
            dfs(i, j, ++cnt);
        }
    }


    FOR(i, 1, cnt+1) pre[i] = i;

    set0(vis);

    queue < pair<int,int> > Q;
    REP(i, n){
        REP(j, m){
            vector < int > vc;
            if(pp[i][j] == '.') continue;
            REP(k, 4){
                int cx = i + nxt[k][0];
                int cy = j + nxt[k][1];
                if(cx < 0 || cx >= n || cy < 0 || cy >= m || pp[cx][cy] == '*') continue;
                vc.pb(Find(cid[cx][cy]));
            }
            vsort(vc);
            FOR(k, 1, vc.size()){
                if(vc[k] == vc[k-1]){
                    cid[i][j] = vc[k];
                    Q.push(mp(i, j));
                    vis[i][j] = 1;
                    break;
                }
            }
        }
    }

    while(!Q.empty()){
        pair<int,int> p = Q.front();
        Q.pop();

        pp[p.xx][p.yy] = '.';
        REP(i, 4){
            int x = p.xx + nxt[i][0];
            int y = p.yy + nxt[i][1];
            if(x < 0 || x >= n || y < 0 || y >= m || pp[x][y] == '*') continue;
            Union(cid[p.xx][p.yy], cid[x][y]);
//            cout << cid[p.xx][p.yy] << " " << cid[x][y] << endl;
        }
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int x = p.xx + i;
                int y = p.yy + j;
                if(x < 0 || x >= n || y < 0 || y >= m || pp[x][y] == '.' || vis[x][y]) continue;
                vector < int > vc;
                REP(k, 4){
                    int cx = x + nxt[k][0];
                    int cy = y + nxt[k][1];
                    if(cx < 0 || cx >= n || cy < 0 || cy >= m || pp[cx][cy] == '*') continue;
                    vc.pb(Find(cid[cx][cy]));
                }
                vsort(vc);
                FOR(k, 1, vc.size()){
                    if(vc[k] == vc[k-1]){
                        cid[x][y] = vc[k];
                        Q.push(mp(x, y));
                        vis[x][y] = 1;
                    }
                }
            }
        }

    }

    REP(i, n) cout << pp[i] << endl;
}