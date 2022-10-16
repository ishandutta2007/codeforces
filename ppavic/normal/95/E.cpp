#include <cstdio>
#include <cstring>
#include <vector>
#include <cstring>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef pair < int, int > pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;

int vel[N], par[N], n, m, kol[N], dp[N];
vector < pii > pot;

bool sretan(int x){
	for(; x ; x /= 10)
		if(x % 10 != 4 && x % 10 != 7)
			return false;
	return true;
}

int pr(int x){
	if(par[x] == x) return par[x];
	return par[x] = pr(par[x]);
}

int main(){
	memset(dp, INF, sizeof(dp));
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		par[i] = i;
	for(int i = 0;i < m;i++){
		int a, b; scanf("%d%d", &a, &b);
		par[pr(a)] = pr(b);
	}
	for(int i = 1;i <= n;i++)
		vel[pr(i)]++;
	for(int i = 1;i <= n;i++)
		if(vel[i])
			kol[vel[i]]++;
	for(int i = 1;i <= n;i++){
		int cur = kol[i];
		for(int j = 1;j <= cur; cur -= j, j *= 2){
			pot.PB({j * i, j});
		}
		if(cur)
			pot.PB({cur * i, cur});
	}
	dp[0] = 0;
	for(pii cur : pot){
		for(int j = n;j >= cur.X;j--)
			dp[j] = min(dp[j], dp[j - cur.X] + cur.Y);
	}
	int ans = INF;
	for(int i = 1;i <= n;i++)
		if(sretan(i))
			ans = min(ans, dp[i]);
	printf("%d\n", ans % INF - 1);
	return 0;
}