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

int n, m, k;
int C[5010];
LL S[5010];
LL R[5010][5010];
LL res;

int main(){
	scanf("%d %d %d", &n, &m, &k);
	FWD(i,0,n){
		scanf("%d", &C[i]);
		S[i+1] = S[i] + C[i];
	}
	FWD(i,0,n){
		FWD(j,1,k+1){
			R[i][j] = max(i?R[i-1][j]:0, (i>=m ? R[i-m][j-1] : 0) + (i+1>=m ? S[i+1] - S[i+1-m] : 0));
			res = max(res, R[i][j]);
		}
	}
	cout << res << endl;
	return 0;
}