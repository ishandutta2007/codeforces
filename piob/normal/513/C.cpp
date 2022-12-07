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

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;


int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
int L[6];
int R[6];
K res;

K gexacly(int i, int x){
	if(x < L[i] || x > R[i]) return 0;
	return (K)1 / (R[i]-L[i]+1);
}

K gless(int i, int x){
	int r = min(R[i], x-1);
	if(r < L[i]) return 0;
	return (K)(r-L[i]+1) / (R[i]-L[i]+1);
}

K gmore(int i, int x){
	int l = max(L[i], x+1);
	if(R[i] < l) return 0;
	return (K)(R[i]-l+1) / (R[i]-L[i]+1);
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d %d", &L[i], &R[i]);
	}
	res = 0;
	FWD(cost,1,10001){ // TODO POPRAW!!!!!
		// liczymy prawdopodobienstwo zaplacenia cost
		FWD(mask,0,1<<n){	// ci wylosuja cost
			if(mask == 0) continue;
			//printf("\n");
			//printf("%d zdobeda: ", cost); FWD(i,0,n) if(mask&(1<<i)) printf("%d ", i); printf("\n");
			// ziomkowie z maski osiagna cost
			if(popcount(mask) == 1){
				// ktos musi miec wiecej
				FWD(i,0,n) if(!(mask&(1<<i))){
					//printf("wygra %d\n", i);
					K prob = 1;
					FWD(j,0,n){
						if(mask&(1<<j))
							prob *= gexacly(j, cost);
						else if(i == j)
							prob *= gmore(j, cost);
						else
							prob *= gless(j, cost);
					}
					//cout << prob << endl;
					res += prob*cost;
				}
			}else{
				//printf("reszta przegra\n");
				// inni musza przegrac
				K prob = 1;
				FWD(i,0,n) if(mask&(1<<i)){
					prob *= gexacly(i, cost);
				}else{
					prob *= gless(i, cost);
				}
				//cout << prob << endl;
				res += prob * cost;

				// ktos wygra wiecej
				FWD(i,0,n) if(!(mask&(1<<i))){
					//printf("wygra %d\n", i);
					prob = 1;
					FWD(j,0,n){
						if(mask&(1<<j))
							prob *= gexacly(j, cost);
						else if(i == j)
							prob *= gmore(j, cost);
						else
							prob *= gless(j, cost);
					}
					//cout << prob << endl;
					res += prob*cost;
				}
			}
		}
	}
	cout.precision(10);
	cout << fixed << res << endl;
	return 0;
}