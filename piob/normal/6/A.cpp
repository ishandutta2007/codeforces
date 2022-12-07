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

int main(){
	int T[4];
	FWD(i,0,4) scanf("%d", &T[i]);	
	sort(T, T+4);
	if(T[0]+T[1] > T[2]){
		printf("TRIANGLE\n");
		return 0;
	}
	if(T[1]+T[2] > T[3]){
		printf("TRIANGLE\n");
		return 0;
	}
	if(T[0]+T[1] == T[2]){
		printf("SEGMENT\n");
		return 0;
	}
	if(T[1]+T[2] == T[3]){
		printf("SEGMENT\n");
		return 0;
	}
	printf("IMPOSSIBLE\n");
	return 0;
}