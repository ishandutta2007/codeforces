#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 250;
const int MAXQ = (1 << 20);

char mat[MAXN + 1][MAXN + 1];

struct Data {
    unsigned char l, c;
    char dst;
}Q[MAXQ];

int mark[MAXN + 1][MAXN + 1];

char dl[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

int n, m;

inline bool in(int l, int c) {
    return l > 0 && c > 0 && l <= n && c <= m;
}

inline void mod(int &x) {
    x++;
    if(x >= MAXQ)
        x -= MAXQ;
}

ll sol[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, p, q;
    ios::sync_with_stdio(false);
    cin >> n >> m >> q >> p;
    for(i = 1; i <= n; i++) {
        cin >> (mat[i] + 1);
    }
    int cur = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(isalpha(mat[i][j])) {
                cur++;
                int b = 0, e = 0;
                int val = (mat[i][j] - 'A' + 1) * q;
                Q[e++] = {i, j, 0};
                mark[i][j] = cur;
                sol[i][j] += val;
                while(b != e) {
                    for(int dir = 0; dir < 4; dir++) {
                        int l = Q[b].l + dl[dir];
                        int c = Q[b].c + dc[dir];
                        if(in(l, c) && mark[l][c] < cur && mat[l][c] != '*') {
                            mark[l][c] = cur;
                            if(val / (1 << (Q[b].dst + 1)) > 0) {
                                Q[e] = {l, c, Q[b].dst + 1};
                                sol[l][c] += val / (1 << (Q[e].dst));
                                mod(e);
                            }
                        }
                    }
                    mod(b);
                }
            }
        }
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            ans += (sol[i][j] > p);
        }
        //printf("\n");
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}