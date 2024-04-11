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
typedef tuple<int, int, int> III;

const int mod = 1000000007;
const int INF = 1000000000;

int n;
int P[2010];
int H[2010];

void dfs(int i){
	if(P[i] == -1){
		H[i] = 1;
		return;
	}
	if(!H[P[i]]) dfs(P[i]);
	H[i] = H[P[i]] + 1;
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1) scanf("%d", &P[i]);
	FWD(i,1,n+1) if(!H[i]) dfs(i);
	printf("%d\n", *max_element(H+1, H+n+1));
	return 0;
}