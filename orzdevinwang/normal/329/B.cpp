#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 1007;
int n, m, stx, sty, enx, eny, len[N * N], Ans;
char s[N][N];
int ans[N][N];
int det[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, n) scanf("%s", s[i] + 1);
    L(i, 1, n) L(j, 1, m) {
        if(s[i][j] == 'S') stx = i, sty = j;
        if(s[i][j] == 'E') enx = i, eny = j;
    }
    queue< pair<int, int> > q;
    q.push(mp(enx, eny));
    ans[enx][eny] = 1;
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        int x = now.first, y = now.second;
        if(s[x][y] >= '1' && s[x][y] <= '9') len[ans[x][y]] += s[x][y] - '0';
        L(i, 0, 3) {
            int dx = x + det[i][0], dy = y + det[i][1];
            if(dx < 1 || dx > n || dy < 1 || dy > m) continue;
            if(ans[dx][dy]) continue;
            if(s[dx][dy] == 'T') continue;
            ans[dx][dy] = ans[x][y] + 1;
            q.push(mp(dx, dy));
        }
    }
    L(i, 1, ans[stx][sty]) Ans += len[i];
    printf("%d\n", Ans);
    return 0;
}