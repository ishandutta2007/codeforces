#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const int INF = 1<<29;
const int dx[]={0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

typedef vector<vector<int> > Mat;

struct SCC {
    vector<int>scc;
    vector<int>v;
    int cnt;
    SCC() {}
    SCC(const Mat&G, const Mat&R) {
        int n=G.size(); cnt=0;
        scc=vector<int>(n);
        for (int i=0; i<n; i++) {
            if (!scc[i]) dfs1(G, i, v);
        }
        scc=vector<int>(n, -1);
        for (int i=n-1; i>=0; i--) {
            if (scc[v[i]]<0) dfs2(R, v[i], cnt++);
        }
    }
    void dfs1(const Mat&G, int p, vector<int>&v) {
        if (scc[p]) return;
        scc[p]=1;
        for (int i=0; i<int(G[p].size()); i++)
            dfs1(G, G[p][i], v);
        v.push_back(p);
    }
    void dfs2(const Mat&R, int p, int cnt) {
        if (scc[p]>=0) return;
        scc[p]=cnt;
        for (int i=0; i<int(R[p].size()); i++)
            dfs2(R, R[p][i], cnt);
    }
};

int N, M;
char F[1024][1024];


int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) scanf("%s", F[i]);

    char next[256];
    next['D'] = 'I';
    next['I'] = 'M';
    next['M'] = 'A';
    next['A'] = 'D';

    
    Mat G(N*M), R(N*M);

    for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
	    for (int d=0; d<4; d++) {
		int yy = i + dy[d], xx = j + dx[d];
		if (yy < 0 || N <= yy || xx < 0 || M <= xx || next[F[i][j]] != F[yy][xx]) continue;
		G[i*M+j].push_back(yy*M+xx);
		R[yy*M+xx].push_back(i*M+j);
	    }
	}
    }
    
    SCC scc(G, R);

    if (scc.cnt != N*M) {
	puts("Poor Inna!");
    } else {
	vector<int>len(N*M, 1);

	for (int i=0; i<(int)scc.v.size(); i++) {
	    int s = scc.v[i];

	    for (int j=0; j<(int)R[s].size(); j++) {
		int t = R[s][j];
		len[t] = max(len[t], len[s]+1);

	    }
	}

	int ans = 0;
	for (int i=0; i<N; i++) {
	    for (int j=0; j<M; j++) {
		if (F[i][j] == 'D') ans = max(ans, len[i*M+j]/4);
	    }
	}
	if (ans == 0) puts("Poor Dima!");
	else printf("%d\n", ans);
    }
    
    return 0;
}