#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define st first
#define nd second
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

bool prime(int n){
	if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0)
			return 0;
	return 1;
}

int n;
int A[210];
vector<int> even, odd;

const int N = 500;
int cap[N][N];
int flow[N][N];

int edmonds(int s, int t) {
    int b,e,q[n],p[n],d,FLOW=0;
    REP(i,n) REP(j,n) flow[i][j]=0;
    for(;;) {
        REP(i,n) p[i]=-1;
        for(q[b=e=0]=s;b<=e;b++)
            REP(v,n) 
                if (flow[q[b]][v] < cap[q[b]][v] && p[v]<0)
                    p[q[++e]=v] = q[b];
        if (p[t]<0) break;
        d = cap[p[t]][t] - flow[p[t]][t];
        for(int i=t;i!=s;i=p[i]) d=min(d,cap[p[i]][i]-flow[p[i]][i]);
        for(int i=t;i!=s;i=p[i]) {
            flow[p[i]][i] += d;
            flow[i][p[i]] -= d;
        }
        FLOW += d;
    }
    return FLOW;
}

vector<int> edge[210];
bool vis[210];
vector<vector<int>> cycle;

void dfs(int u){
	cycle.back().push_back(u);
	vis[u] = 1;
	for(int v : edge[u])
		if(!vis[v])
			dfs(v);
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1){
		scanf("%d", &A[i]);
		if(A[i]&1) odd.push_back(i); else even.push_back(i);
	}
	for(int a : odd)
		cap[0][a] = 2;
	for(int b : even)
		cap[b][n+1] = 2;
	for(int a : odd)
		for(int b : even)
			if(prime(A[a] + A[b])){
				//printf("%d -- %d\n", A[a], A[b]);
				cap[a][b] = 1;
			}
	n += 2;
	/*FWD(i,0,n){
		FWD(j,0,n)
			printf("%d ", cap[i][j]);
		printf("\n");
	}*/
	unsigned f = (unsigned)edmonds(0,n-1);
	//printf("%u\n", f);
	n -= 2;
	if(f == 2*odd.size() && f == 2*even.size()){
		for(int a : odd)
			for(int b : even)
				if(flow[a][b] == 1){
					edge[a].push_back(b);
					edge[b].push_back(a);
				}
		FWD(i,1,n+1)
			if(!vis[i]){
				cycle.push_back(vector<int>());
				dfs(i);
			}
		printf("%d\n", cycle.size());
		FWD(i,0,(int)cycle.size()){
			printf("%d ", cycle[i].size());
			for(int u : cycle[i]) printf("%d ", u);
			printf("\n");
		}
	}else{
		printf("Impossible\n");
	}
	return 0;
}