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


pair < int, int > pp[501][501];
int vis[501][501];
string s[501];

int nxt[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int sz[501][501];

void dfs(int x, int y, int px, int py, int n){
    vis[x][y] = 1;
    pp[x][y] = mp(px, py);
    sz[px][py]++;
    REP(i, 4){
        int nx = x + nxt[i][0];
        int ny = y + nxt[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || s[nx][ny] == 'X' || vis[nx][ny]) continue;
        dfs(nx, ny, px, py, n);
    }
}

int cnt[501][501];
set < pair<int,int> > S;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, K; cin >> n >> K;
    REP(i, n) cin >> s[i];
    REP(i, n){
        REP(j, n){
            if(vis[i][j] == 0 && s[i][j] != 'X'){
                dfs(i, j, i, j, n);
            }
        }
    }

    int res = 0;
    REP(i, n){
        if(i+K-1 >= n) break;
        int xcnt = 0, sum = 0;
        for(int j = i; j < i+K; j++){
            for(int k = 0; k < K; k++){
                if(s[j][k] == 'X') xcnt++;
                else {
                    cnt[ pp[j][k].xx ][ pp[j][k].yy ]++;
                    if(cnt[ pp[j][k].xx ][ pp[j][k].yy ] == 1) {
//                        S.insert(pp[j][k]);
                        sum += sz[ pp[j][k].xx ][ pp[j][k].yy ];
//                        cout << i << " " << sum << " " << pp[j][k].xx << " " << pp[j][k].yy << endl;
                    }
                }
            }
        }
        for(int k = 0; k < K; k++){
            if(i && s[i-1][k] != 'X'){
                cnt[ pp[i-1][k].xx ][ pp[i-1][k].yy ]++;
                if(cnt[ pp[i-1][k].xx ][ pp[i-1][k].yy ] == 1) {
//                    S.insert(pp[i-1][k]);
                    sum += sz[ pp[i-1][k].xx ][ pp[i-1][k].yy ];
                }
            }
            if(i+K < n && s[i+K][k] != 'X'){
                cnt[ pp[i+K][k].xx ][ pp[i+K][k].yy ]++;
                if(cnt[ pp[i+K][k].xx ][ pp[i+K][k].yy ] == 1) {
//                    S.insert(pp[i+K][k]);
                    sum += sz[ pp[i+K][k].xx ][ pp[i+K][k].yy ];
                }
            }
        }
        for(int j = i; j < i+K; j++){
            if(K < n && s[j][K] != 'X'){
                cnt[ pp[j][K].xx ][ pp[j][K].yy ]++;
                if(cnt[ pp[j][K].xx ][ pp[j][K].yy ] == 1) {
//                    S.insert(pp[j][K]);
                    sum += sz[ pp[j][K].xx ][ pp[j][K].yy ];
                }
            }
        }
//        cout << i << " " << sum << " " << xcnt << " " << S.size() << endl;
        res = max(res, sum + xcnt);
        for(int k = 1; k+K-1 < n; k++){
            // delete
            for(int j = i; j < i+K; j++){
                if(s[j][k-1] == 'X') xcnt--;
                if(k-2 >= 0 && s[j][k-2] != 'X'){
                    cnt[ pp[j][k-2].xx ][ pp[j][k-2].yy ]--;
                    if(cnt[ pp[j][k-2].xx ][ pp[j][k-2].yy ] == 0) {
//                        S.erase(pp[j][k-2]);
                        sum -= sz[ pp[j][k-2].xx ][ pp[j][k-2].yy ];
                    }
                }
            }
            if(i > 0 && s[i-1][k-1] != 'X'){
                cnt[ pp[i-1][k-1].xx ][ pp[i-1][k-1].yy ]--;
                if(cnt[ pp[i-1][k-1].xx ][ pp[i-1][k-1].yy ] == 0) {
//                    S.erase(pp[i-1][k-1]);
                    sum -= sz[ pp[i-1][k-1].xx ][ pp[i-1][k-1].yy ];
                }
            }
            if(i+K < n && s[i+K][k-1] != 'X'){
                cnt[ pp[i+K][k-1].xx ][ pp[i+K][k-1].yy ]--;
                if(cnt[ pp[i+K][k-1].xx ][ pp[i+K][k-1].yy ] == 0) {
//                    S.erase(pp[i+K][k-1]);
                    sum -= sz[ pp[i+K][k-1].xx ][ pp[i+K][k-1].yy ];
                }
            }

            // insert

            for(int j = i; j < i+K; j++){
                if(s[j][k+K-1] == 'X') xcnt++;
                if(k+K < n && s[j][k+K] != 'X'){
                    cnt[ pp[j][k+K].xx ][ pp[j][k+K].yy ]++;
                    if(cnt[ pp[j][k+K].xx ][ pp[j][k+K].yy ] == 1) {
//                        S.insert(pp[j][k+K]);
                        sum += sz[ pp[j][k+K].xx ][ pp[j][k+K].yy ];
                    }
                }
            }
            if(i > 0 && s[i-1][k+K-1] != 'X'){
                cnt[ pp[i-1][k+K-1].xx ][ pp[i-1][k+K-1].yy ]++;
                if(cnt[ pp[i-1][k+K-1].xx ][ pp[i-1][k+K-1].yy ] == 1) {
//                    S.insert(pp[i-1][k+K-1]);
                    sum += sz[ pp[i-1][k+K-1].xx ][ pp[i-1][k+K-1].yy ];
                }
            }
            if(i+K < n && s[i+K][k+K-1] != 'X'){
                cnt[ pp[i+K][k+K-1].xx ][ pp[i+K][k+K-1].yy ]++;
                if(cnt[ pp[i+K][k+K-1].xx ][ pp[i+K][k+K-1].yy ] == 1) {
//                    S.insert(pp[i+K][k+K-1]);
                    sum += sz[ pp[i+K][k+K-1].xx ][ pp[i+K][k+K-1].yy ];
                }
            }

//            if(i == 1) cout << i << " " << k << " " << S.size() << " " << sum << " " << xcnt << endl;
            res = max(res, sum + xcnt);
        }
        set0(cnt);
    }
    cout << res << endl;
}