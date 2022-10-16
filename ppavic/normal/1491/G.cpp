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
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int n, p[N], bio[N];
vector < pii > parovi, sol;
vector < vi > svi;

void rijesi1(vi &A){
	if((int)A.size() == 2){
		int x = 1;
		while(A[0] == x || A[1] == x) x++;
		sol.PB({A[0], x});
		sol.PB({A[1], x});
		sol.PB({A[0], x});
		return;
	}
	sol.PB({A[0], A.back()});
	sol.PB({A[0], A[1]});
	sol.PB({A[1], A.back()});
	for(int x : A)
		if(x != A[1] && x != A[0])
			sol.PB({x, A[0]});
}

void rijesi2(vi &A, vi &B){
	sol.PB({A[0], B[0]});
	for(int x : A)
		if(x != A[0])
			sol.PB({B[0], x});
	for(int x : B)
		if(x != B[0])
			sol.PB({A[0], x});
	sol.PB({A[0], B[0]});
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", p + i);
	for(int i = 1;i <= n;i++){
		if(bio[i]) continue;
		int cur = p[i];
		vi cik;
		while(!bio[cur]){
			cik.PB(cur); 
			bio[cur] = 1;
			cur = p[cur];
		}
		if((int)cik.size() == 1) continue;
		svi.PB(cik);
	}
	for(int i = 0;i + 1 < (int)svi.size();i += 2)
		rijesi2(svi[i], svi[i + 1]);
	if((int)svi.size() & 1)
		rijesi1(svi.back());
	printf("%d\n", (int)sol.size());
	for(pii tmp : sol){
		printf("%d %d\n", tmp.X, tmp.Y);
		swap(p[tmp.X], p[tmp.Y]);
		p[tmp.X] *= -1; p[tmp.Y] *= -1;
	}
	return 0;
	for(int i = 1;i <= n;i++)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}