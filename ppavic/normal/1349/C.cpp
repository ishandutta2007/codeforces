#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1005;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);

const int px[4] = {0, 0, 1, -1};
const int py[4] = {-1, 1, 0, 0};

int dis[N][N], boja[N][N];
int n, m, A[N][N];

queue < int > qX, qY;

void bfs(){
	while(!qX.empty()){
		int x = qX.front(), y = qY.front();
		qX.pop(), qY.pop();
		for(int k = 0;k < 4;k++){
			int xx = px[k] + x, yy = py[k] + y;
			if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if(dis[xx][yy] != -1) continue;
			dis[xx][yy] = dis[x][y] + 1;
			boja[xx][yy] = !boja[x][y];
			qX.push(xx), qY.push(yy);
		}
	}
}

int main(){
	int q; scanf("%d%d%d", &n, &m, &q);
	memset(dis, -1, sizeof(dis));	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c; scanf(" %c", &c);
			A[i][j] = c - '0';
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			int ima = 0;
			for(int k = 0;k < 4;k++){
				int ii = px[k] + i, jj = py[k] + j;
				if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
				if(A[ii][jj] == A[i][j]) ima = 1;
			}
			if(ima){
				dis[i][j] = 0; boja[i][j] = A[i][j];
				qX.push(i), qY.push(j);
			}			
		}
	}
	bfs();
	for(int i = 0;i < q;i++){
		ll k; int x, y; 
		scanf("%d%d%lld", &x, &y, &k); x--, y--;
		if(dis[x][y] == -1 || dis[x][y] > k){
			printf("%d\n", A[x][y]);
		}
		else{
			printf("%lld\n", boja[x][y] ^ ((k - dis[x][y])&1LL));
		}
	}
	return 0;
}