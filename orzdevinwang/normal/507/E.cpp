#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define db double 
#define ll long long
using namespace std;
const int N = 1e5 + 7;
int n, m, sum;
int head[N], edge_id = 1;
struct node {
	int to, fr, w, tw, next;
} e[N << 1];
void add_edge(int u, int v, int w) { 
	++edge_id, e[edge_id].next = head[u], e[edge_id].fr = u, e[edge_id].to = v, e[edge_id].w = w, head[u] = edge_id; 
}
int len[N], ans[N], lase[N];
int stk[N], tot;
int main() {
    scanf("%d%d", &n, &m);
	L(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
        add_edge(v, u, w);
	} 
	fill(len + 1, len + n + 1, 1e9);
	queue<int> q;
	q.push(1), len[1] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(len[v] == 1e9) len[v] = len[u] + 1, ans[v] = ans[u] + e[i].w, lase[v] = i, q.push(v);
			else if(len[v] == len[u] + 1 && ans[v] < ans[u] + e[i].w) ans[v] = ans[u] + e[i].w, lase[v] = i;
		}
	}
	for(int x = n; x != 1; x = e[lase[x]].fr) e[lase[x]].tw = e[lase[x] ^ 1].tw = 1;
	L(i, 1, m) if(e[i << 1].tw ^ e[i << 1].w) sum++;
	printf("%d\n", sum);
	L(i, 1, m) if(e[i << 1].tw ^ e[i << 1].w) printf("%d %d %d\n", e[i << 1].fr, e[i << 1].to, e[i << 1].w ^ 1);
    return 0;
}