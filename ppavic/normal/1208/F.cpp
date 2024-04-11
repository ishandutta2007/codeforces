#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;
typedef vector < ll > vl;
typedef pair < ll, ll > pll;

const int N = (1 << 21) + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BS = 31337;

pii dp[N];
int a[N], n;

pii mrg(pii A,pii B){
	if(B.Y == -1) return A;
	if(A.Y == -1) return B;
	if(A.X > B.Y) return A;
	if(B.X > A.Y) return B;
	return {min(A.Y, B.Y), max(A.Y, B.Y)};
}

int odg(int x,int ii){
	int tr = 0;
	for(int i = 20;i >= 0;i--){
		if(x & (1 << i)) continue;
		//printf("indeks %d je %d\n", tr ^ (1 << i), dp[tr ^ (1 << i)].X);
		if(dp[tr ^ (1 << i)].X > ii) 
			tr ^= (1 << i);
	}
	//printf("%d i %d\n", x, tr);
	return x ^ tr;
}

int main(){
	for(int i = 0;i < N;i++) dp[i] = {-1, -1};
	scanf("%d", &n);
	for(int i =  0;i < n;i++){
		scanf("%d", a + i);
		dp[a[i]] = mrg(dp[a[i]], {-1, i});
		//printf("dp %d %d\n", dp[a[i]].X, dp[a[i]].Y);
	}
	for(int i = 0;i < 21;i++){
		for(int mask = (1 << 21) - 1; mask >= 0; mask--){
			if(!(mask & (1 << i)))
				dp[mask] = mrg(dp[mask], dp[mask ^ (1 << i)]);
		}
	}
	//printf("dp %d %d\n", dp[4].X, dp[4].Y);
	int ans = 0;
	for(int i = n - 1;i >= 0;i--)
		ans = max(ans, odg(a[i], i));
	printf("%d\n", ans);
	return 0;
}