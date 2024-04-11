#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
 
#define X first
#define Y second
#define PB push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
 
const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
 
int n, A[N], sm, tme, t1[N], t2[N], t3[N];
 
inline void potez(int i, int j, int x){
	t1[tme] = i, t2[tme] = j, t3[tme] = x;
	A[i] -= i * x; A[j] += i * x;
	tme++;
}
 
void solve(){
	scanf("%d", &n);
	sm = 0; tme = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", A + i); sm += A[i];
	}
	if((sm % n) != 0){
		printf("-1\n");
		return;
	}
	int trb = sm / n;
	for(int i = 2;i <= n;i++){
		potez(1, i, (i - A[i] % i) % i);
		potez(i, 1, A[i] / i);
	}
	for(int i = 2;i <= n;i++){
		potez(1, i, trb);
	}
	printf("%d\n", tme);
	for(int i = 0;i < tme;i++)
		printf("%d %d %d\n", t1[i], t2[i], t3[i]);
}
 
int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}