#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

vector <int> g[MAXN + 1];
int lvl[MAXN + 1];

int father[MAXN + 1][20];

void dfs(int nod) {
    for(int bit = 1; bit < 20; bit++) {
        father[nod][bit] = father[father[nod][bit - 1]][bit - 1];
    }
    for(auto it : g[nod]) {
        if(lvl[it] == 0) {
            father[it][0] = nod;
            lvl[it] = lvl[nod] + 1;
            dfs(it);
        }
    }
}

bool ok[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, x, y;
    //ios::sync_with_stdio(false);
    scanf("%d%d" ,&n,&k);
    for(i = 1; i < n; i++) {
        scanf("%d%d" ,&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    lvl[n] = 1;
    dfs(n);
    int cnt = n - k;
    ok[n] = ok[0] = 1;
    cnt--;
    for(i = n - 1; i >= 1 && cnt > 0; i--) {
        int nod = i;
        for(int bit = 19; bit >= 0; bit--) {
            if(ok[father[nod][bit]] == 0)
                nod = father[nod][bit];
        }
        if(lvl[i] - lvl[nod] + 1 <= cnt) {
            nod = i;
            while(ok[nod] == 0) {
                ok[nod] = 1;
                cnt--;
                nod = father[nod][0];
            }
        }
    }
    for(i = 1; i <= n; i++) {
        if(ok[i] == 0)
            printf("%d " ,i);
    }
    //cin.close();
    //cout.close();
    return 0;
}