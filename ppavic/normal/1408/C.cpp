#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pii pt;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);

int A[N][2], n, L;

ld time(ld pos, int k){
	ld res = 0, brz = 1, lst = 0;
	for(int i = 0;i < n;i++){
		if(A[i][k] > pos){
			res += (ld)(pos - lst) / brz;
			return res;
		}
		else{
			res += (ld)(A[i][k] - lst) / brz;
			lst = A[i][k]; brz += 1.0;
		}
		
	}
	res += (pos - lst) / brz;
	return res;
}

void solve(){
	scanf("%d%d", &n, &L);
	for(int i = 0;i < n;i++){
		scanf("%d", &A[i][0]);
		A[n - i - 1][1] = L - A[i][0];
	} 
	ld lo = 0, hi = L;
	for(int i = 0;i < 60;i++){
		ld mid = (lo + hi) / 2;
		ld t1 = time(mid, 0), t2 = time((ld)L - mid, 1);
		if(t1 < t2)
			lo = mid;
		else
			hi = mid;
	}
	printf("%.15Lf\n", time(lo, 0));
}


int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}