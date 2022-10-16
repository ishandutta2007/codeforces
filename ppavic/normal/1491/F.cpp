#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

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
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int p[N], n;

int pitaj(vi L, vi R){
	printf("? %d %d\n", (int)L.size(), (int)R.size());
	for(int x : L) printf("%d ", p[x] + 1); 
	printf("\n");
	for(int x : R) printf("%d ", p[x] + 1);
	printf("\n");
	fflush(stdout); int ret; scanf("%d", &ret);
	return ret;
}

void solve(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++) p[i] = i;
	random_shuffle(p, p + n);
	vi cur, sol; cur.PB(0); sol.PB(0);
	int bit = 0;
	for(int i = 1;i < n;i++){
		if(pitaj(cur, (vi){i})){
			bit = i;
			for(int j = i + 1;j < n;j++)
				if(!pitaj((vi){i}, (vi){j}))
					sol.PB(j);
			break;
		}
		sol.PB(i);
		cur.PB(i);
	}
	int pos = 0;
	for(int k = 12;k >= 0;k--){
		if(pos + (1 << k) >= (int)cur.size()) continue;
		pos += (1 << k);
		vi tmp = cur; 
		tmp.erase(tmp.begin() + pos, tmp.end());
		if(pitaj(tmp, (vi){bit}))
			pos -= (1 << k);
	}
	int nije = cur[pos];
	for(int i = 0;i < (int)sol.size();i++){
		if(sol[i] == nije){
			sol.erase(sol.begin() + nije);
		}
	}
	printf("! %d ", (int)sol.size());
	for(int x : sol) printf("%d ", p[x] + 1);
	printf("\n"); fflush(stdout);
}

int main(){
	srand(time(NULL));
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}