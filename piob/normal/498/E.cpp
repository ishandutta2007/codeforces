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

const int mod = 1000000007;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;

bool mset(int mask, int i){
	return mask&(1<<i);
}

bool sparse(int k, int left, int horizontal, int right){
	FWD(i,0,k)
		if(mset(left, i) && mset(right, i) && mset(horizontal, i) && mset(horizontal, i+1))
			return 0;
	return 1;
}

int ways(int k, int left, int right){
	int c = 0;
	FWD(horizontal, 0, (1<<(k-1)))
		if(sparse(k, left, 2*horizontal+1+(1<<k), right))
			++c;
	return c;
}

int dp[133];
int tmp[133];

int size;
int matrix[7][128][128];

void diag(int a, int s=1){
	FWD(i,0,size) FWD(j,0,size) matrix[a][i][j] = (i==j?s:0);
}

void mov(int a, int b){
	FWD(i,0,size) FWD(j,0,size) matrix[b][i][j] = matrix[a][i][j];
}

void mul(int a, int b, int c){
	diag(c, 0);
	FWD(i,0,size)
		FWD(k,0,size)
			FWD(j,0,size)
				matrix[c][i][j] = (matrix[c][i][j] + (LL)matrix[a][i][k] * matrix[b][k][j]) % mod;
}

void pow(int k){
	diag(1);
	while(k){
		if(k&1){
			mul(0, 1, 2);
			mov(2, 1);
		}
		mul(0, 0, 2);
		mov(2, 0);
		k /= 2;
	}
}

void process(int k, int w){
	size = (1<<k);
	//printf("processing: k: %d w: %d space size: %d\n", k, w, size);
	//printf("input:\n");
	//FWD(i,0,size/2) printf("%d ", dp[i]); printf("\n");
	FWD(i,0,size/2){
		dp[i+size/2] = dp[i];
		dp[i] = 0;
	}
	FWD(i,0,size) FWD(j,0,size) matrix[0][i][j] = ways(k, i, j);
	/*printf("trans:\n");
	FWD(i,0,size){
		FWD(j,0,size) printf("%d ", matrix[0][i][j]);
		printf("\n");
	}*/
	pow(w);
	FWD(i,0,size) tmp[i] = 0;
	FWD(i,0,size)
		FWD(j,0,size)
			tmp[j] = (tmp[j] + (LL)dp[i] * matrix[1][i][j]) % mod;
	FWD(i,0,size) dp[i] = tmp[i];
	//printf("output:\n");
	//FWD(i,0,size) printf("%d ", dp[i]); printf("\n");
}

int main(){
	dp[0] = 1;
	FWD(k,1,8){
		int w;
		scanf("%d", &w);
		process(k, w);
	}
	printf("%d\n", dp[127]);
	return 0;
}