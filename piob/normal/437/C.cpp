#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const K eps = 1e-9;

int n, m;
int O[1010];
int C[1010];
int D[1010];
vector<int> E[1010];

inline int cmp(int a, int b){
	return C[a] > C[b];
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n){
		scanf("%d", &C[i]);
		O[i] = i;
	}
	sort(O, O+n, cmp);
	FWD(i,0,m){
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	int r = 0;
	FWD(i,0,n){
		int u = O[i];
		for(int v : E[u])
			if(!D[v]){
				r += C[v];
			}
		D[u] = 1;
	}
	printf("%d\n", r);
	return 0;
}