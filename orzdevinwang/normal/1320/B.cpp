#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
using namespace std;
const int N = 1e6 + 7;
int n, m, len, f[N], ans[N], who[N], ansa, ansb;
int edge_id, head[N];
struct node {
    int to, next;
} e[N << 1];
void add_edge(int u, int v) { ++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id; }
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, m) {
        int u, v; scanf("%d%d", &u, &v);
        add_edge(v, u);
    }
    scanf("%d", &len); L(i, 1, len) scanf("%d", &f[i]);
    memset(ans, 0x3f, sizeof(ans));
    queue<int> q;
    ans[f[len]] = 1, q.push(f[len]);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(ans[v] > 1e8) ans[v] = ans[u] + 1, who[v] = u, q.push(v);
            else if(ans[v] == ans[u] + 1) who[v] = -1;
        }
    }
    L(i, 1, len - 1) {
        if(ans[f[i]] != ans[f[i + 1]] + 1) ansa ++;
        if(who[f[i]] != f[i + 1]) ansb++;
    }
    printf("%d %d\n", ansa, ansb);
	return 0;
}