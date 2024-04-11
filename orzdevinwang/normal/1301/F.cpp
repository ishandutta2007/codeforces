#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++)
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--)
#define ll long long
#define db double
#define mkp make_pair
using namespace std;
const int N = 1002;
const int K = 43;
const int inf = 1e9;
int n, m, k, q;
int G[K][K], s[N][N];
int det[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int min(int x, int y) { return x > y ? y : x; }
int ans[K][N][N];
void BFS(int x) {
    queue< pair<int, int> > q;
    L(i, 1, n) L(j, 1, m) if(s[i][j] == x) q.push(mkp(i, j)), ans[x][i][j] = 1;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        int xx = p.first, yy = p.second;
        q.pop();
        L(i, 0, 3) {
            int fx = xx + det[i][0], fy = yy + det[i][1];
            if(fx > n || fy > m || fx < 0 || fy < 0) continue;
            if(ans[x][fx][fy]) continue;
            ans[x][fx][fy] = ans[x][xx][yy] + 1;
            q.push(mkp(fx, fy));
        }
    }
    L(i, 1, n) L(j, 1, m) G[x][s[i][j]] = min(G[x][s[i][j]], ans[x][i][j]);
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    memset(G, 0x3f, sizeof(G));
    L(i, 1, k) G[i][i] = 0;
    L(i, 1, n) L(j, 1, m) scanf("%d", &s[i][j]);
    L(i, 1, k) BFS(i);
    L(t, 1, k) L(i, 1, k) L(j, 1, k) G[i][j] = min(G[i][j], G[i][t] + G[t][j]);
    scanf("%d", &q);
    while(q--) {
        int Xa, Ya, Xb, Yb; scanf("%d%d%d%d", &Xa, &Ya, &Xb, &Yb);
        int Ans = abs(Xa - Xb) + abs(Ya - Yb); 
        L(i, 1, k) L(j, 1, k) Ans = min(Ans, G[i][j] + ans[i][Xa][Ya] + ans[j][Xb][Yb] - 1);
        printf("%d\n", Ans);
    }
    return 0;
}