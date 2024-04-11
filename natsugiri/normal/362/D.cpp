#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

typedef long long LL;


struct UnionFind {
    vector<int>U;
    int n;
    UnionFind() {}
    void init(int n) { U=vector<int>(n, -1); this->n=n; }
    int root(int x) {
        if (U[x]<0) return x;
        return U[x]=root(U[x]);
    }
    int link(int x, int y) {
        int p, q;
        p=root(x); q=root(y);
        if (p==q) return p;
        if (q<p) swap(p, q);
        U[p]+=U[q];
        n--;
        return U[q]=p;
    }
    bool same(int x, int y) { return root(x)==root(y); }
    int size(int x) { return -U[root(x)]; }
};


int N, M, P, Q;
vector<int> X, Y, L;
int main() {
    scanf("%d%d%d%d", &N, &M, &P, &Q);
    for (int i=0; i<M; i++) {
	int x, y, l;
	scanf("%d%d%d", &x, &y, &l);
	x--; y--;
	X.push_back(x);
	Y.push_back(y);
	L.push_back(l);
    }

    UnionFind uf; uf.init(N);
    for (int i=0; i<M; i++) uf.link(X[i], Y[i]);

    vector<LL>weight(N);
    int big_reg = 0;

    for (int i=0; i<M; i++) {
	weight[uf.root(X[i])] += L[i];
    }
    for (int i=0; i<N; i++) {
	if (i == uf.root(i) && uf.size(i)>1) big_reg++;
    }
    
    bool yes = true;
    if (uf.n < Q) yes = false;
    if (uf.n == Q && P>0 && big_reg==0) yes = false;
    if (uf.n-Q > P) yes = false;

    if (yes) {
	puts("YES");
	priority_queue<pair<LL,int> >G;
	for (int i=0; i<N; i++) {
	    if (uf.root(i) == i) {
		G.push(make_pair(-weight[i], i));
	    }
	}
	for (int i=0; i<P; i++) {
	    if ((int)G.size() > Q) { // Q >= 2
		pair<LL,int> s = G.top(); G.pop();
		pair<LL,int> t = G.top(); G.pop();

		X.push_back(s.second);
		Y.push_back(t.second);
		LL S = -s.first-t.first, cost = S+1;
		cost = min(cost, (LL)1e9);
		G.push(make_pair(-cost-S, s.second));
	    }

	    printf("%d %d\n", X.back()+1, Y.back()+1);
	}
    } else {
	puts("NO");
    }
    return 0;
}