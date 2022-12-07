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

int n, k;
vector<PII> V;
vector<int> R;

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,1,n+1){
		int a;
		scanf("%d", &a);
		V.push_back(PII(a, i));
	}
	sort(V.begin(), V.end());
	int i = 0;
	while(i < (int)V.size() && V[i].x <= k){
		k -= V[i].x;
		R.push_back(V[i].y);
		++i;
	}
	printf("%d\n", (int)R.size());
	for(int r : R) printf("%d\n", r);
	return 0;
}