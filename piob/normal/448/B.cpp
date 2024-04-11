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
char A[110];
char B[110];
int C[256];

int main(){
	scanf("%s%s", A, B);
	n = strlen(A);
	m = strlen(B);
	int j = 0;
	FWD(i,0,n)
		if(A[i] == B[j])
			++j;
	if(j == m){
		printf("automaton\n");
		return 0;
	}
	FWD(i,0,n) ++C[A[i]];
	FWD(i,0,m) --C[B[i]];
	bool zero = 1;
	FWD(i,'a','z'+1){
		if(C[i] < 0){
			printf("need tree\n");
			return 0;
		}
		if(C[i])
			zero = 0;
	}
	if(zero)
		printf("array\n");
	else
		printf("both\n");
	return 0;
}