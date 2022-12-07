#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

void pref_suf(int *w, int n, int *p){
	p[0] = 0;
	for(int i=1;i<n;i++){
		p[i] = p[i-1];
		while(p[i] > 0 && w[i] != w[p[i]]) p[i] = p[p[i]-1];
		if (w[i] == w[p[i]]) p[i]++;
	}
}

int n, m, k, r;
int A[200010];
int B[200010];
int C[200010];
int P[200010];

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n) scanf("%d", &A[i]);
	FWD(i,0,m) scanf("%d", &B[i]);
	FWD(i,1,m) C[k++] = B[i]-B[i-1];
	C[k++] = (1e9)+3;
	FWD(i,1,n) C[k++] = A[i]-A[i-1];
	pref_suf(C, k, P);
	FWD(i,m-1,k) if(P[i] == m-1) ++r;
	printf("%d\n", r);
	return 0;
}