#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int sub(int A, int B){
	if(A - B < 0)
		return A - B + MOD;
	return A - B;
}

int sve = 0, n;
ll off = 0;
map < ll , int > dp;

void solve(){
	dp.clear(); off = 0;
	dp[0] = 1; sve = 1;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		sve = sub(sve, dp[-off]);
		dp[-off] = add(dp[-off], sve);
		sve = add(sve, dp[-off]);
		off += x; 
	}
	printf("%d\n", sve);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}