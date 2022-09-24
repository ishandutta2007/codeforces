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
int n, m;
vector<int>one, two, three;

int main() {
    scanf("%d%d", &n, &m);
    UnionFind uf; uf.init(n);
    for (;m--;) {
	int a, b;
	scanf("%d%d", &a, &b); a--; b--;
	uf.link(a, b);
    }
    for (int i=0; i<n; i++) {
	if (uf.root(i)==i) {
	    if (uf.size(i)>3) {
		puts("-1");
		return 0;
	    }
	    for (int j=0; j<n; j++) {
		if (uf.same(i, j)) {
		    if (uf.size(i)==1) one.push_back(j);
		    if (uf.size(i)==2) two.push_back(j);
		    if (uf.size(i)==3) three.push_back(j);
		}
	    }
	}
    }
    if (two.size()>2*one.size()) {
	puts("-1");
	return 0;
    }
    for (int i=0; i<int(two.size()); i+=2) {
	three.push_back(two[i]);
	three.push_back(two[i+1]);
	three.push_back(one.back());
	one.pop_back();
    }
    for (int i=0; i<int(one.size()); i+=3) {
	three.push_back(one[i]);
	three.push_back(one[i+1]);
	three.push_back(one[i+2]);
    }
    for (int i=0; i<int(three.size()); i+=3) {
	printf("%d %d %d\n", three[i]+1, three[i+1]+1, three[i+2]+1);
    }
	
    return 0;
}