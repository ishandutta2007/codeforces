#include <cstdio>
#include <set>
#include <vector>
#include <cstring>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef pair < int, int > pii;
typedef pair < int, pii > pip;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int K = 51;

set < pip > S;
vector < pii > v[N];
int n, m, dis[N][K];

int main(){
	memset(dis, INF, sizeof(dis));
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		v[x].PB({w, y}), v[y].PB({w,x });
	}
	dis[1][0] = 0;
	S.insert({0, {1, 0}});
	for(;!S.empty();){
		int cur = S.begin() -> Y.X, rnk = S.begin() -> Y.Y;
		S.erase(S.begin());
		if(rnk){
			for(pii nxt : v[cur]){
				if(dis[nxt.Y][0] > dis[cur][rnk] + (nxt.X + rnk) * (nxt.X + rnk)){
					dis[nxt.Y][0] = dis[cur][rnk] + (nxt.X + rnk) * (nxt.X + rnk);
					S.insert({dis[nxt.Y][0], {nxt.Y, 0}});
				}	
			}
		}
		else{
			for(pii nxt : v[cur]){
				if(dis[nxt.Y][nxt.X] > dis[cur][0]){
					dis[nxt.Y][nxt.X] = dis[cur][0];
					S.insert({dis[nxt.Y][nxt.X], {nxt.Y, nxt.X}});
				}	
			}
		}
	}
	for(int i = 1;i <= n;i++)
		printf("%d ", dis[i][0] != INF ? dis[i][0] : -1);
	printf("\n");
	return 0;
}