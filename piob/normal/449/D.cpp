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
int dp[(1<<20)+3];
LL w;
LL P2[(1<<20)+3];

int main(){
	P2[0] = 1;
	FWD(i,1,(1<<20))
		P2[i] = P2[i-1]*2 % mod;
	scanf("%d", &n);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		++dp[a];
	}
	FWD(r,0,20){
		FWD(i,0,(1<<20))
			if((i&(1<<r))==0)
				dp[i] += dp[i|(1<<r)];
	}
	FWD(i,0,(1<<20)){
		if(__builtin_popcount(i)&1){
			w = (w - P2[dp[i]] + mod) % mod;
		}else{
			w = (w + P2[dp[i]]) % mod;
		}
	}
	printf("%d\n", (int)w);
	return 0;
}