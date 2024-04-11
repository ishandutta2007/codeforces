#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < int, int > pt;
typedef vector < int > vi;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << LOG);

inline int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) {if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int n;
char s[N], A[N], B[N];

void solve(){
	scanf("%d", &n);
	scanf("%s", s);
	int n0 = 0;
	for(int i = 0;i < n;i++)
		n0 += s[i] == '0';
	if(n0 & 1){
		printf("NO\n");
		return;
	}
	int otv = (n - n0) / 2, lst = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == '1' && otv){
			A[i] = '('; B[i] = '(';
			otv--;
		}
		else if(s[i] == '1'){
			A[i] = ')', B[i] = ')';
		}
		else if(lst){
			A[i] = '(', B[i] = ')';
			lst = !lst;
		}
		else{
			A[i] = ')', B[i] = '(';
			lst = !lst;
		}
	}
	int curA = 0, curB = 0;
	for(int i = 0;i < n;i++){
		curA += (A[i] == '(' ? 1 : -1);
		curB += (B[i] == '(' ? 1 : -1);
		if(curA < 0 || curB < 0){
			printf("NO\n");
			return;
		}
	}
	if(curA != 0 || curB != 0){
		printf("NO\n");
		return;	
	}
	printf("YES\n");
	for(int i = 0;i < n;i++)
		printf("%c", A[i]);
	printf("\n");
	for(int i = 0;i < n;i++)
		printf("%c", B[i]);
	printf("\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}