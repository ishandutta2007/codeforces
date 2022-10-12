#include <bits/stdc++.h>
using namespace std;

struct Edge {    
    int q, i, j, v;
};

int n, m, q;
const int N = 100001;
vector <Edge> edge[N];

int ans[N];

int sum;

int sumX[1002];
int book[1002][1002];
int inv[1002];


int dfs(int u) {
    ans[u] = sum;
    
    for (int i=0; i<edge[u].size(); i++) {
        int q = edge[u][i].q;
        int x = edge[u][i].i;
        int y = edge[u][i].j;
        int v = edge[u][i].v;
        
        if (q == 1) {
            if (book[x][y] == (inv[x])) {
                book[x][y] = (1 ^ inv[x]);
                sum++;
                sumX[x]++;
                
                dfs(v);
                
                sumX[x]--;
                sum--;
                book[x][y] = inv[x];
            } else dfs(v);
        } else if (q == 2) {
            if (book[x][y] == (1 ^ inv[x])) {
                book[x][y] = inv[x];
                sum--;
                sumX[x]--;
                
                dfs(v);
                
                sumX[x]++;
                sum++;
                book[x][y] = (1 ^ inv[x]);
            } else dfs(v);
        } else if (q == 3) {
            sum -= sumX[x];
            sumX[x] = m - sumX[x];
            sum += sumX[x];
            inv[x] ^= 1;
            
            dfs(v);
            
            inv[x] ^= 1;
            sum -= sumX[x];
            sumX[x] = m - sumX[x];
            sum += sumX[x];
        } else {
            dfs(v);
        }
    }
}

int main() {
    scanf ("%d %d %d", &n, &m, &q);
    
    Edge tmp;
    for (int i=1; i<=q; i++) {        
        scanf ("%d", &tmp.q);     
        scanf ("%d", &tmp.i);
        tmp.v = i;
        if (tmp.q == 1 || tmp.q == 2) {
            scanf ("%d", &tmp.j);
        }
        
        if (tmp.q == 4) edge[tmp.i].push_back(tmp);
        else edge[i-1].push_back(tmp);
    }
    
    dfs(0);
    
    for (int i=1; i<=q; i++) printf ("%d\n", ans[i]);
    return 0;
}