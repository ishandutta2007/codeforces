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

int n, m;
char A[23];
char B[23];

int main(){
	scanf("%d %d", &n, &m);
	scanf("%s", A);
	scanf("%s", B);
	if(A[0] == '>' && A[n-1] == '<' && B[0] == '^' && B[m-1] == 'v'){
		printf("YES\n");
		return 0;
	}
	if(A[0] == '<' && A[n-1] == '>' && B[0] == 'v' && B[m-1] == '^'){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}