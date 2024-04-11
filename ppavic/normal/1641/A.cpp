#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << 20);


multiset < int > S;
int n, k;

void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		S.insert(x);
	}
	int sol = 0;
	for(;(int)S.size() > 0;){
		int x = *S.begin(); S.erase(S.begin());
		if((ll)x * k < (ll)1e9 && S.find(x * k) != S.end())
			S.erase(S.lower_bound(x * k));
		else
			sol++;
	}
	printf("%d\n", sol);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}