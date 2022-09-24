#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, T[100010], A[100010], L[100010], O[100010];

int dfs(int v) {
    if (L[v]!=-1) return L[v];
    L[v] = 0;
    if (A[v]==-1) return L[v] = 1; 
    if (T[A[v]]==1) return L[v] = 1;
    if (O[A[v]]>1) return L[v] = 1;
    return L[v] = 1 + dfs(A[v]);
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", T+i);
    for (int i=0; i<N; i++) {
	scanf("%d", A+i); A[i]--;
	if (A[i] >= 0) O[A[i]]++;
    }
    memset(L, -1, sizeof L);

    int ans = 0;
    for (int i=0; i<N; i++) {
	if (T[i]==1) {
	    ans = max(ans, dfs(i));
	}
    }

    
    printf("%d\n", ans);
    for (int i=0; i<N; i++) {
	if (T[i]==1 && ans == L[i]) {
	    vector<int>k;
	    for (int j=0, v=i; j<ans; j++) {
		k.push_back(v);
		v=A[v];
	    }
	    for (int j=ans; j--;) printf("%d%c", k[j]+1, j?' ':'\n');
	    break;
	}
    }

    return 0;
}