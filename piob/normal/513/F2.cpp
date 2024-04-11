#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

namespace flow{
	const int N = 10000;
	struct edge {
	    int v, cap, flow;
	    int back_ind;
	    edge *back;
	    edge(int vi, int ci) : v(vi), cap(ci) {}
	};

	int n, s, t;
	int e[N], h[N];
	vector<edge> g[N];
	vector<edge>::iterator cur[N];

	void bfs(int start, int start_h) {
	    queue<int> q;
	    h[start] = start_h;
	    for(q.push(start);!q.empty();q.pop()) {
	        int u = q.front();
	        for(auto i :g[u])
	            if (i.back->flow < i.back->cap && h[i.v] > h[u]+1) {
	                    h[i.v] = h[u] + 1;
	                    q.push(i.v);
	            }
	    }
	}

	int compute_flow() {
	    queue<int> q;
	    REP(i,n) {
	        for(auto &j : g[i]) {
	            j.flow = 0;
	            j.back = &g[j.v][j.back_ind];
	        }
	        cur[i] = g[i].begin();
	        h[i] = e[i] = 0;
	    }
	    for(auto &i : g[s]) {
	        i.flow = i.cap;
	        i.back->flow = -i.flow;
	        if (e[i.v] == 0 && i.v != t) q.push(i.v);
	        e[i.v] += i.flow;
	    }
	    h[s] = n;
	    int relabel_counter = 0;
	    for(;!q.empty();q.pop()) {
	        int u = q.front();
	        while (e[u] > 0) {
	            if (cur[u] == g[u].end()) { // relabel
	                relabel_counter++;
	                h[u] = 2*n+1;
	                for(auto i : g[u]) if(i.flow < i.cap) h[u] = min(h[u], h[i.v]+1);
	                cur[u] = g[u].begin(); 
	                continue; 
	            }
	            if (cur[u]->flow < cur[u]->cap && h[u] == h[cur[u]->v]+1) { // push
	                int d = min(e[u], cur[u]->cap - cur[u]->flow);
	                cur[u]->flow += d;
	                cur[u]->back->flow -= d;
	                e[u] -= d;
	                e[cur[u]->v] += d;
	                if (e[cur[u]->v]==d && cur[u]->v!=t && cur[u]->v!=s) q.push(cur[u]->v);
	            } else cur[u]++; 
	        }
	        if (relabel_counter >= n) { 
	            REP(i,n) h[i] = 2*n+1;
	            bfs(t, 0);
	            bfs(s, n);
	            relabel_counter = 0;
	        }
	    }
	    return e[t];
	}

	void add_edge(int a, int b, int c) {
		//printf("add edge %d -> %d\n", a, b);
	    assert(a != b);  // NIE wrzucac petelek!
	    g[a].push_back(edge(b, c));
	    g[b].push_back(edge(a, 0));
	    g[a].back().back_ind = (int)g[b].size()-1;
	    g[b].back().back_ind = (int)g[a].size()-1;
	}
}

int n, m, x, y;
char M[23][23];

int cell_id(int i, int j){
	return i*m+j;
}

int dist[23*23][23*23];
bool obstacle[23*23];

//  0 - zrodlo
//  1...x
//  x+1...x+n*m
//  x+n*m+1...x+2*n*m
//  x+2*n*m+1...x+2*n*m+y
//  x+2*n*m+y+1 - ujscie

int XP[1010], XQ[1010], XC[1010];
int YP[1010], YQ[1010], YC[1010];

LL time_limit;

void processX(int p, int q, int c, int i){
	flow::add_edge(0, 1+i, 1);
	int u = cell_id(p, q);
	FWD(v,0,n*m) if(!obstacle[v] && dist[u][v] < 1000*1000*1000 && (LL)dist[u][v]*c <= time_limit) flow::add_edge(1+i, x+1+v, 1);
}

void processY(int p, int q, int c, int i){
	flow::add_edge(x+2*n*m+1+i, flow::t, 1);
	int u = cell_id(p, q);
	FWD(v,0,n*m) if(!obstacle[v] && dist[u][v] < 1000*1000*1000 && (LL)dist[u][v]*c <= time_limit) flow::add_edge(x+n*m+1+v, x+2*n*m+1+i, 1);	
}

bool check(LL mi){
	time_limit = mi;
	REP(i,flow::n) flow::g[i].clear();
	FWD(i,0,n*m) if(!obstacle[i]) flow::add_edge(x+1+i, x+n*m+1+i, 1);
	FWD(i,0,x) processX(XP[i]-1,XQ[i]-1,XC[i],i);
	FWD(i,0,y) processY(YP[i]-1,YQ[i]-1,YC[i],i);
	int f = flow::compute_flow();
	//printf("%d\n", f);
	return f == x;
}

int main(){
	scanf("%d %d %d %d", &n, &m, &x, &y);
	FWD(i,0,n) scanf("%s", M[i]);
	FWD(i,0,n*m) FWD(j,0,n*m) dist[i][j] = 1000*1000*1000;
	FWD(i,0,n) FWD(j,0,m) obstacle[cell_id(i,j)] = (M[i][j] == '#' ? 1 : 0);
	FWD(p,0,n)
		FWD(q,0,m)
			if(M[p][q] == '.'){
				dist[cell_id(p,q)][cell_id(p,q)] = 0;
				FWD(d,0,4){
					int s = p + dx[d];
					int t = q + dy[d];
					if(0 <= s && s < n && 0 <= t && t < m && M[s][t] == '.'){
						dist[cell_id(p,q)][cell_id(s,t)] = 1;
					}
				}
			}
	FWD(k,0,n*m) if(!obstacle[k])
		FWD(i,0,n*m) if(!obstacle[i])
			FWD(j,0,n*m) if(!obstacle[j])
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int p, q, c;
	scanf("%d %d %d", &p, &q, &c);
	FWD(i,0,x) scanf("%d %d %d", &XP[i], &XQ[i], &XC[i]);
	FWD(i,0,y) scanf("%d %d %d", &YP[i], &YQ[i], &YC[i]);
	if(x < y){
		XP[x] = p; XQ[x] = q; XC[x] = c;
		++x;
	}else{
		YP[y] = p; YQ[y] = q; YC[y] = c;
		++y;
	}
	if(x != y){
		cout << -1 << endl;
		return 0;
	}
	flow::s = 0;
	flow::t = x+2*n*m+y+1;
	flow::n = flow::t + 1;
	//check(1);
	//return 0;
	LL lo = -1;
	LL hi = 1000LL*1000*1000*1000;
	while(hi-lo > 1){
		LL mi = (lo+hi)/2;
		if(check(mi))
			hi = mi;
		else
			lo = mi;
	}
	if(hi == 1000LL*1000*1000*1000)
		hi = -1;
	cout << hi << endl;
	return 0;
}