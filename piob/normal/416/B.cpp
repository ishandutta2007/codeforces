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

int m, n;
int T[7];

int main(){
	scanf("%d %d", &m, &n);
	FWD(i,1,m+1){
		FWD(i,1,n+1){
			int a;
			scanf("%d", &a);
			T[i] = max(T[i-1], T[i]) + a;
		}
		printf("%d ", T[n]);
	}
	printf("\n");
	return 0;
}