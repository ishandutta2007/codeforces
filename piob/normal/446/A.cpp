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

int n, r;
int T[100010];
int P[100010];
int S[100010];

int main(){
	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &T[i]);
	P[0] = 1;
	FWD(i,1,n) if(T[i-1] < T[i]) P[i] = P[i-1]+1; else P[i] = 1;
	S[n-1] = 1;
	BCK(i,n-2,-1) if(T[i+1] > T[i]) S[i] = S[i+1]+1; else S[i] = 1;
	r = max(1, max(P[n-1], S[0]));
	FWD(i,1,n-1)
		if(T[i-1]+2 <= T[i+1])
			r = max(r, P[i-1]+1+S[i+1]);
	FWD(i,0,n-1) r = max(r, P[i]+1);
	FWD(i,1,n) r = max(r, S[i]+1);
	printf("%d\n", r);
	return 0;
}