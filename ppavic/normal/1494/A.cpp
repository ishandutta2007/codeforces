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

const int N = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

char s[N];
int n;

void solve(){
	scanf("%s", s); n = strlen(s);
	for(int a = -1;a <= 1;a += 2){
		for(int b = -1;b <= 1;b += 2){
			for(int c = -1;c <= 1;c += 2){
				bool dob = true; int cur = 0;
				for(int i = 0;i < n;i++){
					if(s[i] == 'A') cur += a;
					if(s[i] == 'B') cur += b;
					if(s[i] == 'C') cur += c;
					if(cur < 0) dob = false;
				}
				if(cur != 0) dob = false;
				if(dob){
					printf("yes\n"); return;
				}
			}
		}
	}
	printf("no\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}