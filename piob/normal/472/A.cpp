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

const int N = 1000010;

int n;
bool prime[1000010];

int main(){
	FWD(i,2,N) prime[i] = 1;
	for(int i=2; i*i < N; ++i)
		if(prime[i])
			for(int j=i*i; j<N; j+=i)
				prime[j] = 0;
	scanf("%d", &n);
	FWD(x,4,n)
		if(!prime[x] && !prime[n-x]){
			printf("%d %d\n", x, n-x);
			return 0;
		}
	return 0;
}