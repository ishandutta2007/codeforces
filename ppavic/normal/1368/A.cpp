#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);

int T;
ll A, B, n;

int main(){
	scanf("%d", &T);
	for(;T--;){
		scanf("%lld%lld%lld", &A, &B, &n);
		int sol = 0;
		if(A > B){
			swap(A, B);
		}
		while(A <= n && B <= n){
			A += B;
			if(A > B){
				swap(A, B);
			}
			sol++;
		}
		printf("%d\n", sol);	
	}
	return 0;
}