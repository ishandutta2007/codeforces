#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define st first
#define nd second
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

int n;
int L[310];
int C[310];
int res;
vector<int> primes[310];
map<int, int> ID;
map<int, int> cost;
vector<PII> prop;

int main(){
	res = 1000*1000*1000;

	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &L[i]);
	FWD(i,0,n) scanf("%d", &C[i]);

	FWD(i,0,n){
		int x = L[i];
		for(int p = 2; p*p <= x; ++p)
			if(x % p == 0){
				do{
					x /= p;
				}while(x % p == 0);
				primes[i].push_back(p);
			}
		if(x > 1)
			primes[i].push_back(x);
		//printf("%d: ", L[i]);
		//for(int p : primes[i]) printf("%d ", p);
		//printf("\n");
	}

	FWD(i,0,n){
		ID.clear();
		FWD(j,0,(int)primes[i].size())
			ID[primes[i][j]] = j;
		cost.clear();
		cost[(1<<primes[i].size())-1] = C[i];
		//printf("disposing %d\n", L[i]);
		FWD(j,0,n){
			int mask = 0;
			for(int p : primes[j])
				if(ID.find(p) != ID.end())
					mask |= (1 << ID[p]);
			//printf("%d mask %d\n", L[j], mask);
			prop.clear();
			for(const auto &kv : cost){
				//printf("%d : %d\n", kv.st, kv.nd, C[j]);
				//printf("%d : %d\n", (kv.st&mask), kv.nd + C[j]);
				prop.push_back(PII(kv.st&mask, kv.nd+C[j]));
			}
			for(const PII &kv : prop)
				if(cost.find(kv.st) == cost.end())
					cost[kv.st] = kv.nd;
				else
					cost[kv.st] = min(cost[kv.st], kv.nd);
		}
		if(cost.find(0) != cost.end())
			res = min(res, cost[0]);
	}

	if(res == 1000*1000*1000)
		res = -1;
	printf("%d\n", res);
	return 0;
}