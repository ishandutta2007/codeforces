#include<bits/stdc++.h>
#define N 100010
#define inf 0x7ffffff
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
using namespace std;
int n,m,s,t,sum,cc[N],use[N];
int head[N],last[N];
struct node{
	int to,next,val;
} e[N << 1];
int edge_id = 1;
void add_edge(int x, int y, int val) {
	int id = ++edge_id;
	if(head[x]==0) head[x] = id;
	else e[last[x]].next=id;
	last[x]=id,e[id].val=val,e[id].to=y;
}
void add(int x, int y, int val) {
	add_edge(x, y, val);
	add_edge(y, x, 0);
}
void bfs() {
	for(int i = 1; i <= n; i++) use[i]=cc[i]=0;
	cc[s]=1,use[1]=s;
	int u=0,v=1;
	while(u<v) {
		++u;
		int fst=use[u];
		for(int i = head[fst]; i != 0; i = e[i].next) {
			if(cc[e[i].to]!=0) continue;
			if(e[i].val==0) continue;
			++v,cc[e[i].to]=cc[fst]+1,use[v]=e[i].to;
		}
	}
}
int dfs(int x,int val) {
	if(x==t) return val;
	if(cc[x]==cc[t]) {
		cc[x]=0;
		return 0;
	}
	int yuliu=val;
	for(int i = head[x]; i != 0; i = e[i].next) {
		if(cc[e[i].to]!=cc[x]+1) continue;
		int addd=dfs(e[i].to,min(e[i].val,yuliu));
		yuliu -= addd , e[i].val -= addd , e[i^1].val += addd;
	}
	return val-yuliu;
}
void Dinic(int &ans) {
	bfs();
	int addd=dfs(s,inf);
	ans += addd;
	if(addd==0) return;
	Dinic(ans);
}
int pn, A[4], B[4];
int main() {
	n = 8, m = 12, s = 7, t = 8;
    scanf("%d", &pn);
    L(i, 1, 3) scanf("%d", &A[i]), add(s, i, A[i]);
	L(i, 1, 3) scanf("%d", &B[i]), add(i + 3, t, B[i]);
    L(i, 1, 3) add(i, i + 3, 1e9);
    L(i, 1, 3) add(i, (i + 1) % 3 + 4, 1e9);
    Dinic(sum);
	printf("%d ", pn - sum);
    printf("%d\n", min(A[1], B[2]) + min(A[2], B[3]) + min(A[3], B[1]));
	return 0;
}