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

const int INF = 1000000010;

int n, m;
int dp[2010][2010];	// dp[i][j] = minimal cost of getting j matches on S[i...n-1]
int cost[2010];
char S[2010];
char P[510];

int main(){
	scanf("%s%s", S, P);
	n = strlen(S);
	m = strlen(P);
	FWD(i,0,n){
		cost[i] = INF;
		int j = i;
		int p = 0;
		while(p < m && j < n){
			if(S[j] == P[p]) ++p;
			++j;
		}
		if(p == m) cost[i] = j-i;
	}
	FWD(i,0,n+1) FWD(j,0,n+1) dp[i][j] = (j == 0 ? 0 : INF);
	BCK(i,n-1,-1){
		FWD(j,0,n+1){
			dp[i][j] = dp[i+1][j];
			if(j && cost[i] < INF)
				dp[i][j] = min(dp[i][j], dp[i+cost[i]][j-1]+cost[i]-m);
		}
	}
	FWD(i,0,n+1){
		int r = 0;
		while(r < n && dp[0][r+1] <= i) ++r;
		while(r*m+i > n) --r;
		printf("%d%c", r, "\n "[i<n]);
	}
	return 0;
}