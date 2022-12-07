#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int MAXN = 100010;
const int MAXV = 2000010;

int n;
int A[MAXN];
int B[MAXN];
int P[MAXN];
int Q[MAXN];

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d %d", &A[i], &B[i]);
		++P[A[i]];
		++Q[B[i]];
	}
	FWD(i,0,n){
		printf("%d %d\n", (n-1) + P[B[i]], (n-1) - P[B[i]]);
	}
	return 0;
}