#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

const int N = 1e5 + 500;

int deg[N], n, P[N], bio[N];
vector < int > v[N], ost;
queue < int > Q;

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
		deg[x]++, deg[y]++;
		P[i] = i;
	}
	P[n] = n;
	for(int i = 1;i <= n;i++){
		if(deg[i] == 1)
			Q.push(i);
	}
	int sol = 0;
	for(int i = 0;i + 1 < n;i++){
		int cur = Q.front(); Q.pop();
		int nxt = 0;
		for(int tmp : v[cur]){
			if(deg[tmp]) nxt = tmp;
		}
		deg[nxt]--; deg[cur]--;
		if(P[cur] == cur || (!deg[nxt] && P[nxt] == nxt)){
			sol += 2; swap(P[cur], P[nxt]);
		}
		if(deg[nxt] == 1)
			Q.push(nxt);
	}
	printf("%d\n", sol);
	for(int i = 1;i <= n;i++)
		printf("%d ", P[i]);
	printf("\n");
}