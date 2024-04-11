#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define popcount __builtin_popcount
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()
#define max3(a,b,c) max((a), max((b),(c)))

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

const int INF = 1000*1000*1000;

int n, m;

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,1,n+1){
		if(i&1){
			FWD(j,0,m) printf("#");
		}else{
			if(((i/2)&1)==0) printf("#");
			FWD(j,1,m) printf(".");
			if(((i/2)&1)==1) printf("#");
		}
		printf("\n");
	}
	return 0;
}