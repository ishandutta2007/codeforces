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

int n;
int T[1010];
int W[1010][1010];
int M[1010][1010];
vector<int> G;

int main(){
	scanf("%d", &n);
	FWD(i,0,n)
		scanf("%d", &T[i]);
	
		FWD(j,0,n)
			W[j][n] = T[j];
	
		FWD(j,0,n-1)
			W[j][n-1] = max(T[j], T[n-1]);
			
	BCK(k,n-2,0){
		FWD(j,0,k){
			W[j][k] = min(	W[k+1][k+2] + max(T[j], T[k]),
					  min(	W[k][k+2] + max(T[j], T[k+1]),
					  		W[j][k+2] + max(T[k], T[k+1])
					  		));
			if(W[j][k] == W[k+1][k+2] + max(T[j], T[k])) M[j][k] = 0;
			if(W[j][k] == W[k][k+2] + max(T[j], T[k+1])) M[j][k] = 1;
			if(W[j][k] == W[j][k+2] + max(T[k], T[k+1])) M[j][k] = 2;
			}
	}
	printf("%d\n", W[0][1]);
	int a = 0;
	int b = 1;
	while(1){
		if(b == n){
			printf("%d\n", a+1);
			break;
		}
		if(b == n-1){
			printf("%d %d\n", a+1, b+1);
			break;
		}
		switch(M[a][b]){
			case 0:
				printf("%d %d\n", a+1, b+1);
				a = b+1;
				b = b+2;
				break;
			case 1:
				printf("%d %d\n", a+1, b+1+1);
				a = b;
				b = b+2;
				break;
			case 2:
				printf("%d %d\n", b+1, b+1+1);
				b = b+2;
				break;
		}
	}
	return 0;
}