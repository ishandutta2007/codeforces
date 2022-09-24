#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
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

int N, X, A[1024];
int len[1024];
bool dp[1024];


int dfs(int k) {
    if (len[k]!=-1) return len[k];
    if (A[k]==-1) return len[k]=0;
    return len[k]=dfs(A[k])+1;
}

int main() {
    scanf("%d%d", &N, &X);
    X--;
    memset(len, -1, sizeof len);
    
    for (int i=0; i<N; i++) {
	scanf("%d", A+i);
	A[i]--;
    }

    UnionFind uf; uf.init(N);
    for (int i=0; i<N; i++) {
	dfs(i);
	if (A[i]!=-1) uf.link(i, A[i]);
    }
    vector<int>v;
    for (int i=0; i<N; i++) {
	if (uf.root(i)==i && !uf.same(i, X)) v.push_back(uf.size(i));
    }

    dp[0]=1;
    for (int i=0; i<int(v.size()); i++) {
	for (int j=N; j>=v[i]; j--) {
	    dp[j] |= dp[j-v[i]];
	}
    }
    for (int i=0; i<N; i++) {
	if (dp[i]) {
	    printf("%d\n", i+len[X]+1);
	}
    }
    
    return 0;
}