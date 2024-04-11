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

int n, q;

int cnt = 0, A[N];

int main(){
	scanf("%d%d", &n, &q);	
	for(int i = 0;i < n;i++)
		scanf("%d", A + i), cnt += A[i];
	for(int i = 0;i < q;i++){
		int ty; scanf("%d", &ty);
		if(ty == 1){
			int ind; scanf("%d", &ind);
			if(A[ind - 1]) cnt--;
			else cnt++;
			A[ind - 1] = !A[ind - 1];
		}
		else{
			int k; scanf("%d", &k);
			printf("%d\n", (cnt >= k));
		}
	}
		
	return 0;
}