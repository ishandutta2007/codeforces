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

const int mod = 1000000007;

int a, b;
int r;

int main(){
	scanf("%d %d", &a, &b);
	FWD(q,1,b){
//		r += (qb+q) + (2qb+q) + (3qb+q) + ... + (aqb+q);
		r = (r + (LL)a*q) % mod;
		r = (r + (LL)a*(a+1)/2%mod*q%mod*b%mod) % mod;
	}
	printf("%d\n", r);
	return 0;
}