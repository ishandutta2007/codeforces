#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int n, m, deg[N], p[N], Mp[N], tot;
priority_queue< int > q;
void tp() {
	L(i, 1, n) if(deg[i] == 0) q.push(i);
	while(!q.empty()) {
		int u = q.top();
		p[++tot] = u, q.pop();
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			deg[v] --;
			if(deg[v] == 0) q.push(v);
		}
	}
	reverse(p + 1, p + n + 1);
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(v, u), deg[u] ++;
	}
	tp();
	L(i, 1, n) Mp[p[i]] = i;
	L(i, 1, n) printf("%d ", Mp[i]);
	puts("");
	return 0;
}