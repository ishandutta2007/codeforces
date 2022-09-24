#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

int N, M;
vector<int>A[128], B[128];
int use[110];

int dfs(int v, int g) {
    if (use[v]!=-1) return 0;
    use[v]=g;
    for (int i=0; i<int(A[v].size()); i++) {
	for (int j=0; j<int(B[A[v][i]].size()); j++) {
	    dfs(B[A[v][i]][j], g);
	}
    }
    return 0;
}
	    
int main() {
    scanf("%d%d", &N, &M);
    bool no_lang=1;

    for (int i=0; i<N; i++) {
	int k, t;
	scanf("%d", &k);
	if (k>0) no_lang=0;
	for (int j=0; j<k; j++) {
	    scanf("%d", &t); t--;
	    A[i].push_back(t);
	    B[t].push_back(i);
	}
    }

    int g=0;
    memset(use, -1, sizeof use);

    for (int i=0; i<N; i++) {
	if (use[i]<0) dfs(i, g++);
    }
    printf("%d\n", no_lang?N:g-1);

    return 0;
}