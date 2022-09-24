#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

struct SegmentTree {
    int n, m;
    vector<int>all;
    vector<char>lazy;
    SegmentTree(int n) :n(n) {
	m=1;
	for (;m<n;) m*=2;
	all = vector<int>(m*2);
	lazy = vector<char>(m*2, 0);
    }
    void down(int x, int y, int k, int l, int r) {
	if (lazy[k]) {
	    if (k<m) lazy[k*2] = lazy[k*2+1] = 1;
	    all[k] = 0;
	    lazy[k] = 0;
	}
	if (x<=l && r<=y) {
	    return ;
	} else if (x<r && l<y) {
	    down(x, y, k*2, l, (l+r)/2);
	    down(x, y, k*2+1, (l+r)/2, r);
	}
    }
    void zero(int x, int y) { down(x, y ,1, 0, m); zero(x, y, 1, 0, m); }
    void zero(int x, int y, int k, int l, int r) {
	if (x<=l && r<=y) {
	    lazy[k] = 1;
	    all[k] = 0;
	} else if (x<r && l<y) {
	    all[k*2] += all[k]; all[k*2+1] += all[k]; all[k] = 0;
	    zero(x, y, k*2, l, (l+r)/2);
	    zero(x, y, k*2+1, (l+r)/2, r);
	}
    }
    void inc(int x, int y) { down(x, y, 1, 0, m); inc(x, y, 1, 0, m); }
    void inc(int x, int y, int k, int l, int r) {
	if (x<=l && r<=y) {
	    all[k]++;
	} else if (x<r && l<y) {
	    inc(x, y, k*2, l, (l+r)/2);
	    inc(x, y, k*2+1, (l+r)/2, r);
	}
    }
    int at(int x) { down(x, x+1, 1, 0, m); return at(x, 1, 0, m); }
    int at(int x, int k, int l, int r) {
	if (m<=k) return all[k];
	return all[k] + (x<(l+r)/2 ?
			 at(x, k*2, l, (l+r)/2) :
			 at(x, k*2+1, (l+r)/2, r));
    }
};


typedef vector<vector<int> > Mat;
Mat G;
int N, Q;
vector<int>tour;
vector<pair<int,int> > pos;

void dfs(int k, int p) {
    tour.push_back(k);
    for (int i=0; i<int(G[k].size()); i++) {
	if (G[k][i]==p) continue;
	dfs(G[k][i], k);
    }
    tour.push_back(-k);
}

int main() {
    // build
    scanf("%d", &N);
    G = Mat(N+1);

    for (int i=1; i<N; i++) {
	int a, b; scanf("%d%d", &a, &b);
	G[a].push_back(b);
	G[b].push_back(a);
    }
    dfs(1, -1);
    pos.resize(N+1);
    for (int i=0; i<N*2; i++) {
	if (tour[i] > 0) pos[tour[i]].first = i;
	else pos[-tour[i]].second = i;
    }

    //for (int i=0; i<N*2; i++) printf("%d ", tour[i]); puts("");
    SegmentTree tree(N*2);
    for (int i=1; i<=N; i++) tree.inc(0, pos[i].first+1);

    // query
    scanf("%d", &Q);
    for (;Q--;) {
	int c, v;
	scanf("%d%d", &c, &v);
	if (c==1) {
	    //printf("%d %d\n", pos[v].first, pos[v].second);
	    tree.zero(pos[v].first, pos[v].second+1);
	} else if (c==2) {
	    tree.inc(0, pos[v].first+1);
	} else {
	    int a = tree.at(pos[v].first),
		b = tree.at(pos[v].second);
	    puts(a==b ? "1" : "0");
	}
	//for (int i=0; i<N*2; i++) printf("%d ", tree.at(i)); puts("");
    }
    return 0;
}