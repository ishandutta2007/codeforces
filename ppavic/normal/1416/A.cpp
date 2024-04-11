#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

vector < int > v[N];
int n, A[N], ans[N];

void solve(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		v[A[i]].PB(i);
	}
	for(int i = 0;i <= n;i++)
		ans[i] = INF;
	for(int i = n;i >= 1;i--){
		if((int)v[i].size() == 0) continue;
		int cur = max(v[i][0], n - v[i].back() - 1);
		for(int j = 0;j + 1 < (int)v[i].size();j++)
			cur = max(cur, v[i][j + 1] - v[i][j] - 1);
		//printf("i = %d cur = %d\n", i, cur);
		ans[cur + 1] = i;
	}
	for(int i = 1;i <= n;i++){
		ans[i] = min(ans[i], ans[i - 1]);
		if(ans[i] == INF)
			printf("-1 ");
		else
			printf("%d ", ans[i]);
	}
	printf("\n");
	for(int i = 1;i <= n;i++){
		v[i].clear();
	}
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}