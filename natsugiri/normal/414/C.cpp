#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, A[1<<20];
int M;

LL G[32], R[32];

void merge_sort(int l, int r, int d) {
    if (l+1 >= r) return;
    int m = (l+r)/2;
    merge_sort(l, m, d+1);
    merge_sort(m, r, d+1);
    
    for (int i=l; i<m; i++) {
	G[d] += lower_bound(A+m, A+r, A[i]) - (A+m);
	R[d] += (A+r) - upper_bound(A+m, A+r, A[i]);
    }
    
    int i=l, j=m;
    vector<int>v;
    for (;i<m && j<r;) {
	if (A[i] > A[j]) v.push_back(A[j++]);
	else v.push_back(A[i++]);
    }
    for (;i<m;) v.push_back(A[i++]);
    for (;j<r;) v.push_back(A[j++]);
    
    for (int i=0; i<(int)v.size(); i++) A[i+l] = v[i];
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<(1<<N); i++) scanf("%d", A+i);

    merge_sort(0, 1<<N, 0);

    // for (int i=0; i<N; i++) {
    // 	printf("%lld %lld\n", G[i], R[i]);
    // }

    scanf("%d", &M);
    for (;M--;) {
	int Q;
	scanf("%d", &Q);
	
	for (int i=0; i<Q; i++) swap(G[N-1-i], R[N-1-i]);
	LL ans = 0;
	for (int i=0; i<N; i++) ans += G[i];
	printf("%lld\n", ans);
    }

    return 0;
}