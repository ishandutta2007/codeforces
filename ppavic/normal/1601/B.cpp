#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

set < int > S;
queue < int > Q;
int dis[N], rek[N], zap[N];
int A[N], B[N], n;

int main(){
	memset(dis, -1, sizeof(dis));
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", A + i);
	for(int i = 1;i <= n;i++) scanf("%d", B + i);
	for(int i = 0;i <= n;i++) S.insert(i);
	Q.push(n); dis[n] = 0;
	
	for(;!Q.empty();Q.pop()){
		int cur = Q.front();
		while(S.lower_bound(cur - A[cur]) != S.end() && *S.lower_bound(cur - A[cur]) <= cur){
			int nxt = *S.lower_bound(cur - A[cur]); S.erase(nxt);
			if(dis[nxt + B[nxt]] == -1){
				dis[nxt + B[nxt]] = dis[cur] + 1;
				rek[nxt + B[nxt]] = cur;
				zap[nxt + B[nxt]] = nxt;
				Q.push(nxt + B[nxt]);
			}	
		}
	}
	printf("%d\n", dis[0]);
	if(dis[0] == -1) return 0;
	int st = 0;
	vector < int > fin;
	for(;st < n;){
		fin.PB(zap[st]);
		st = rek[st];
	}
	reverse(fin.begin(), fin.end());
	for(int x : fin) printf("%d ", x);
	printf("\n");
	return 0;
}