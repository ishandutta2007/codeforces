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

pair<vector<int>, int> W[210];
vector<int> S;

int main(){
	int n, m, a;
	scanf("%d", &n);
	if(n == 2){
		scanf("%d", &m);
		printf("%d ", m/2);
		FWD(i,0,m/2){
			scanf("%d", &a);
			printf("%d ", a);
		}
		printf("\n%d ", m-m/2);
		FWD(i,0,m-m/2){
			scanf("%d", &a);
			printf("%d ", a);
		}
		printf("\n");
		return 0;
	}
	n = n * (n-1) / 2;
	FWD(i,0,202) W[i].y = i;
	FWD(i,0,n){
		scanf("%d", &m);
		FWD(j,0,m){
			scanf("%d", &a);
			W[a].x.push_back(i);
		}
	}
	sort(W, W+202);
	n = 0;
	while(W[n].x.empty())	++n;
	++n;
	S.push_back(1);
	FWD(i,n,202){
		if(W[i].x != W[i-1].x){
			S.push_back(1);
		}else{
			++S.back();
		}
	}
	m = 1;
	printf("%d %d ", S[0], W[n-1].y);
	FWD(i,n,202){
		if(W[i].x != W[i-1].x){
			printf("\n%d %d ", S[m], W[i].y);
			++m;
		}else{
			printf("%d ", W[i].y);
		}
	}
	printf("\n");
	return 0;
}