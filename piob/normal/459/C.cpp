#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;

int n, k, d;

bool check(){
	int r = 1;
	FWD(i,0,d){
		r *= k;
		if(r >= n)
			return 1;
	}
	return 0;
}

int main(){
	scanf("%d %d %d", &n, &k, &d);
	if(check()){
		int W[d][n];
		int T[d];
		FWD(i,0,d) T[i] = 1;
		FWD(i,0,n){
			FWD(j,0,d) W[j][i] = T[j];
			if(i != n-1){
				int j = d-1;
				while(T[j] == k) --j;
				++T[j];
				while(++j < d) T[j] = 1;
			}
		}
		FWD(j,0,d){
			FWD(i,0,n) printf("%d ", W[j][i]);
			printf("\n");
		}
	}else
		printf("-1\n");
	return 0;
}