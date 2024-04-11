#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



typedef vector<vector<int> > Mat;
int N;
Mat G;
double dfs(int k, int p, double d) {
    double r=1/d;
    for (int i=0; i<int(G[k].size()); i++) {
	if (G[k][i]==p) continue;
	r+=dfs(G[k][i], k, d+1);
    }
    return r;
}

int main() {
    scanf("%d", &N);
    G=Mat(N);
    for (int i=1; i<N; i++) {
	int a, b;
	scanf("%d%d", &a, &b); a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }
    printf("%.20f\n", dfs(0, -1, 1));
    return 0;
}