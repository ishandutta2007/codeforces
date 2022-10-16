#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < ld, ld > pt;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int n;

ld dis(pt A, pt B){
	return sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}

vector < pt > Dp, Dm, M, D;

void solve(){
	scanf("%d", &n);
	for(int i = 0;i < 2 * n;i++){
		int x, y; scanf("%d%d", &x, &y);
		pt tmp = {abs(x), abs(y)};
		if(!y)
			D.PB(tmp);
		else
			M.PB(tmp);
	}
	sort(M.begin(), M.end());
	sort(D.begin(), D.end());
	ld sol1 = 0, sol2 = 0;
	for(int i = 0;i < n;i++){
		sol1 += dis(M[i], D[i]);
		sol2 += dis(M[i], D[n - i - 1]);
	}
	printf("%.10Lf\n", min(sol1, sol2));
	M.clear(); D.clear();
	return;
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();

	return 0;
}