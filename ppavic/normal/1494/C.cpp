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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

vector < int > A[2], B[2];
int n, m, dod[N];
map < int, int > ima;

void solve(){
	A[0].clear(); A[1].clear(); B[0].clear(); B[1].clear(); ima.clear();
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		if(x > 0) A[0].PB(x);
		else A[1].PB(-x);
	}
	for(int i = 0;i < m;i++){
		int x; scanf("%d", &x);
		if(x > 0) B[0].PB(x);
		else B[1].PB(-x);
	}
	reverse(A[1].begin(), A[1].end()); reverse(B[1].begin(), B[1].end());
	int sol = 0;
	for(int c = 0;c < 2;c++){
		ima.clear();
		for(int x : A[c]) ima[x] = 1;
		int j = 0, k = 0, cur = 0;
		dod[(int)B[c].size()] = 0;
		for(int i = (int)B[c].size() - 1;i >= 0;i--)
			dod[i] = dod[i + 1] + ima[B[c][i]];
		for(int i = 0;i < (int)B[c].size();i++){
			while(k < (int)A[c].size() && A[c][k] <= B[c][i] + k - 1) 
				k++;
			while(j < (int)B[c].size() && B[c][j] <= B[c][i] + k - 1)
				j++;
			if(j < i) j = i;
			cur = max(cur, j - i + dod[j]);
		}	
		sol += cur;
	}
	printf("%d\n", sol);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}