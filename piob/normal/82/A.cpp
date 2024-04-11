#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <limits>
#define FWD(a,b,c) for(int a=(b); a<(c); a++)
#define BCK(a,b,c) for(int a=(b); a>(c); a--)
#define FE(a,b) for(typeof(b.end()) a=b.begin(); a!=b.end(); a++)
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) erase(unique(a.begin(), a.end()), a.end())
#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define PDD pair<double, double>
#define x first
#define y second
#define PACKS(a) int a; scanf("%d", &a); a++; while(--a)

//#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug
#endif

using namespace std;

int T[40];

int main(){
	T[0] = 5;
	FWD(i,1,40) T[i] = T[i-1] * 2;
	int n, d;
	scanf("%d", &n);
	d = 0;
	--n;
	while(T[d] <= n){
		n -= T[d];
		++d;
	}
	n /= T[d]/5;
	switch(n){
		case 0:
			printf("Sheldon\n");
			break;
		case 1:
			printf("Leonard\n");
			break;
		case 2:
			printf("Penny\n");
			break;
		case 3:
			printf("Rajesh\n");
			break;
		case 4:
			printf("Howard\n");
			break;
	}
	return 0;
}