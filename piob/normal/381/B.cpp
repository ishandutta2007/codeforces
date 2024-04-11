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

int n, m;
int C[5010];

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		++C[a];
		m = max(m, a);
	}
	int n = 1;
	FWD(i,0,m)
		n += min(2, C[i]);
	printf("%d\n", n);
	FWD(i,0,m)
		if(C[i])
			printf("%d ", i);
	printf("%d", m);
	BCK(i,m-1,-1)
		if(C[i]>1)
			printf(" %d", i);
	printf("\n");
	return 0;
}