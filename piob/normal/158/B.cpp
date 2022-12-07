#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PACKS(a) int a;scanf("%d",&a);++a;while(--a)
#define PLL pair<long long, long long>
#define x first
#define y second

using namespace std;

int n, a, b;
int S[5];

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d", &a);
		++S[a];
	}
	a = 0;
	a += S[4];
	b = min(S[3], S[1]);
	a += b;
	S[3] -= b;
	S[1] -= b;
	a += S[3];
	b = S[2]/2;
	a += b;
	S[2] -= 2*b;
	if(S[2]){
		++a;
		S[1] -= min(2, S[1]);
	}
	a += (S[1] + 3)/4;
	printf("%d\n", a);
	return 0;
}