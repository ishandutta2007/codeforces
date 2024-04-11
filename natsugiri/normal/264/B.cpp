#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

const int MAX_N = 100010;

int N, A[100010];
int d[100010];
vector<int>P[100010], G[100010];

void factor(int id) {
    int n=A[id];
    for (int i=2; i*i<=n; i++) {
	if (n%i==0) {
	    P[i].push_back(id);
	    while (n%i==0) n/=i;
	}
    }
    if (n>1) P[n].push_back(id);
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    for (int i=0; i<N; i++) factor(i);
    for (int i=2; i<MAX_N; i++) {
	for (int j=0; j<int(P[i].size())-1; j++) {
	    G[P[i][j]].push_back(P[i][j+1]);
	}
    }

    for (int i=0; i<N; i++) d[i]=1;
    for (int i=0; i<N; i++) {
	for (int j=0; j<int(G[i].size()); j++) {
	    int e=G[i][j];
		d[e]=max(d[e], d[i]+1);
	}
    }

    int ans=0;
    for (int i=0; i<N; i++) ans=max(ans, d[i]);

    printf("%d\n", ans);
    
    return 0;
}