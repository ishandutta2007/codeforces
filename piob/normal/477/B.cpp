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

int n, k;

int main(){
	scanf("%d %d", &n, &k);
	printf("%d\n", k*(n*6-1));
	FWD(i,0,n){
		int m = 6*i+1;
		printf("%d %d %d ", k*m, k*(m+2), k*(m+4));
		if((m+1)%3 == 0)
			printf("%d\n", k*(m+3));
		else
			printf("%d\n", k*(m+1));
	}
	return 0;
}