#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define db double 
#define ll long long
using namespace std;
const int N = 111;
const int NN = 30;
int n;
int head[NN], deg[NN], edge_id;
struct node {
    int to, next;
} e[N * N * 3];
void add_edge(int x, int y) {
    ++edge_id, e[edge_id].next = head[x], e[edge_id].to = y, head[x] = edge_id;
    deg[y]++;
}
char s[N][N];
void bj(int aa, int bb) {
    int la = strlen(s[aa] + 1), lb = strlen(s[bb] + 1), minn = min(la, lb);
    for(int i = 1; i <= minn; i++) 
        if(s[aa][i] != s[bb][i]) {
            add_edge(s[aa][i] - 'a' + 1, s[bb][i] - 'a' + 1);
            return;
        }
    if(la >= lb) {
        printf("Impossible\n");
        exit(0);
    }
}
int ans[N], cnt = 0;
void kp() {
    queue<int> q;
    L(i, 1, 26) if(deg[i] == 0) q.push(i);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans[++cnt] = u;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            deg[v]--;
            if(deg[v] == 0) q.push(v);
        }
    }
    if(cnt != 26) {
        printf("Impossible\n");
        exit(0);
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for(int i = 1; i < n; i++) bj(i, i + 1);
    kp();
    L(i, 1, 26) putchar(ans[i] + 'a' - 1);
    return 0;
}