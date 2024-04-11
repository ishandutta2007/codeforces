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

int n, k, r;
int T[2010];

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n) scanf("%d", &T[i]);
	sort(T, T+n);
	int i = n-1;
	while(i >= 0){
		r += (T[i]-1)*2;
		i -= k;
	}
	printf("%d\n", r);
	return 0;
}