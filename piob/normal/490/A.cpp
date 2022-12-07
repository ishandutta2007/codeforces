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

int n, a;
queue<int> E[3];

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d", &a);
		E[a-1].push(i);
	}
	n = min(E[0].size(), min(E[1].size(), E[2].size()));
	printf("%d\n", n);
	FWD(i,0,n){
		printf("%d %d %d\n", E[0].front()+1, E[1].front()+1, E[2].front()+1);
		E[0].pop();
		E[1].pop();
		E[2].pop();
	}
	return 0;
}