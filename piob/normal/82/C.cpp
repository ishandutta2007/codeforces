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

int n, a, b, c;
int P[5010];
priority_queue<PII> C[5010];
int S[5010];
int par[5010];	//parent
int cap[5010];	//capacity
vector<PII> E[5010];
int T[5010];
bool change;
int K[5010];

void dfs(int u){
	K[a++] = u;
	FE(v,E[u]){
		if(par[v->x] == 0){
			par[v->x] = u;
			cap[v->x] = v->y;
			dfs(v->x);
		}
	}
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1){
		scanf("%d", &P[i]);
		P[i] = -P[i];
		C[i].push(PII(P[i], i));
	}
	FWD(i,1,n){
		scanf("%d %d %d", &a, &b, &c);
		E[a].push_back(PII(b,c));
		E[b].push_back(PII(a,c));
	}
	a = 0;
	par[1] = -1;
	dfs(1);
	a = 0;
	do{
		change = 0;
		while(!C[1].empty()){
			T[C[1].top().y] = a;
			C[1].pop();
		}
		++a;
		FWD(i,2,n+1)
			S[i] = min((int)C[i].size(), cap[i]);
		FWD(i,1,n){
			b = K[i];
			FWD(i,0,S[b]){
				C[par[b]].push(C[b].top());
				C[b].pop();
				change = 1;
			}
		}
	}while(change);
	FWD(i,1,n+1)
		printf("%d ", T[i]);
	printf("\n");
	return 0;
}